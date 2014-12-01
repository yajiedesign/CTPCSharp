
#include "stdafx.h"
#include "MdApi.h"
#include <string>


using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

namespace CTPCLR
{
	public ref class MdApiclr
	{
	private:

		System::Collections::Generic::List<GCHandle> ^ gchlist = gcnew 	System::Collections::Generic::List<GCHandle>();

		std::string MarshalString(String ^ s) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			std::string os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
			return os;
		}

		CMdSpi *pUserSpi = nullptr;
		CThostFtdcMdApi * pUserApi = nullptr;
		int lRequestID = 0;

	public:


		MdApiclr(System::String ^_investor, System::String ^_pwd, System::String ^_broker,
			System::String ^_addr, System::String ^_FlowPath)
		{
			FrontAddr = _addr;

			pUserSpi = new CMdSpi();
			// 初始化UserApi
			pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(MarshalString(_FlowPath).c_str());		// 创建UserApi

			EventInit();

			pUserApi->RegisterSpi(pUserSpi);						// 注册事件类
			pUserApi->RegisterFront((char*)MarshalString(FrontAddr).c_str());					// connect
			pUserApi->Init();
		}

		virtual ~MdApiclr(){

			for each (GCHandle var in gchlist)
			{
				var.Free();
			}
		}

		/// <summary>
		/// 前置地址
		/// </summary>
		property  System::String ^ FrontAddr;


		/// <summary>
		///订阅行情。
		/// </summary>
		int SubscribeMarketData(array<String^>^ ppInstrumentID, int nCount)
		{
			char** ppi = new char*[nCount];
			System::Collections::Generic::List<IntPtr> ^ ppIntPtrs = gcnew 	System::Collections::Generic::List<IntPtr>();
			try
			{
				for (int i = 0; i < nCount; i++)
				{
					IntPtr tp = Marshal::StringToHGlobalAnsi(ppInstrumentID[i]);
					ppIntPtrs->Add(tp);
					ppi[i] = static_cast<char*>(tp.ToPointer());
				}
				return pUserApi->SubscribeMarketData(ppi, nCount);
			}
			finally
			{
				for each (IntPtr var in ppIntPtrs)
				{
					Marshal::FreeHGlobal(var);
				}
			}
		}


		/// <summary>
		///退订行情。
		/// </summary>
		int UnSubscribeMarketData(array<String^>^ ppInstrumentID, int nCount)
		{
			char** ppi = new char*[nCount];
			System::Collections::Generic::List<IntPtr> ^ ppIntPtrs = gcnew 	System::Collections::Generic::List<IntPtr>();
			try
			{
				for (int i = 0; i < nCount; i++)
				{
					IntPtr tp = Marshal::StringToHGlobalAuto(ppInstrumentID[i]);
					ppIntPtrs->Add(tp);
					ppi[i] = static_cast<char*>(tp.ToPointer());
				}
				return pUserApi->UnSubscribeMarketData(ppi, nCount);
			}
			finally
			{
				for each (IntPtr var in ppIntPtrs)
				{
					Marshal::FreeHGlobal(var);
				}
			}
		}

		/// <summary>
		///用户登录请求
		/// </summary>
		int ReqUserLogin(CTPCommon::CThostFtdcReqUserLoginField pReqUserLoginField, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pReqUserLoginField);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pReqUserLoginField, bufferIntPtr, false);
				CThostFtdcReqUserLoginField* temp = static_cast<CThostFtdcReqUserLoginField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqUserLogin(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///登出请求
		/// </summary>
		int ReqUserLogout(CTPCommon::CThostFtdcUserLogoutField pUserLogout, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pUserLogout);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pUserLogout, bufferIntPtr, false);
				CThostFtdcUserLogoutField* temp = static_cast<CThostFtdcUserLogoutField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqUserLogout(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		void EventInit()
		{

			{
				cppFrontConnect^ fp = gcnew cppFrontConnect(this, &MdApiclr::cppcbFrontConnect);
				GCHandle gch = GCHandle::Alloc(fp);
				gchlist->Add(gch);
				IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
				CBOnFrontConnected cb = static_cast<CBOnFrontConnected>(ip.ToPointer());
				pUserSpi->cbOnFrontConnected = cb;
			}

		{
			cppDisConnected^ fp = gcnew cppDisConnected(this, &MdApiclr::cppcbDisConnected);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnFrontDisconnected cb = static_cast<CBOnFrontDisconnected>(ip.ToPointer());
			pUserSpi->cbOnFrontDisconnected = cb;
		}
		{
			cppRspUserLogin^ fp = gcnew cppRspUserLogin(this, &MdApiclr::cppcbRspUserLogin);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnRspUserLogin cb = static_cast<CBOnRspUserLogin>(ip.ToPointer());
			pUserSpi->cbOnRspUserLogin = cb;
		}
		{
			cppRspUserLogout^ fp = gcnew cppRspUserLogout(this, &MdApiclr::cppcbRspUserLogout);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnRspUserLogout cb = static_cast<CBOnRspUserLogout>(ip.ToPointer());
			pUserSpi->cbOnRspUserLogout = cb;
		}
		{
			cppOnRtnDepthMarketData^ fp = gcnew cppOnRtnDepthMarketData(this, &MdApiclr::cppcbRtnDepthMarketData);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnRtnDepthMarketData cb = static_cast<CBOnRtnDepthMarketData>(ip.ToPointer());
			pUserSpi->cbOnRtnDepthMarketData = cb;
		}

		}


	public:
		delegate void FrontConnect();
	private:
		delegate void cppFrontConnect();
		void cppcbFrontConnect()
		{

			OnFrontConnect();
		}
	public:
		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// </summary>
		event FrontConnect ^OnFrontConnect;


	public:
		delegate void DisConnected(int reason);
	private:
		delegate void cppDisConnected(int reason);
		void cppcbDisConnected(int reason)
		{

			OnDisConnected(reason);
		}
	public:
		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// </summary>
		event DisConnected ^OnDisConnected;



	public:
		delegate void RspUserLogin(CTPCommon::CThostFtdcRspUserLoginField pRspUserLogin, CTPCommon::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
	private:
		delegate void cppRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcRspUserLoginField  cspRspUserLogin = (CTPCommon::CThostFtdcRspUserLoginField) Marshal::PtrToStructure(IntPtr(pRspUserLogin), CTPCommon::CThostFtdcRspUserLoginField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspUserLogin(cspRspUserLogin, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 登录请求响应
		/// </summary>
		event RspUserLogin ^OnRspUserLogin;


	public:
		delegate void RspUserLogout(CTPCommon::CThostFtdcUserLogoutField pUserLogout, CTPCommon::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
	private:
		delegate void cppRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcUserLogoutField  cspUserLogout = (CTPCommon::CThostFtdcUserLogoutField) Marshal::PtrToStructure(IntPtr(pUserLogout), CTPCommon::CThostFtdcUserLogoutField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspUserLogout(cspUserLogout, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 登出请求响应
		/// </summary>
		event RspUserLogout ^OnRspUserLogout;




	public:
		delegate void RtnDepthMarketData(CTPCommon::CThostFtdcDepthMarketDataField pDepthMarketData);
	private:
		delegate void cppOnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData);
		void cppcbRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
		{
			CTPCommon::CThostFtdcDepthMarketDataField  cspDepthMarketData = (CTPCommon::CThostFtdcDepthMarketDataField) Marshal::PtrToStructure(IntPtr(pDepthMarketData), CTPCommon::CThostFtdcDepthMarketDataField::typeid);
			OnRtnDepthMarketData(cspDepthMarketData);
		}
	public:
		/// <summary>
		/// 期货发起银行资金转期货错误回报
		/// </summary>
		event RtnDepthMarketData ^OnRtnDepthMarketData;

	};
}
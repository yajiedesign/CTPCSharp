
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

			CThostFtdcMdSpi* pUserSpi = new CMdSpi();
			// 初始化UserApi
			pUserApi = CThostFtdcMdApi::CreateFtdcMdApi(MarshalString(_FlowPath).c_str());		// 创建UserApi

			pUserApi->RegisterSpi(pUserSpi);						// 注册事件类
			pUserApi->RegisterFront((char*)MarshalString(FrontAddr).c_str());					// connect
			pUserApi->Init();
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
					IntPtr tp = Marshal::StringToHGlobalAuto(ppInstrumentID[i]);
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
	};
}
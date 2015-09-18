#include "stdafx.h"
#include "KSTradeApi.h"
#include "ICTPTradeApi.h"
#include <string>


namespace CTPTradeApi
{
#include "../api/ThostFtdcTraderApi.h"
}

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

namespace CTPCLR
{
	public ref class KSTradeApiclr :ICTPTradeApi
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


	public:


		KSTradeApiclr(System::String ^_investor, System::String ^_pwd, System::String ^_broker,
			System::String ^_addr, System::String ^_FlowPath)
		{
			FrontAddr = _addr;
			BrokerID = _broker;
			InvestorID = _investor;
			passWord = _pwd;
			FlowPath = _FlowPath;

			pUserApi = KingstarAPI::CThostFtdcTraderApi::CreateFtdcTraderApi(MarshalString(_FlowPath).c_str());			// 创建UserApi
			pUserSpi = new KSTraderSpi();
			pUserApi->RegisterSpi((KingstarAPI::CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
			pUserApi->SubscribePublicTopic(THOST_TERT_QUICK/*THOST_TERT_RESTART*/);					// 注册公有流
			pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK/*THOST_TERT_RESTART*/);					// 注册私有流
			pUserApi->RegisterFront((char*)MarshalString(_addr).c_str());							// connect
			EventInit();
			pUserApi->Init();
		}

		virtual ~KSTradeApiclr(){

			for each (GCHandle var in gchlist)
			{
				var.Free();
			}
		}

		/// <summary>
		/// 前置地址
		/// </summary>
		virtual property  System::String ^ FrontAddr;
		/// <summary>
		/// 经纪公司代码
		/// </summary>
		virtual property  System::String ^ BrokerID;
		/// <summary>
		/// 投资者代码
		/// </summary>
		virtual property  System::String ^ InvestorID;
		virtual property  System::String ^ passWord;
		virtual property  System::String ^ FlowPath;

		/// <summary>
		/// 前置编号
		/// </summary>
		virtual property int FrontID;

		/// <summary>
		/// 会话编号
		/// </summary>
		virtual property int SessionID;

		/// <summary>
		/// 最大报单引用
		/// </summary>
		virtual property int MaxOrderRef;


		//投资者结算结果确认
		virtual int SettlementInfoConfirm([Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			KingstarAPI::CThostFtdcSettlementInfoConfirmField req;
			memset(&req, 0, sizeof(req));
			strcpy_s(req.BrokerID, MarshalString(BrokerID).c_str());
			strcpy_s(req.InvestorID, MarshalString(InvestorID).c_str());
			return pUserApi->ReqSettlementInfoConfirm(&req, nRequestID);
		}

		/// <summary>
		///报单录入请求
		/// </summary>
		virtual int ReqOrderInsert(CTPCommon::CThostFtdcInputOrderField pInputOrder, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			pInputOrder.RequestID = nRequestID;
			int size = Marshal::SizeOf(pInputOrder);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pInputOrder, bufferIntPtr, false);
				KingstarAPI::CThostFtdcInputOrderField* temp = static_cast<KingstarAPI::CThostFtdcInputOrderField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqOrderInsert(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///报单操作请求
		/// </summary>
		virtual int ReqOrderAction(CTPCommon::CThostFtdcInputOrderActionField pInputOrderAction, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			pInputOrderAction.RequestID = nRequestID;
			int size = Marshal::SizeOf(pInputOrderAction);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pInputOrderAction, bufferIntPtr, false);
				KingstarAPI::CThostFtdcInputOrderActionField* temp = static_cast<KingstarAPI::CThostFtdcInputOrderActionField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqOrderAction(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		//自动生成------------------------------------------------------------------------

		/// <summary>
		///客户端认证请求
		/// </summary>
		virtual int ReqAuthenticate(CTPCommon::CThostFtdcReqAuthenticateField pReqAuthenticateField, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pReqAuthenticateField);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pReqAuthenticateField, bufferIntPtr, false);
				KingstarAPI::CThostFtdcReqAuthenticateField* temp = static_cast<KingstarAPI::CThostFtdcReqAuthenticateField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqAuthenticate(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///用户登录请求
		/// </summary>
		virtual int ReqUserLogin(CTPCommon::CThostFtdcReqUserLoginField pReqUserLoginField, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pReqUserLoginField);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pReqUserLoginField, bufferIntPtr, false);
				KingstarAPI::CThostFtdcReqUserLoginField* temp = static_cast<KingstarAPI::CThostFtdcReqUserLoginField*>(bufferIntPtr.ToPointer());
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
		virtual int ReqUserLogout(CTPCommon::CThostFtdcUserLogoutField pUserLogout, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pUserLogout);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pUserLogout, bufferIntPtr, false);
				KingstarAPI::CThostFtdcUserLogoutField* temp = static_cast<KingstarAPI::CThostFtdcUserLogoutField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqUserLogout(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///用户口令更新请求
		/// </summary>
		virtual int ReqUserPasswordUpdate(CTPCommon::CThostFtdcUserPasswordUpdateField pUserPasswordUpdate, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pUserPasswordUpdate);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pUserPasswordUpdate, bufferIntPtr, false);
				KingstarAPI::CThostFtdcUserPasswordUpdateField* temp = static_cast<KingstarAPI::CThostFtdcUserPasswordUpdateField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqUserPasswordUpdate(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///资金账户口令更新请求
		/// </summary>
		virtual int ReqTradingAccountPasswordUpdate(CTPCommon::CThostFtdcTradingAccountPasswordUpdateField pTradingAccountPasswordUpdate, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pTradingAccountPasswordUpdate);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pTradingAccountPasswordUpdate, bufferIntPtr, false);
				KingstarAPI::CThostFtdcTradingAccountPasswordUpdateField* temp = static_cast<KingstarAPI::CThostFtdcTradingAccountPasswordUpdateField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqTradingAccountPasswordUpdate(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}



		/// <summary>
		///预埋单录入请求
		/// </summary>
		virtual int ReqParkedOrderInsert(CTPCommon::CThostFtdcParkedOrderField pParkedOrder, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pParkedOrder);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pParkedOrder, bufferIntPtr, false);
				KingstarAPI::CThostFtdcParkedOrderField* temp = static_cast<KingstarAPI::CThostFtdcParkedOrderField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqParkedOrderInsert(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///预埋撤单录入请求
		/// </summary>
		virtual int ReqParkedOrderAction(CTPCommon::CThostFtdcParkedOrderActionField pParkedOrderAction, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pParkedOrderAction);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pParkedOrderAction, bufferIntPtr, false);
				KingstarAPI::CThostFtdcParkedOrderActionField* temp = static_cast<KingstarAPI::CThostFtdcParkedOrderActionField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqParkedOrderAction(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}



		/// <summary>
		///查询最大报单数量请求
		/// </summary>
		virtual int ReqQueryMaxOrderVolume(CTPCommon::CThostFtdcQueryMaxOrderVolumeField pQueryMaxOrderVolume, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQueryMaxOrderVolume);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQueryMaxOrderVolume, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQueryMaxOrderVolumeField* temp = static_cast<KingstarAPI::CThostFtdcQueryMaxOrderVolumeField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQueryMaxOrderVolume(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///投资者结算结果确认
		/// </summary>
		virtual int ReqSettlementInfoConfirm(CTPCommon::CThostFtdcSettlementInfoConfirmField pSettlementInfoConfirm, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pSettlementInfoConfirm);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pSettlementInfoConfirm, bufferIntPtr, false);
				KingstarAPI::CThostFtdcSettlementInfoConfirmField* temp = static_cast<KingstarAPI::CThostFtdcSettlementInfoConfirmField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqSettlementInfoConfirm(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求删除预埋单
		/// </summary>
		virtual int ReqRemoveParkedOrder(CTPCommon::CThostFtdcRemoveParkedOrderField pRemoveParkedOrder, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pRemoveParkedOrder);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pRemoveParkedOrder, bufferIntPtr, false);
				KingstarAPI::CThostFtdcRemoveParkedOrderField* temp = static_cast<KingstarAPI::CThostFtdcRemoveParkedOrderField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqRemoveParkedOrder(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求删除预埋撤单
		/// </summary>
		virtual int ReqRemoveParkedOrderAction(CTPCommon::CThostFtdcRemoveParkedOrderActionField pRemoveParkedOrderAction, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pRemoveParkedOrderAction);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pRemoveParkedOrderAction, bufferIntPtr, false);
				KingstarAPI::CThostFtdcRemoveParkedOrderActionField* temp = static_cast<KingstarAPI::CThostFtdcRemoveParkedOrderActionField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqRemoveParkedOrderAction(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询报单
		/// </summary>
		virtual int ReqQryOrder(CTPCommon::CThostFtdcQryOrderField pQryOrder, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryOrder);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryOrder, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryOrderField* temp = static_cast<KingstarAPI::CThostFtdcQryOrderField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryOrder(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询成交
		/// </summary>
		virtual int ReqQryTrade(CTPCommon::CThostFtdcQryTradeField pQryTrade, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryTrade);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryTrade, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryTradeField* temp = static_cast<KingstarAPI::CThostFtdcQryTradeField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryTrade(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询投资者持仓
		/// </summary>
		virtual int ReqQryInvestorPosition(CTPCommon::CThostFtdcQryInvestorPositionField pQryInvestorPosition, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryInvestorPosition);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryInvestorPosition, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryInvestorPositionField* temp = static_cast<KingstarAPI::CThostFtdcQryInvestorPositionField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryInvestorPosition(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询资金账户
		/// </summary>
		virtual int ReqQryTradingAccount(CTPCommon::CThostFtdcQryTradingAccountField pQryTradingAccount, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryTradingAccount);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryTradingAccount, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryTradingAccountField* temp = static_cast<KingstarAPI::CThostFtdcQryTradingAccountField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryTradingAccount(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询投资者
		/// </summary>
		virtual int ReqQryInvestor(CTPCommon::CThostFtdcQryInvestorField pQryInvestor, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryInvestor);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryInvestor, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryInvestorField* temp = static_cast<KingstarAPI::CThostFtdcQryInvestorField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryInvestor(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询交易编码
		/// </summary>
		virtual int ReqQryTradingCode(CTPCommon::CThostFtdcQryTradingCodeField pQryTradingCode, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryTradingCode);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryTradingCode, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryTradingCodeField* temp = static_cast<KingstarAPI::CThostFtdcQryTradingCodeField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryTradingCode(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询合约保证金率
		/// </summary>
		virtual int ReqQryInstrumentMarginRate(CTPCommon::CThostFtdcQryInstrumentMarginRateField pQryInstrumentMarginRate, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryInstrumentMarginRate);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryInstrumentMarginRate, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryInstrumentMarginRateField* temp = static_cast<KingstarAPI::CThostFtdcQryInstrumentMarginRateField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryInstrumentMarginRate(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询合约手续费率
		/// </summary>
		virtual int ReqQryInstrumentCommissionRate(CTPCommon::CThostFtdcQryInstrumentCommissionRateField pQryInstrumentCommissionRate, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryInstrumentCommissionRate);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryInstrumentCommissionRate, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryInstrumentCommissionRateField* temp = static_cast<KingstarAPI::CThostFtdcQryInstrumentCommissionRateField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryInstrumentCommissionRate(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询交易所
		/// </summary>
		virtual int ReqQryExchange(CTPCommon::CThostFtdcQryExchangeField pQryExchange, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryExchange);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryExchange, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryExchangeField* temp = static_cast<KingstarAPI::CThostFtdcQryExchangeField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryExchange(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询合约
		/// </summary>
		virtual int ReqQryInstrument(CTPCommon::CThostFtdcQryInstrumentField pQryInstrument, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryInstrument);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryInstrument, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryInstrumentField* temp = static_cast<KingstarAPI::CThostFtdcQryInstrumentField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryInstrument(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询行情
		/// </summary>
		virtual int ReqQryDepthMarketData(CTPCommon::CThostFtdcQryDepthMarketDataField pQryDepthMarketData, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryDepthMarketData);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryDepthMarketData, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryDepthMarketDataField* temp = static_cast<KingstarAPI::CThostFtdcQryDepthMarketDataField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryDepthMarketData(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询投资者结算结果
		/// </summary>
		virtual int ReqQrySettlementInfo(CTPCommon::CThostFtdcQrySettlementInfoField pQrySettlementInfo, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQrySettlementInfo);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQrySettlementInfo, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQrySettlementInfoField* temp = static_cast<KingstarAPI::CThostFtdcQrySettlementInfoField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQrySettlementInfo(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询转帐银行
		/// </summary>
		virtual int ReqQryTransferBank(CTPCommon::CThostFtdcQryTransferBankField pQryTransferBank, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryTransferBank);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryTransferBank, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryTransferBankField* temp = static_cast<KingstarAPI::CThostFtdcQryTransferBankField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryTransferBank(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询投资者持仓明细
		/// </summary>
		virtual int ReqQryInvestorPositionDetail(CTPCommon::CThostFtdcQryInvestorPositionDetailField pQryInvestorPositionDetail, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryInvestorPositionDetail);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryInvestorPositionDetail, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryInvestorPositionDetailField* temp = static_cast<KingstarAPI::CThostFtdcQryInvestorPositionDetailField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryInvestorPositionDetail(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询客户通知
		/// </summary>
		virtual int ReqQryNotice(CTPCommon::CThostFtdcQryNoticeField pQryNotice, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryNotice);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryNotice, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryNoticeField* temp = static_cast<KingstarAPI::CThostFtdcQryNoticeField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryNotice(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询结算信息确认
		/// </summary>
		virtual int ReqQrySettlementInfoConfirm(CTPCommon::CThostFtdcQrySettlementInfoConfirmField pQrySettlementInfoConfirm, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQrySettlementInfoConfirm);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQrySettlementInfoConfirm, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQrySettlementInfoConfirmField* temp = static_cast<KingstarAPI::CThostFtdcQrySettlementInfoConfirmField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQrySettlementInfoConfirm(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询投资者持仓明细
		/// </summary>
		virtual int ReqQryInvestorPositionCombineDetail(CTPCommon::CThostFtdcQryInvestorPositionCombineDetailField pQryInvestorPositionCombineDetail, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryInvestorPositionCombineDetail);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryInvestorPositionCombineDetail, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryInvestorPositionCombineDetailField* temp = static_cast<KingstarAPI::CThostFtdcQryInvestorPositionCombineDetailField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryInvestorPositionCombineDetail(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询保证金监管系统经纪公司资金账户密钥
		/// </summary>
		virtual int ReqQryCFMMCTradingAccountKey(CTPCommon::CThostFtdcQryCFMMCTradingAccountKeyField pQryCFMMCTradingAccountKey, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryCFMMCTradingAccountKey);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryCFMMCTradingAccountKey, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryCFMMCTradingAccountKeyField* temp = static_cast<KingstarAPI::CThostFtdcQryCFMMCTradingAccountKeyField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryCFMMCTradingAccountKey(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询仓单折抵信息
		/// </summary>
		virtual int ReqQryEWarrantOffset(CTPCommon::CThostFtdcQryEWarrantOffsetField pQryEWarrantOffset, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryEWarrantOffset);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryEWarrantOffset, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryEWarrantOffsetField* temp = static_cast<KingstarAPI::CThostFtdcQryEWarrantOffsetField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryEWarrantOffset(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询投资者品种/跨品种保证金
		/// </summary>
		virtual int ReqQryInvestorProductGroupMargin(CTPCommon::CThostFtdcQryInvestorProductGroupMarginField pQryInvestorProductGroupMargin, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryInvestorProductGroupMargin);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryInvestorProductGroupMargin, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryInvestorProductGroupMarginField* temp = static_cast<KingstarAPI::CThostFtdcQryInvestorProductGroupMarginField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryInvestorProductGroupMargin(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询交易所保证金率
		/// </summary>
		virtual int ReqQryExchangeMarginRate(CTPCommon::CThostFtdcQryExchangeMarginRateField pQryExchangeMarginRate, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryExchangeMarginRate);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryExchangeMarginRate, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryExchangeMarginRateField* temp = static_cast<KingstarAPI::CThostFtdcQryExchangeMarginRateField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryExchangeMarginRate(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询交易所调整保证金率
		/// </summary>
		virtual int ReqQryExchangeMarginRateAdjust(CTPCommon::CThostFtdcQryExchangeMarginRateAdjustField pQryExchangeMarginRateAdjust, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryExchangeMarginRateAdjust);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryExchangeMarginRateAdjust, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryExchangeMarginRateAdjustField* temp = static_cast<KingstarAPI::CThostFtdcQryExchangeMarginRateAdjustField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryExchangeMarginRateAdjust(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询转帐流水
		/// </summary>
		virtual int ReqQryTransferSerial(CTPCommon::CThostFtdcQryTransferSerialField pQryTransferSerial, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryTransferSerial);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryTransferSerial, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryTransferSerialField* temp = static_cast<KingstarAPI::CThostFtdcQryTransferSerialField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryTransferSerial(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询银期签约关系
		/// </summary>
		virtual int ReqQryAccountregister(CTPCommon::CThostFtdcQryAccountregisterField pQryAccountregister, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryAccountregister);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryAccountregister, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryAccountregisterField* temp = static_cast<KingstarAPI::CThostFtdcQryAccountregisterField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryAccountregister(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询签约银行
		/// </summary>
		virtual int ReqQryContractBank(CTPCommon::CThostFtdcQryContractBankField pQryContractBank, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryContractBank);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryContractBank, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryContractBankField* temp = static_cast<KingstarAPI::CThostFtdcQryContractBankField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryContractBank(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询预埋单
		/// </summary>
		virtual int ReqQryParkedOrder(CTPCommon::CThostFtdcQryParkedOrderField pQryParkedOrder, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryParkedOrder);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryParkedOrder, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryParkedOrderField* temp = static_cast<KingstarAPI::CThostFtdcQryParkedOrderField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryParkedOrder(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询预埋撤单
		/// </summary>
		virtual int ReqQryParkedOrderAction(CTPCommon::CThostFtdcQryParkedOrderActionField pQryParkedOrderAction, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryParkedOrderAction);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryParkedOrderAction, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryParkedOrderActionField* temp = static_cast<KingstarAPI::CThostFtdcQryParkedOrderActionField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryParkedOrderAction(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询交易通知
		/// </summary>
		virtual int ReqQryTradingNotice(CTPCommon::CThostFtdcQryTradingNoticeField pQryTradingNotice, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryTradingNotice);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryTradingNotice, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryTradingNoticeField* temp = static_cast<KingstarAPI::CThostFtdcQryTradingNoticeField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryTradingNotice(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询经纪公司交易参数
		/// </summary>
		virtual int ReqQryBrokerTradingParams(CTPCommon::CThostFtdcQryBrokerTradingParamsField pQryBrokerTradingParams, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryBrokerTradingParams);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryBrokerTradingParams, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryBrokerTradingParamsField* temp = static_cast<KingstarAPI::CThostFtdcQryBrokerTradingParamsField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryBrokerTradingParams(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///请求查询经纪公司交易算法
		/// </summary>
		virtual int ReqQryBrokerTradingAlgos(CTPCommon::CThostFtdcQryBrokerTradingAlgosField pQryBrokerTradingAlgos, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pQryBrokerTradingAlgos);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pQryBrokerTradingAlgos, bufferIntPtr, false);
				KingstarAPI::CThostFtdcQryBrokerTradingAlgosField* temp = static_cast<KingstarAPI::CThostFtdcQryBrokerTradingAlgosField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQryBrokerTradingAlgos(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///期货发起银行资金转期货请求
		/// </summary>
		virtual int ReqFromBankToFutureByFuture(CTPCommon::CThostFtdcReqTransferField pReqTransfer, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pReqTransfer);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pReqTransfer, bufferIntPtr, false);
				KingstarAPI::CThostFtdcReqTransferField* temp = static_cast<KingstarAPI::CThostFtdcReqTransferField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqFromBankToFutureByFuture(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///期货发起期货资金转银行请求
		/// </summary>
		virtual int ReqFromFutureToBankByFuture(CTPCommon::CThostFtdcReqTransferField pReqTransfer, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pReqTransfer);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pReqTransfer, bufferIntPtr, false);
				KingstarAPI::CThostFtdcReqTransferField* temp = static_cast<KingstarAPI::CThostFtdcReqTransferField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqFromFutureToBankByFuture(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}

		/// <summary>
		///期货发起查询银行余额请求
		/// </summary>
		virtual int ReqQueryBankAccountMoneyByFuture(CTPCommon::CThostFtdcReqQueryAccountField pReqQueryAccount, [Out]  int %nRequestID)
		{
			nRequestID = Interlocked::Increment(lRequestID);
			int size = Marshal::SizeOf(pReqQueryAccount);
			IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
			try
			{
				Marshal::StructureToPtr(pReqQueryAccount, bufferIntPtr, false);
				KingstarAPI::CThostFtdcReqQueryAccountField* temp = static_cast<KingstarAPI::CThostFtdcReqQueryAccountField*>(bufferIntPtr.ToPointer());
				return pUserApi->ReqQueryBankAccountMoneyByFuture(temp, nRequestID);
			}
			finally
			{
				Marshal::FreeHGlobal(bufferIntPtr);
			}
		}


	private:
		void EventInit()
		{

			{
				cppFrontConnect^ fp = gcnew cppFrontConnect(this, &KSTradeApiclr::cppcbFrontConnect);
				GCHandle gch = GCHandle::Alloc(fp);
				gchlist->Add(gch);
				IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
				CBOnFrontConnected cb = static_cast<CBOnFrontConnected>(ip.ToPointer());
				pUserSpi->cbOnFrontConnected = cb;
			}

		{
			cppDisConnected^ fp = gcnew cppDisConnected(this, &KSTradeApiclr::cppcbDisConnected);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnFrontDisconnected cb = static_cast<CBOnFrontDisconnected>(ip.ToPointer());
			pUserSpi->cbOnFrontDisconnected = cb;
		}

		{
			cppHeartBeatWarning^ fp = gcnew cppHeartBeatWarning(this, &KSTradeApiclr::cppcbHeartBeatWarning);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnHeartBeatWarning cb = static_cast<CBOnHeartBeatWarning>(ip.ToPointer());
			pUserSpi->cbOnHeartBeatWarning = cb;
		}

		{
			cppErrRtnBankToFutureByFuture^ fp = gcnew cppErrRtnBankToFutureByFuture(this, &KSTradeApiclr::cppcbErrRtnBankToFutureByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnBankToFutureByFuture cb = static_cast<CBErrRtnBankToFutureByFuture>(ip.ToPointer());
			pUserSpi->cbErrRtnBankToFutureByFuture = cb;
		}

		{
			cppErrRtnFutureToBankByFuture^ fp = gcnew cppErrRtnFutureToBankByFuture(this, &KSTradeApiclr::cppcbErrRtnFutureToBankByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnFutureToBankByFuture cb = static_cast<CBErrRtnFutureToBankByFuture>(ip.ToPointer());
			pUserSpi->cbErrRtnFutureToBankByFuture = cb;
		}

		{
			cppErrRtnOrderAction^ fp = gcnew cppErrRtnOrderAction(this, &KSTradeApiclr::cppcbErrRtnOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnOrderAction cb = static_cast<CBErrRtnOrderAction>(ip.ToPointer());
			pUserSpi->cbErrRtnOrderAction = cb;
		}

		{
			cppErrRtnOrderInsert^ fp = gcnew cppErrRtnOrderInsert(this, &KSTradeApiclr::cppcbErrRtnOrderInsert);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnOrderInsert cb = static_cast<CBErrRtnOrderInsert>(ip.ToPointer());
			pUserSpi->cbErrRtnOrderInsert = cb;
		}

		{
			cppErrRtnQueryBankBalanceByFuture^ fp = gcnew cppErrRtnQueryBankBalanceByFuture(this, &KSTradeApiclr::cppcbErrRtnQueryBankBalanceByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnQueryBankBalanceByFuture cb = static_cast<CBErrRtnQueryBankBalanceByFuture>(ip.ToPointer());
			pUserSpi->cbErrRtnQueryBankBalanceByFuture = cb;
		}

		{
			cppErrRtnRepealBankToFutureByFutureManual^ fp = gcnew cppErrRtnRepealBankToFutureByFutureManual(this, &KSTradeApiclr::cppcbErrRtnRepealBankToFutureByFutureManual);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnRepealBankToFutureByFutureManual cb = static_cast<CBErrRtnRepealBankToFutureByFutureManual>(ip.ToPointer());
			pUserSpi->cbErrRtnRepealBankToFutureByFutureManual = cb;
		}

		{
			cppErrRtnRepealFutureToBankByFutureManual^ fp = gcnew cppErrRtnRepealFutureToBankByFutureManual(this, &KSTradeApiclr::cppcbErrRtnRepealFutureToBankByFutureManual);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnRepealFutureToBankByFutureManual cb = static_cast<CBErrRtnRepealFutureToBankByFutureManual>(ip.ToPointer());
			pUserSpi->cbErrRtnRepealFutureToBankByFutureManual = cb;
		}

		{
			cppRspError^ fp = gcnew cppRspError(this, &KSTradeApiclr::cppcbRspError);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspError cb = static_cast<CBRspError>(ip.ToPointer());
			pUserSpi->cbRspError = cb;
		}

		{
			cppRspFromBankToFutureByFuture^ fp = gcnew cppRspFromBankToFutureByFuture(this, &KSTradeApiclr::cppcbRspFromBankToFutureByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspFromBankToFutureByFuture cb = static_cast<CBRspFromBankToFutureByFuture>(ip.ToPointer());
			pUserSpi->cbRspFromBankToFutureByFuture = cb;
		}

		{
			cppRspFromFutureToBankByFuture^ fp = gcnew cppRspFromFutureToBankByFuture(this, &KSTradeApiclr::cppcbRspFromFutureToBankByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspFromFutureToBankByFuture cb = static_cast<CBRspFromFutureToBankByFuture>(ip.ToPointer());
			pUserSpi->cbRspFromFutureToBankByFuture = cb;
		}

		{
			cppRspOrderAction^ fp = gcnew cppRspOrderAction(this, &KSTradeApiclr::cppcbRspOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspOrderAction cb = static_cast<CBRspOrderAction>(ip.ToPointer());
			pUserSpi->cbRspOrderAction = cb;
		}

		{
			cppRspOrderInsert^ fp = gcnew cppRspOrderInsert(this, &KSTradeApiclr::cppcbRspOrderInsert);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspOrderInsert cb = static_cast<CBRspOrderInsert>(ip.ToPointer());
			pUserSpi->cbRspOrderInsert = cb;
		}

		{
			cppRspParkedOrderAction^ fp = gcnew cppRspParkedOrderAction(this, &KSTradeApiclr::cppcbRspParkedOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspParkedOrderAction cb = static_cast<CBRspParkedOrderAction>(ip.ToPointer());
			pUserSpi->cbRspParkedOrderAction = cb;
		}

		{
			cppRspParkedOrderInsert^ fp = gcnew cppRspParkedOrderInsert(this, &KSTradeApiclr::cppcbRspParkedOrderInsert);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspParkedOrderInsert cb = static_cast<CBRspParkedOrderInsert>(ip.ToPointer());
			pUserSpi->cbRspParkedOrderInsert = cb;
		}

		{
			cppRspQryBrokerTradingAlgos^ fp = gcnew cppRspQryBrokerTradingAlgos(this, &KSTradeApiclr::cppcbRspQryBrokerTradingAlgos);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryBrokerTradingAlgos cb = static_cast<CBRspQryBrokerTradingAlgos>(ip.ToPointer());
			pUserSpi->cbRspQryBrokerTradingAlgos = cb;
		}

		{
			cppRspQryBrokerTradingParams^ fp = gcnew cppRspQryBrokerTradingParams(this, &KSTradeApiclr::cppcbRspQryBrokerTradingParams);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryBrokerTradingParams cb = static_cast<CBRspQryBrokerTradingParams>(ip.ToPointer());
			pUserSpi->cbRspQryBrokerTradingParams = cb;
		}

		{
			cppRspQryCFMMCTradingAccountKey^ fp = gcnew cppRspQryCFMMCTradingAccountKey(this, &KSTradeApiclr::cppcbRspQryCFMMCTradingAccountKey);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryCFMMCTradingAccountKey cb = static_cast<CBRspQryCFMMCTradingAccountKey>(ip.ToPointer());
			pUserSpi->cbRspQryCFMMCTradingAccountKey = cb;
		}

		{
			cppRspQryContractBank^ fp = gcnew cppRspQryContractBank(this, &KSTradeApiclr::cppcbRspQryContractBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryContractBank cb = static_cast<CBRspQryContractBank>(ip.ToPointer());
			pUserSpi->cbRspQryContractBank = cb;
		}

		{
			cppRspQryDepthMarketData^ fp = gcnew cppRspQryDepthMarketData(this, &KSTradeApiclr::cppcbRspQryDepthMarketData);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryDepthMarketData cb = static_cast<CBRspQryDepthMarketData>(ip.ToPointer());
			pUserSpi->cbRspQryDepthMarketData = cb;
		}

		{
			cppRspQryExchange^ fp = gcnew cppRspQryExchange(this, &KSTradeApiclr::cppcbRspQryExchange);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryExchange cb = static_cast<CBRspQryExchange>(ip.ToPointer());
			pUserSpi->cbRspQryExchange = cb;
		}

		{
			cppRspQryInstrument^ fp = gcnew cppRspQryInstrument(this, &KSTradeApiclr::cppcbRspQryInstrument);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInstrument cb = static_cast<CBRspQryInstrument>(ip.ToPointer());
			pUserSpi->cbRspQryInstrument = cb;
		}

		{
			cppRspQryInstrumentCommissionRate^ fp = gcnew cppRspQryInstrumentCommissionRate(this, &KSTradeApiclr::cppcbRspQryInstrumentCommissionRate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInstrumentCommissionRate cb = static_cast<CBRspQryInstrumentCommissionRate>(ip.ToPointer());
			pUserSpi->cbRspQryInstrumentCommissionRate = cb;
		}

		{
			cppRspQryInstrumentMarginRate^ fp = gcnew cppRspQryInstrumentMarginRate(this, &KSTradeApiclr::cppcbRspQryInstrumentMarginRate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInstrumentMarginRate cb = static_cast<CBRspQryInstrumentMarginRate>(ip.ToPointer());
			pUserSpi->cbRspQryInstrumentMarginRate = cb;
		}

		{
			cppRspQryInvestor^ fp = gcnew cppRspQryInvestor(this, &KSTradeApiclr::cppcbRspQryInvestor);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInvestor cb = static_cast<CBRspQryInvestor>(ip.ToPointer());
			pUserSpi->cbRspQryInvestor = cb;
		}

		{
			cppRspQryInvestorPosition^ fp = gcnew cppRspQryInvestorPosition(this, &KSTradeApiclr::cppcbRspQryInvestorPosition);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInvestorPosition cb = static_cast<CBRspQryInvestorPosition>(ip.ToPointer());
			pUserSpi->cbRspQryInvestorPosition = cb;
		}

		{
			cppRspQryInvestorPositionCombineDetail^ fp = gcnew cppRspQryInvestorPositionCombineDetail(this, &KSTradeApiclr::cppcbRspQryInvestorPositionCombineDetail);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInvestorPositionCombineDetail cb = static_cast<CBRspQryInvestorPositionCombineDetail>(ip.ToPointer());
			pUserSpi->cbRspQryInvestorPositionCombineDetail = cb;
		}

		{
			cppRspQryInvestorPositionDetail^ fp = gcnew cppRspQryInvestorPositionDetail(this, &KSTradeApiclr::cppcbRspQryInvestorPositionDetail);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInvestorPositionDetail cb = static_cast<CBRspQryInvestorPositionDetail>(ip.ToPointer());
			pUserSpi->cbRspQryInvestorPositionDetail = cb;
		}

		{
			cppRspQryNotice^ fp = gcnew cppRspQryNotice(this, &KSTradeApiclr::cppcbRspQryNotice);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryNotice cb = static_cast<CBRspQryNotice>(ip.ToPointer());
			pUserSpi->cbRspQryNotice = cb;
		}

		{
			cppRspQryOrder^ fp = gcnew cppRspQryOrder(this, &KSTradeApiclr::cppcbRspQryOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryOrder cb = static_cast<CBRspQryOrder>(ip.ToPointer());
			pUserSpi->cbRspQryOrder = cb;
		}

		{
			cppRspQryParkedOrder^ fp = gcnew cppRspQryParkedOrder(this, &KSTradeApiclr::cppcbRspQryParkedOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryParkedOrder cb = static_cast<CBRspQryParkedOrder>(ip.ToPointer());
			pUserSpi->cbRspQryParkedOrder = cb;
		}

		{
			cppRspQryParkedOrderAction^ fp = gcnew cppRspQryParkedOrderAction(this, &KSTradeApiclr::cppcbRspQryParkedOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryParkedOrderAction cb = static_cast<CBRspQryParkedOrderAction>(ip.ToPointer());
			pUserSpi->cbRspQryParkedOrderAction = cb;
		}

		{
			cppRspQrySettlementInfo^ fp = gcnew cppRspQrySettlementInfo(this, &KSTradeApiclr::cppcbRspQrySettlementInfo);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQrySettlementInfo cb = static_cast<CBRspQrySettlementInfo>(ip.ToPointer());
			pUserSpi->cbRspQrySettlementInfo = cb;
		}

		{
			cppRspQrySettlementInfoConfirm^ fp = gcnew cppRspQrySettlementInfoConfirm(this, &KSTradeApiclr::cppcbRspQrySettlementInfoConfirm);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQrySettlementInfoConfirm cb = static_cast<CBRspQrySettlementInfoConfirm>(ip.ToPointer());
			pUserSpi->cbRspQrySettlementInfoConfirm = cb;
		}

		{
			cppRspQryTrade^ fp = gcnew cppRspQryTrade(this, &KSTradeApiclr::cppcbRspQryTrade);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTrade cb = static_cast<CBRspQryTrade>(ip.ToPointer());
			pUserSpi->cbRspQryTrade = cb;
		}

		{
			cppRspQryTradingAccount^ fp = gcnew cppRspQryTradingAccount(this, &KSTradeApiclr::cppcbRspQryTradingAccount);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTradingAccount cb = static_cast<CBRspQryTradingAccount>(ip.ToPointer());
			pUserSpi->cbRspQryTradingAccount = cb;
		}

		{
			cppRspQryTradingCode^ fp = gcnew cppRspQryTradingCode(this, &KSTradeApiclr::cppcbRspQryTradingCode);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTradingCode cb = static_cast<CBRspQryTradingCode>(ip.ToPointer());
			pUserSpi->cbRspQryTradingCode = cb;
		}

		{
			cppRspQryTradingNotice^ fp = gcnew cppRspQryTradingNotice(this, &KSTradeApiclr::cppcbRspQryTradingNotice);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTradingNotice cb = static_cast<CBRspQryTradingNotice>(ip.ToPointer());
			pUserSpi->cbRspQryTradingNotice = cb;
		}

		{
			cppRspQryTransferBank^ fp = gcnew cppRspQryTransferBank(this, &KSTradeApiclr::cppcbRspQryTransferBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTransferBank cb = static_cast<CBRspQryTransferBank>(ip.ToPointer());
			pUserSpi->cbRspQryTransferBank = cb;
		}

		{
			cppRspQryTransferSerial^ fp = gcnew cppRspQryTransferSerial(this, &KSTradeApiclr::cppcbRspQryTransferSerial);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTransferSerial cb = static_cast<CBRspQryTransferSerial>(ip.ToPointer());
			pUserSpi->cbRspQryTransferSerial = cb;
		}

		{
			cppRspQryAccountregister^ fp = gcnew cppRspQryAccountregister(this, &KSTradeApiclr::cppcbRspQryAccountregister);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryAccountregister cb = static_cast<CBRspQryAccountregister>(ip.ToPointer());
			pUserSpi->cbRspQryAccountregister = cb;
		}

		{
			cppRspQueryBankAccountMoneyByFuture^ fp = gcnew cppRspQueryBankAccountMoneyByFuture(this, &KSTradeApiclr::cppcbRspQueryBankAccountMoneyByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQueryBankAccountMoneyByFuture cb = static_cast<CBRspQueryBankAccountMoneyByFuture>(ip.ToPointer());
			pUserSpi->cbRspQueryBankAccountMoneyByFuture = cb;
		}

		{
			cppRspQueryMaxOrderVolume^ fp = gcnew cppRspQueryMaxOrderVolume(this, &KSTradeApiclr::cppcbRspQueryMaxOrderVolume);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQueryMaxOrderVolume cb = static_cast<CBRspQueryMaxOrderVolume>(ip.ToPointer());
			pUserSpi->cbRspQueryMaxOrderVolume = cb;
		}

		{
			cppRspRemoveParkedOrder^ fp = gcnew cppRspRemoveParkedOrder(this, &KSTradeApiclr::cppcbRspRemoveParkedOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspRemoveParkedOrder cb = static_cast<CBRspRemoveParkedOrder>(ip.ToPointer());
			pUserSpi->cbRspRemoveParkedOrder = cb;
		}

		{
			cppRspRemoveParkedOrderAction^ fp = gcnew cppRspRemoveParkedOrderAction(this, &KSTradeApiclr::cppcbRspRemoveParkedOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspRemoveParkedOrderAction cb = static_cast<CBRspRemoveParkedOrderAction>(ip.ToPointer());
			pUserSpi->cbRspRemoveParkedOrderAction = cb;
		}

		{
			cppRspSettlementInfoConfirm^ fp = gcnew cppRspSettlementInfoConfirm(this, &KSTradeApiclr::cppcbRspSettlementInfoConfirm);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspSettlementInfoConfirm cb = static_cast<CBRspSettlementInfoConfirm>(ip.ToPointer());
			pUserSpi->cbRspSettlementInfoConfirm = cb;
		}

		{
			cppRspTradingAccountPasswordUpdate^ fp = gcnew cppRspTradingAccountPasswordUpdate(this, &KSTradeApiclr::cppcbRspTradingAccountPasswordUpdate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspTradingAccountPasswordUpdate cb = static_cast<CBRspTradingAccountPasswordUpdate>(ip.ToPointer());
			pUserSpi->cbRspTradingAccountPasswordUpdate = cb;
		}

		{
			cppRspAuthenticate^ fp = gcnew cppRspAuthenticate(this, &KSTradeApiclr::cppcbRspAuthenticate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspAuthenticate cb = static_cast<CBRspAuthenticate>(ip.ToPointer());
			pUserSpi->cbRspAuthenticate = cb;
		}


		{
			cppRspUserLogin^ fp = gcnew cppRspUserLogin(this, &KSTradeApiclr::cppcbRspUserLogin);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspUserLogin cb = static_cast<CBRspUserLogin>(ip.ToPointer());
			pUserSpi->cbRspUserLogin = cb;
		}

		{
			cppRspUserLogout^ fp = gcnew cppRspUserLogout(this, &KSTradeApiclr::cppcbRspUserLogout);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspUserLogout cb = static_cast<CBRspUserLogout>(ip.ToPointer());
			pUserSpi->cbRspUserLogout = cb;
		}

		{
			cppRspUserPasswordUpdate^ fp = gcnew cppRspUserPasswordUpdate(this, &KSTradeApiclr::cppcbRspUserPasswordUpdate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspUserPasswordUpdate cb = static_cast<CBRspUserPasswordUpdate>(ip.ToPointer());
			pUserSpi->cbRspUserPasswordUpdate = cb;
		}

		{
			cppRtnErrorConditionalOrder^ fp = gcnew cppRtnErrorConditionalOrder(this, &KSTradeApiclr::cppcbRtnErrorConditionalOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnErrorConditionalOrder cb = static_cast<CBRtnErrorConditionalOrder>(ip.ToPointer());
			pUserSpi->cbRtnErrorConditionalOrder = cb;
		}

		{
			cppRtnFromBankToFutureByBank^ fp = gcnew cppRtnFromBankToFutureByBank(this, &KSTradeApiclr::cppcbRtnFromBankToFutureByBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnFromBankToFutureByBank cb = static_cast<CBRtnFromBankToFutureByBank>(ip.ToPointer());
			pUserSpi->cbRtnFromBankToFutureByBank = cb;
		}

		{
			cppRtnFromBankToFutureByFuture^ fp = gcnew cppRtnFromBankToFutureByFuture(this, &KSTradeApiclr::cppcbRtnFromBankToFutureByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnFromBankToFutureByFuture cb = static_cast<CBRtnFromBankToFutureByFuture>(ip.ToPointer());
			pUserSpi->cbRtnFromBankToFutureByFuture = cb;
		}

		{
			cppRtnFromFutureToBankByBank^ fp = gcnew cppRtnFromFutureToBankByBank(this, &KSTradeApiclr::cppcbRtnFromFutureToBankByBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnFromFutureToBankByBank cb = static_cast<CBRtnFromFutureToBankByBank>(ip.ToPointer());
			pUserSpi->cbRtnFromFutureToBankByBank = cb;
		}

		{
			cppRtnFromFutureToBankByFuture^ fp = gcnew cppRtnFromFutureToBankByFuture(this, &KSTradeApiclr::cppcbRtnFromFutureToBankByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnFromFutureToBankByFuture cb = static_cast<CBRtnFromFutureToBankByFuture>(ip.ToPointer());
			pUserSpi->cbRtnFromFutureToBankByFuture = cb;
		}

		{
			cppRtnInstrumentStatus^ fp = gcnew cppRtnInstrumentStatus(this, &KSTradeApiclr::cppcbRtnInstrumentStatus);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnInstrumentStatus cb = static_cast<CBRtnInstrumentStatus>(ip.ToPointer());
			pUserSpi->cbRtnInstrumentStatus = cb;
		}

		{
			cppRtnOrder^ fp = gcnew cppRtnOrder(this, &KSTradeApiclr::cppcbRtnOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnOrder cb = static_cast<CBRtnOrder>(ip.ToPointer());
			pUserSpi->cbRtnOrder = cb;
		}

		{
			cppRtnQueryBankBalanceByFuture^ fp = gcnew cppRtnQueryBankBalanceByFuture(this, &KSTradeApiclr::cppcbRtnQueryBankBalanceByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnQueryBankBalanceByFuture cb = static_cast<CBRtnQueryBankBalanceByFuture>(ip.ToPointer());
			pUserSpi->cbRtnQueryBankBalanceByFuture = cb;
		}

		{
			cppRtnRepealFromBankToFutureByBank^ fp = gcnew cppRtnRepealFromBankToFutureByBank(this, &KSTradeApiclr::cppcbRtnRepealFromBankToFutureByBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromBankToFutureByBank cb = static_cast<CBRtnRepealFromBankToFutureByBank>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromBankToFutureByBank = cb;
		}

		{
			cppRtnRepealFromBankToFutureByFuture^ fp = gcnew cppRtnRepealFromBankToFutureByFuture(this, &KSTradeApiclr::cppcbRtnRepealFromBankToFutureByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromBankToFutureByFuture cb = static_cast<CBRtnRepealFromBankToFutureByFuture>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromBankToFutureByFuture = cb;
		}

		{
			cppRtnRepealFromBankToFutureByFutureManual^ fp = gcnew cppRtnRepealFromBankToFutureByFutureManual(this, &KSTradeApiclr::cppcbRtnRepealFromBankToFutureByFutureManual);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromBankToFutureByFutureManual cb = static_cast<CBRtnRepealFromBankToFutureByFutureManual>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromBankToFutureByFutureManual = cb;
		}

		{
			cppRtnRepealFromFutureToBankByBank^ fp = gcnew cppRtnRepealFromFutureToBankByBank(this, &KSTradeApiclr::cppcbRtnRepealFromFutureToBankByBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromFutureToBankByBank cb = static_cast<CBRtnRepealFromFutureToBankByBank>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromFutureToBankByBank = cb;
		}

		{
			cppRtnRepealFromFutureToBankByFuture^ fp = gcnew cppRtnRepealFromFutureToBankByFuture(this, &KSTradeApiclr::cppcbRtnRepealFromFutureToBankByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromFutureToBankByFuture cb = static_cast<CBRtnRepealFromFutureToBankByFuture>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromFutureToBankByFuture = cb;
		}

		{
			cppRtnRepealFromFutureToBankByFutureManual^ fp = gcnew cppRtnRepealFromFutureToBankByFutureManual(this, &KSTradeApiclr::cppcbRtnRepealFromFutureToBankByFutureManual);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromFutureToBankByFutureManual cb = static_cast<CBRtnRepealFromFutureToBankByFutureManual>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromFutureToBankByFutureManual = cb;
		}

		{
			cppRtnTrade^ fp = gcnew cppRtnTrade(this, &KSTradeApiclr::cppcbRtnTrade);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnTrade cb = static_cast<CBRtnTrade>(ip.ToPointer());
			pUserSpi->cbRtnTrade = cb;
		}

		{
			cppRtnTradingNotice^ fp = gcnew cppRtnTradingNotice(this, &KSTradeApiclr::cppcbRtnTradingNotice);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnTradingNotice cb = static_cast<CBRtnTradingNotice>(ip.ToPointer());
			pUserSpi->cbRtnTradingNotice = cb;
		}

		}





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
		virtual event FrontConnect ^OnFrontConnect;




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
		virtual event DisConnected ^OnDisConnected;




	private:
		delegate void cppHeartBeatWarning(int pTimeLapes);
		void cppcbHeartBeatWarning(int pTimeLapes)
		{

			OnHeartBeatWarning(pTimeLapes);
		}
	public:
		/// <summary>
		/// 心跳超时警告。当长时间未收到报文时，该方法被调用。
		/// </summary>
		virtual event HeartBeatWarning ^OnHeartBeatWarning;




	private:
		delegate void cppErrRtnBankToFutureByFuture(KingstarAPI::CThostFtdcReqTransferField *pReqTransfer, KingstarAPI::CThostFtdcRspInfoField *pRspInfo);
		void cppcbErrRtnBankToFutureByFuture(KingstarAPI::CThostFtdcReqTransferField *pReqTransfer, KingstarAPI::CThostFtdcRspInfoField *pRspInfo)
		{
			CTPCommon::CThostFtdcReqTransferField  cspReqTransfer = (CTPCommon::CThostFtdcReqTransferField) Marshal::PtrToStructure(IntPtr(pReqTransfer), CTPCommon::CThostFtdcReqTransferField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnErrRtnBankToFutureByFuture(cspReqTransfer, cspRspInfo);
		}
	public:
		/// <summary>
		/// 期货发起银行资金转期货错误回报
		/// </summary>
		virtual event ErrRtnBankToFutureByFuture ^OnErrRtnBankToFutureByFuture;




	private:
		delegate void cppErrRtnFutureToBankByFuture(KingstarAPI::CThostFtdcReqTransferField *pReqTransfer, KingstarAPI::CThostFtdcRspInfoField *pRspInfo);
		void cppcbErrRtnFutureToBankByFuture(KingstarAPI::CThostFtdcReqTransferField *pReqTransfer, KingstarAPI::CThostFtdcRspInfoField *pRspInfo)
		{
			CTPCommon::CThostFtdcReqTransferField  cspReqTransfer = (CTPCommon::CThostFtdcReqTransferField) Marshal::PtrToStructure(IntPtr(pReqTransfer), CTPCommon::CThostFtdcReqTransferField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnErrRtnFutureToBankByFuture(cspReqTransfer, cspRspInfo);
		}
	public:
		/// <summary>
		/// 期货发起期货资金转银行错误回报
		/// </summary>
		virtual event ErrRtnFutureToBankByFuture ^OnErrRtnFutureToBankByFuture;




	private:
		delegate void cppErrRtnOrderAction(KingstarAPI::CThostFtdcOrderActionField *pOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo);
		void cppcbErrRtnOrderAction(KingstarAPI::CThostFtdcOrderActionField *pOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo)
		{
			CTPCommon::CThostFtdcOrderActionField  cspOrderAction = (CTPCommon::CThostFtdcOrderActionField) Marshal::PtrToStructure(IntPtr(pOrderAction), CTPCommon::CThostFtdcOrderActionField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnErrRtnOrderAction(cspOrderAction, cspRspInfo);
		}
	public:
		/// <summary>
		/// 报单操作错误回报
		/// </summary>
		virtual event ErrRtnOrderAction ^OnErrRtnOrderAction;




	private:
		delegate void cppErrRtnOrderInsert(KingstarAPI::CThostFtdcInputOrderField *pInputOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo);
		void cppcbErrRtnOrderInsert(KingstarAPI::CThostFtdcInputOrderField *pInputOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo)
		{
			CTPCommon::CThostFtdcInputOrderField  cspInputOrder = (CTPCommon::CThostFtdcInputOrderField) Marshal::PtrToStructure(IntPtr(pInputOrder), CTPCommon::CThostFtdcInputOrderField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnErrRtnOrderInsert(cspInputOrder, cspRspInfo);
		}
	public:
		/// <summary>
		/// 报单录入错误回报
		/// </summary>
		virtual event ErrRtnOrderInsert ^OnErrRtnOrderInsert;




	private:
		delegate void cppErrRtnQueryBankBalanceByFuture(KingstarAPI::CThostFtdcReqQueryAccountField *pReqQueryAccount, KingstarAPI::CThostFtdcRspInfoField *pRspInfo);
		void cppcbErrRtnQueryBankBalanceByFuture(KingstarAPI::CThostFtdcReqQueryAccountField *pReqQueryAccount, KingstarAPI::CThostFtdcRspInfoField *pRspInfo)
		{
			CTPCommon::CThostFtdcReqQueryAccountField  cspReqQueryAccount = (CTPCommon::CThostFtdcReqQueryAccountField) Marshal::PtrToStructure(IntPtr(pReqQueryAccount), CTPCommon::CThostFtdcReqQueryAccountField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnErrRtnQueryBankBalanceByFuture(cspReqQueryAccount, cspRspInfo);
		}
	public:
		/// <summary>
		/// 期货发起查询银行余额错误回报
		/// </summary>
		virtual event ErrRtnQueryBankBalanceByFuture ^OnErrRtnQueryBankBalanceByFuture;




	private:
		delegate void cppErrRtnRepealBankToFutureByFutureManual(KingstarAPI::CThostFtdcReqRepealField *pReqRepeal, KingstarAPI::CThostFtdcRspInfoField *pRspInfo);
		void cppcbErrRtnRepealBankToFutureByFutureManual(KingstarAPI::CThostFtdcReqRepealField *pReqRepeal, KingstarAPI::CThostFtdcRspInfoField *pRspInfo)
		{
			CTPCommon::CThostFtdcReqRepealField  cspReqRepeal = (CTPCommon::CThostFtdcReqRepealField) Marshal::PtrToStructure(IntPtr(pReqRepeal), CTPCommon::CThostFtdcReqRepealField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnErrRtnRepealBankToFutureByFutureManual(cspReqRepeal, cspRspInfo);
		}
	public:
		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报
		/// </summary>
		virtual event ErrRtnRepealBankToFutureByFutureManual ^OnErrRtnRepealBankToFutureByFutureManual;




	private:
		delegate void cppErrRtnRepealFutureToBankByFutureManual(KingstarAPI::CThostFtdcReqRepealField *pReqRepeal, KingstarAPI::CThostFtdcRspInfoField *pRspInfo);
		void cppcbErrRtnRepealFutureToBankByFutureManual(KingstarAPI::CThostFtdcReqRepealField *pReqRepeal, KingstarAPI::CThostFtdcRspInfoField *pRspInfo)
		{
			CTPCommon::CThostFtdcReqRepealField  cspReqRepeal = (CTPCommon::CThostFtdcReqRepealField) Marshal::PtrToStructure(IntPtr(pReqRepeal), CTPCommon::CThostFtdcReqRepealField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnErrRtnRepealFutureToBankByFutureManual(cspReqRepeal, cspRspInfo);
		}
	public:
		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报
		/// </summary>
		virtual event ErrRtnRepealFutureToBankByFutureManual ^OnErrRtnRepealFutureToBankByFutureManual;




	private:
		delegate void cppRspError(KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspError(KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspError(cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 错误应答
		/// </summary>
		virtual event RspError ^OnRspError;




	private:
		delegate void cppRspFromBankToFutureByFuture(KingstarAPI::CThostFtdcReqTransferField *pReqTransfer, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspFromBankToFutureByFuture(KingstarAPI::CThostFtdcReqTransferField *pReqTransfer, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcReqTransferField  cspReqTransfer = (CTPCommon::CThostFtdcReqTransferField) Marshal::PtrToStructure(IntPtr(pReqTransfer), CTPCommon::CThostFtdcReqTransferField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspFromBankToFutureByFuture(cspReqTransfer, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 期货发起银行资金转期货应答
		/// </summary>
		virtual event RspFromBankToFutureByFuture ^OnRspFromBankToFutureByFuture;




	private:
		delegate void cppRspFromFutureToBankByFuture(KingstarAPI::CThostFtdcReqTransferField *pReqTransfer, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspFromFutureToBankByFuture(KingstarAPI::CThostFtdcReqTransferField *pReqTransfer, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcReqTransferField  cspReqTransfer = (CTPCommon::CThostFtdcReqTransferField) Marshal::PtrToStructure(IntPtr(pReqTransfer), CTPCommon::CThostFtdcReqTransferField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspFromFutureToBankByFuture(cspReqTransfer, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 期货发起期货资金转银行应答
		/// </summary>
		virtual event RspFromFutureToBankByFuture ^OnRspFromFutureToBankByFuture;




	private:
		delegate void cppRspOrderAction(KingstarAPI::CThostFtdcInputOrderActionField *pInputOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspOrderAction(KingstarAPI::CThostFtdcInputOrderActionField *pInputOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcInputOrderActionField  cspInputOrderAction = (CTPCommon::CThostFtdcInputOrderActionField) Marshal::PtrToStructure(IntPtr(pInputOrderAction), CTPCommon::CThostFtdcInputOrderActionField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspOrderAction(cspInputOrderAction, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 报单操作请求响应
		/// </summary>
		virtual event RspOrderAction ^OnRspOrderAction;




	private:
		delegate void cppRspOrderInsert(KingstarAPI::CThostFtdcInputOrderField *pInputOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspOrderInsert(KingstarAPI::CThostFtdcInputOrderField *pInputOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcInputOrderField  cspInputOrder = (CTPCommon::CThostFtdcInputOrderField) Marshal::PtrToStructure(IntPtr(pInputOrder), CTPCommon::CThostFtdcInputOrderField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspOrderInsert(cspInputOrder, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 报单录入请求响应
		/// </summary>
		virtual event RspOrderInsert ^OnRspOrderInsert;




	private:
		delegate void cppRspParkedOrderAction(KingstarAPI::CThostFtdcParkedOrderActionField *pParkedOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspParkedOrderAction(KingstarAPI::CThostFtdcParkedOrderActionField *pParkedOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcParkedOrderActionField  cspParkedOrderAction = (CTPCommon::CThostFtdcParkedOrderActionField) Marshal::PtrToStructure(IntPtr(pParkedOrderAction), CTPCommon::CThostFtdcParkedOrderActionField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspParkedOrderAction(cspParkedOrderAction, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 预埋撤单录入请求响应
		/// </summary>
		virtual event RspParkedOrderAction ^OnRspParkedOrderAction;




	private:
		delegate void cppRspParkedOrderInsert(KingstarAPI::CThostFtdcParkedOrderField *pParkedOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspParkedOrderInsert(KingstarAPI::CThostFtdcParkedOrderField *pParkedOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcParkedOrderField  cspParkedOrder = (CTPCommon::CThostFtdcParkedOrderField) Marshal::PtrToStructure(IntPtr(pParkedOrder), CTPCommon::CThostFtdcParkedOrderField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspParkedOrderInsert(cspParkedOrder, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 预埋单录入请求响应
		/// </summary>
		virtual event RspParkedOrderInsert ^OnRspParkedOrderInsert;




	private:
		delegate void cppRspQryBrokerTradingAlgos(KingstarAPI::CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryBrokerTradingAlgos(KingstarAPI::CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcBrokerTradingAlgosField  cspBrokerTradingAlgos = (CTPCommon::CThostFtdcBrokerTradingAlgosField) Marshal::PtrToStructure(IntPtr(pBrokerTradingAlgos), CTPCommon::CThostFtdcBrokerTradingAlgosField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryBrokerTradingAlgos(cspBrokerTradingAlgos, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询经纪公司交易算法响应
		/// </summary>
		virtual event RspQryBrokerTradingAlgos ^OnRspQryBrokerTradingAlgos;




	private:
		delegate void cppRspQryBrokerTradingParams(KingstarAPI::CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryBrokerTradingParams(KingstarAPI::CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcBrokerTradingParamsField  cspBrokerTradingParams = (CTPCommon::CThostFtdcBrokerTradingParamsField) Marshal::PtrToStructure(IntPtr(pBrokerTradingParams), CTPCommon::CThostFtdcBrokerTradingParamsField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryBrokerTradingParams(cspBrokerTradingParams, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询经纪公司交易参数响应
		/// </summary>
		virtual event RspQryBrokerTradingParams ^OnRspQryBrokerTradingParams;




	private:
		delegate void cppRspQryCFMMCTradingAccountKey(KingstarAPI::CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryCFMMCTradingAccountKey(KingstarAPI::CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcCFMMCTradingAccountKeyField  cspCFMMCTradingAccountKey = (CTPCommon::CThostFtdcCFMMCTradingAccountKeyField) Marshal::PtrToStructure(IntPtr(pCFMMCTradingAccountKey), CTPCommon::CThostFtdcCFMMCTradingAccountKeyField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryCFMMCTradingAccountKey(cspCFMMCTradingAccountKey, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应
		/// </summary>
		virtual event RspQryCFMMCTradingAccountKey ^OnRspQryCFMMCTradingAccountKey;




	private:
		delegate void cppRspQryContractBank(KingstarAPI::CThostFtdcContractBankField *pContractBank, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryContractBank(KingstarAPI::CThostFtdcContractBankField *pContractBank, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcContractBankField  cspContractBank = (CTPCommon::CThostFtdcContractBankField) Marshal::PtrToStructure(IntPtr(pContractBank), CTPCommon::CThostFtdcContractBankField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryContractBank(cspContractBank, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询签约银行响应
		/// </summary>
		virtual event RspQryContractBank ^OnRspQryContractBank;




	private:
		delegate void cppRspQryDepthMarketData(KingstarAPI::CThostFtdcDepthMarketDataField *pDepthMarketData, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryDepthMarketData(KingstarAPI::CThostFtdcDepthMarketDataField *pDepthMarketData, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcDepthMarketDataField  cspDepthMarketData = (CTPCommon::CThostFtdcDepthMarketDataField) Marshal::PtrToStructure(IntPtr(pDepthMarketData), CTPCommon::CThostFtdcDepthMarketDataField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryDepthMarketData(cspDepthMarketData, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询行情响应
		/// </summary>
		virtual event RspQryDepthMarketData ^OnRspQryDepthMarketData;




	private:
		delegate void cppRspQryExchange(KingstarAPI::CThostFtdcExchangeField *pExchange, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryExchange(KingstarAPI::CThostFtdcExchangeField *pExchange, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcExchangeField  cspExchange = (CTPCommon::CThostFtdcExchangeField) Marshal::PtrToStructure(IntPtr(pExchange), CTPCommon::CThostFtdcExchangeField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryExchange(cspExchange, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询交易所响应
		/// </summary>
		virtual event RspQryExchange ^OnRspQryExchange;




	private:
		delegate void cppRspQryInstrument(KingstarAPI::CThostFtdcInstrumentField *pInstrument, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryInstrument(KingstarAPI::CThostFtdcInstrumentField *pInstrument, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcInstrumentField  cspInstrument = (CTPCommon::CThostFtdcInstrumentField) Marshal::PtrToStructure(IntPtr(pInstrument), CTPCommon::CThostFtdcInstrumentField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryInstrument(cspInstrument, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询合约响应
		/// </summary>
		virtual event RspQryInstrument ^OnRspQryInstrument;




	private:
		delegate void cppRspQryInstrumentCommissionRate(KingstarAPI::CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryInstrumentCommissionRate(KingstarAPI::CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcInstrumentCommissionRateField  cspInstrumentCommissionRate = (CTPCommon::CThostFtdcInstrumentCommissionRateField) Marshal::PtrToStructure(IntPtr(pInstrumentCommissionRate), CTPCommon::CThostFtdcInstrumentCommissionRateField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryInstrumentCommissionRate(cspInstrumentCommissionRate, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询合约手续费率响应
		/// </summary>
		virtual event RspQryInstrumentCommissionRate ^OnRspQryInstrumentCommissionRate;




	private:
		delegate void cppRspQryInstrumentMarginRate(KingstarAPI::CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryInstrumentMarginRate(KingstarAPI::CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcInstrumentMarginRateField  cspInstrumentMarginRate = (CTPCommon::CThostFtdcInstrumentMarginRateField) Marshal::PtrToStructure(IntPtr(pInstrumentMarginRate), CTPCommon::CThostFtdcInstrumentMarginRateField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryInstrumentMarginRate(cspInstrumentMarginRate, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询合约保证金率响应
		/// </summary>
		virtual event RspQryInstrumentMarginRate ^OnRspQryInstrumentMarginRate;




	private:
		delegate void cppRspQryInvestor(KingstarAPI::CThostFtdcInvestorField *pInvestor, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryInvestor(KingstarAPI::CThostFtdcInvestorField *pInvestor, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcInvestorField  cspInvestor = (CTPCommon::CThostFtdcInvestorField) Marshal::PtrToStructure(IntPtr(pInvestor), CTPCommon::CThostFtdcInvestorField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryInvestor(cspInvestor, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询投资者响应
		/// </summary>
		virtual event RspQryInvestor ^OnRspQryInvestor;




	private:
		delegate void cppRspQryInvestorPosition(KingstarAPI::CThostFtdcInvestorPositionField *pInvestorPosition, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryInvestorPosition(KingstarAPI::CThostFtdcInvestorPositionField *pInvestorPosition, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcInvestorPositionField  cspInvestorPosition = (CTPCommon::CThostFtdcInvestorPositionField) Marshal::PtrToStructure(IntPtr(pInvestorPosition), CTPCommon::CThostFtdcInvestorPositionField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryInvestorPosition(cspInvestorPosition, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询投资者持仓响应
		/// </summary>
		virtual event RspQryInvestorPosition ^OnRspQryInvestorPosition;




	private:
		delegate void cppRspQryInvestorPositionCombineDetail(KingstarAPI::CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryInvestorPositionCombineDetail(KingstarAPI::CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcInvestorPositionCombineDetailField  cspInvestorPositionCombineDetail = (CTPCommon::CThostFtdcInvestorPositionCombineDetailField) Marshal::PtrToStructure(IntPtr(pInvestorPositionCombineDetail), CTPCommon::CThostFtdcInvestorPositionCombineDetailField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryInvestorPositionCombineDetail(cspInvestorPositionCombineDetail, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// </summary>
		virtual event RspQryInvestorPositionCombineDetail ^OnRspQryInvestorPositionCombineDetail;




	private:
		delegate void cppRspQryInvestorPositionDetail(KingstarAPI::CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryInvestorPositionDetail(KingstarAPI::CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{

			CTPTradeApi::CThostFtdcInvestorPositionDetailField field;

			memcpy(field.InstrumentID, pInvestorPositionDetail->InstrumentID, sizeof(field.InstrumentID));

			memcpy(field.BrokerID, pInvestorPositionDetail->BrokerID, sizeof(field.BrokerID));

			memcpy(field.InvestorID, pInvestorPositionDetail->InvestorID, sizeof(field.InvestorID));

			memcpy(&field.HedgeFlag, &pInvestorPositionDetail->HedgeFlag, sizeof(field.HedgeFlag));

			memcpy(&field.Direction, &pInvestorPositionDetail->Direction, sizeof(field.Direction));

			memcpy(field.OpenDate, pInvestorPositionDetail->OpenDate, sizeof(field.OpenDate));

			memcpy(field.TradeID, pInvestorPositionDetail->TradeID, sizeof(field.TradeID));

			memcpy(&field.Volume, &pInvestorPositionDetail->Volume, sizeof(field.Volume));

			memcpy(&field.OpenPrice, &pInvestorPositionDetail->OpenPrice, sizeof(field.OpenPrice));

			memcpy(field.TradingDay, pInvestorPositionDetail->TradingDay, sizeof(field.TradingDay));

			memcpy(&field.SettlementID, &pInvestorPositionDetail->SettlementID, sizeof(field.SettlementID));

			memcpy(&field.TradeType, &pInvestorPositionDetail->TradeType, sizeof(field.TradeType));

			memcpy(field.CombInstrumentID, pInvestorPositionDetail->CombInstrumentID, sizeof(field.CombInstrumentID));

			memcpy(field.ExchangeID, pInvestorPositionDetail->ExchangeID, sizeof(field.ExchangeID));

			memcpy(&field.CloseProfitByDate, &pInvestorPositionDetail->CloseProfitByDate, sizeof(field.CloseProfitByDate));

			memcpy(&field.CloseProfitByTrade, &pInvestorPositionDetail->CloseProfitByTrade, sizeof(field.CloseProfitByTrade));

			memcpy(&field.PositionProfitByDate, &pInvestorPositionDetail->PositionProfitByDate, sizeof(field.PositionProfitByDate));

			memcpy(&field.PositionProfitByTrade, &pInvestorPositionDetail->PositionProfitByTrade, sizeof(field.PositionProfitByTrade));

			memcpy(&field.Margin, &pInvestorPositionDetail->Margin, sizeof(field.Margin));

			memcpy(&field.ExchMargin, &pInvestorPositionDetail->ExchMargin, sizeof(field.ExchMargin));

			memcpy(&field.MarginRateByMoney, &pInvestorPositionDetail->MarginRateByMoney, sizeof(field.MarginRateByMoney));

			memcpy(&field.MarginRateByVolume, &pInvestorPositionDetail->MarginRateByVolume, sizeof(field.MarginRateByVolume));

			memcpy(&field.LastSettlementPrice, &pInvestorPositionDetail->LastSettlementPrice, sizeof(field.LastSettlementPrice));

			memcpy(&field.SettlementPrice, &pInvestorPositionDetail->SettlementPrice, sizeof(field.SettlementPrice));

			memcpy(&field.CloseVolume, &pInvestorPositionDetail->CloseVolume, sizeof(field.CloseVolume));

			memcpy(&field.CloseAmount, &pInvestorPositionDetail->CloseAmount, sizeof(field.CloseAmount));

			CTPCommon::CThostFtdcInvestorPositionDetailField  cspInvestorPositionDetail = (CTPCommon::CThostFtdcInvestorPositionDetailField) Marshal::PtrToStructure(IntPtr(&field), CTPCommon::CThostFtdcInvestorPositionDetailField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryInvestorPositionDetail(cspInvestorPositionDetail, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// </summary>
		virtual event RspQryInvestorPositionDetail ^OnRspQryInvestorPositionDetail;




	private:
		delegate void cppRspQryNotice(KingstarAPI::CThostFtdcNoticeField *pNotice, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryNotice(KingstarAPI::CThostFtdcNoticeField *pNotice, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcNoticeField  cspNotice = (CTPCommon::CThostFtdcNoticeField) Marshal::PtrToStructure(IntPtr(pNotice), CTPCommon::CThostFtdcNoticeField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryNotice(cspNotice, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询客户通知响应
		/// </summary>
		virtual event RspQryNotice ^OnRspQryNotice;




	private:
		delegate void cppRspQryOrder(KingstarAPI::CThostFtdcOrderField *pOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryOrder(KingstarAPI::CThostFtdcOrderField *pOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcOrderField  cspOrder = (CTPCommon::CThostFtdcOrderField) Marshal::PtrToStructure(IntPtr(pOrder), CTPCommon::CThostFtdcOrderField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryOrder(cspOrder, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询报单响应
		/// </summary>
		virtual event RspQryOrder ^OnRspQryOrder;




	private:
		delegate void cppRspQryParkedOrder(KingstarAPI::CThostFtdcParkedOrderField *pParkedOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryParkedOrder(KingstarAPI::CThostFtdcParkedOrderField *pParkedOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcParkedOrderField  cspParkedOrder = (CTPCommon::CThostFtdcParkedOrderField) Marshal::PtrToStructure(IntPtr(pParkedOrder), CTPCommon::CThostFtdcParkedOrderField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryParkedOrder(cspParkedOrder, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询预埋单响应
		/// </summary>
		virtual event RspQryParkedOrder ^OnRspQryParkedOrder;




	private:
		delegate void cppRspQryParkedOrderAction(KingstarAPI::CThostFtdcParkedOrderActionField *pParkedOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryParkedOrderAction(KingstarAPI::CThostFtdcParkedOrderActionField *pParkedOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcParkedOrderActionField  cspParkedOrderAction = (CTPCommon::CThostFtdcParkedOrderActionField) Marshal::PtrToStructure(IntPtr(pParkedOrderAction), CTPCommon::CThostFtdcParkedOrderActionField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryParkedOrderAction(cspParkedOrderAction, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询预埋撤单响应
		/// </summary>
		virtual event RspQryParkedOrderAction ^OnRspQryParkedOrderAction;




	private:
		delegate void cppRspQrySettlementInfo(KingstarAPI::CThostFtdcSettlementInfoField *pSettlementInfo, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQrySettlementInfo(KingstarAPI::CThostFtdcSettlementInfoField *pSettlementInfo, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcSettlementInfoField  cspSettlementInfo = (CTPCommon::CThostFtdcSettlementInfoField) Marshal::PtrToStructure(IntPtr(pSettlementInfo), CTPCommon::CThostFtdcSettlementInfoField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQrySettlementInfo(cspSettlementInfo, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询投资者结算结果响应
		/// </summary>
		virtual event RspQrySettlementInfo ^OnRspQrySettlementInfo;




	private:
		delegate void cppRspQrySettlementInfoConfirm(KingstarAPI::CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQrySettlementInfoConfirm(KingstarAPI::CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcSettlementInfoConfirmField  cspSettlementInfoConfirm = (CTPCommon::CThostFtdcSettlementInfoConfirmField) Marshal::PtrToStructure(IntPtr(pSettlementInfoConfirm), CTPCommon::CThostFtdcSettlementInfoConfirmField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQrySettlementInfoConfirm(cspSettlementInfoConfirm, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询结算信息确认响应
		/// </summary>
		virtual event RspQrySettlementInfoConfirm ^OnRspQrySettlementInfoConfirm;




	private:
		delegate void cppRspQryTrade(KingstarAPI::CThostFtdcTradeField *pTrade, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryTrade(KingstarAPI::CThostFtdcTradeField *pTrade, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcTradeField  cspTrade = (CTPCommon::CThostFtdcTradeField) Marshal::PtrToStructure(IntPtr(pTrade), CTPCommon::CThostFtdcTradeField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryTrade(cspTrade, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询成交响应
		/// </summary>
		virtual event RspQryTrade ^OnRspQryTrade;




	private:
		delegate void cppRspQryTradingAccount(KingstarAPI::CThostFtdcTradingAccountField *pTradingAccount, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryTradingAccount(KingstarAPI::CThostFtdcTradingAccountField *pTradingAccount, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcTradingAccountField  cspTradingAccount = (CTPCommon::CThostFtdcTradingAccountField) Marshal::PtrToStructure(IntPtr(pTradingAccount), CTPCommon::CThostFtdcTradingAccountField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryTradingAccount(cspTradingAccount, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询资金账户响应
		/// </summary>
		virtual event RspQryTradingAccount ^OnRspQryTradingAccount;




	private:
		delegate void cppRspQryTradingCode(KingstarAPI::CThostFtdcTradingCodeField *pTradingCode, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryTradingCode(KingstarAPI::CThostFtdcTradingCodeField *pTradingCode, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcTradingCodeField  cspTradingCode = (CTPCommon::CThostFtdcTradingCodeField) Marshal::PtrToStructure(IntPtr(pTradingCode), CTPCommon::CThostFtdcTradingCodeField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryTradingCode(cspTradingCode, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询交易编码响应
		/// </summary>
		virtual event RspQryTradingCode ^OnRspQryTradingCode;




	private:
		delegate void cppRspQryTradingNotice(KingstarAPI::CThostFtdcTradingNoticeField *pTradingNotice, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryTradingNotice(KingstarAPI::CThostFtdcTradingNoticeField *pTradingNotice, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcTradingNoticeField  cspTradingNotice = (CTPCommon::CThostFtdcTradingNoticeField) Marshal::PtrToStructure(IntPtr(pTradingNotice), CTPCommon::CThostFtdcTradingNoticeField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryTradingNotice(cspTradingNotice, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询交易通知响应
		/// </summary>
		virtual event RspQryTradingNotice ^OnRspQryTradingNotice;




	private:
		delegate void cppRspQryTransferBank(KingstarAPI::CThostFtdcTransferBankField *pTransferBank, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryTransferBank(KingstarAPI::CThostFtdcTransferBankField *pTransferBank, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcTransferBankField  cspTransferBank = (CTPCommon::CThostFtdcTransferBankField) Marshal::PtrToStructure(IntPtr(pTransferBank), CTPCommon::CThostFtdcTransferBankField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryTransferBank(cspTransferBank, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询转帐银行响应
		/// </summary>
		virtual event RspQryTransferBank ^OnRspQryTransferBank;




	private:
		delegate void cppRspQryTransferSerial(KingstarAPI::CThostFtdcTransferSerialField *pTransferSerial, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryTransferSerial(KingstarAPI::CThostFtdcTransferSerialField *pTransferSerial, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcTransferSerialField  cspTransferSerial = (CTPCommon::CThostFtdcTransferSerialField) Marshal::PtrToStructure(IntPtr(pTransferSerial), CTPCommon::CThostFtdcTransferSerialField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryTransferSerial(cspTransferSerial, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询转帐流水响应
		/// </summary>
		virtual event RspQryTransferSerial ^OnRspQryTransferSerial;




	private:
		delegate void cppRspQryAccountregister(KingstarAPI::CThostFtdcAccountregisterField *pAccountregister, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQryAccountregister(KingstarAPI::CThostFtdcAccountregisterField *pAccountregister, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcAccountregisterField  cspAccountregister = (CTPCommon::CThostFtdcAccountregisterField) Marshal::PtrToStructure(IntPtr(pAccountregister), CTPCommon::CThostFtdcAccountregisterField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQryAccountregister(cspAccountregister, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 请求查询转帐流水响应
		/// </summary>
		virtual event RspQryAccountregister ^OnRspQryAccountregister;




	private:
		delegate void cppRspQueryBankAccountMoneyByFuture(KingstarAPI::CThostFtdcReqQueryAccountField *pReqQueryAccount, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQueryBankAccountMoneyByFuture(KingstarAPI::CThostFtdcReqQueryAccountField *pReqQueryAccount, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcReqQueryAccountField  cspReqQueryAccount = (CTPCommon::CThostFtdcReqQueryAccountField) Marshal::PtrToStructure(IntPtr(pReqQueryAccount), CTPCommon::CThostFtdcReqQueryAccountField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQueryBankAccountMoneyByFuture(cspReqQueryAccount, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 期货发起查询银行余额应答
		/// </summary>
		virtual event RspQueryBankAccountMoneyByFuture ^OnRspQueryBankAccountMoneyByFuture;




	private:
		delegate void cppRspQueryMaxOrderVolume(KingstarAPI::CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspQueryMaxOrderVolume(KingstarAPI::CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcQueryMaxOrderVolumeField  cspQueryMaxOrderVolume = (CTPCommon::CThostFtdcQueryMaxOrderVolumeField) Marshal::PtrToStructure(IntPtr(pQueryMaxOrderVolume), CTPCommon::CThostFtdcQueryMaxOrderVolumeField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspQueryMaxOrderVolume(cspQueryMaxOrderVolume, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 查询最大报单数量响应
		/// </summary>
		virtual event RspQueryMaxOrderVolume ^OnRspQueryMaxOrderVolume;




	private:
		delegate void cppRspRemoveParkedOrder(KingstarAPI::CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspRemoveParkedOrder(KingstarAPI::CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcRemoveParkedOrderField  cspRemoveParkedOrder = (CTPCommon::CThostFtdcRemoveParkedOrderField) Marshal::PtrToStructure(IntPtr(pRemoveParkedOrder), CTPCommon::CThostFtdcRemoveParkedOrderField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspRemoveParkedOrder(cspRemoveParkedOrder, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 删除预埋单响应
		/// </summary>
		virtual event RspRemoveParkedOrder ^OnRspRemoveParkedOrder;




	private:
		delegate void cppRspRemoveParkedOrderAction(KingstarAPI::CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspRemoveParkedOrderAction(KingstarAPI::CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcRemoveParkedOrderActionField  cspRemoveParkedOrderAction = (CTPCommon::CThostFtdcRemoveParkedOrderActionField) Marshal::PtrToStructure(IntPtr(pRemoveParkedOrderAction), CTPCommon::CThostFtdcRemoveParkedOrderActionField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspRemoveParkedOrderAction(cspRemoveParkedOrderAction, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 删除预埋撤单响应
		/// </summary>
		virtual event RspRemoveParkedOrderAction ^OnRspRemoveParkedOrderAction;




	private:
		delegate void cppRspSettlementInfoConfirm(KingstarAPI::CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspSettlementInfoConfirm(KingstarAPI::CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcSettlementInfoConfirmField  cspSettlementInfoConfirm = (CTPCommon::CThostFtdcSettlementInfoConfirmField) Marshal::PtrToStructure(IntPtr(pSettlementInfoConfirm), CTPCommon::CThostFtdcSettlementInfoConfirmField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspSettlementInfoConfirm(cspSettlementInfoConfirm, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 投资者结算结果确认响应
		/// </summary>
		virtual event RspSettlementInfoConfirm ^OnRspSettlementInfoConfirm;




	private:
		delegate void cppRspTradingAccountPasswordUpdate(KingstarAPI::CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspTradingAccountPasswordUpdate(KingstarAPI::CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcTradingAccountPasswordUpdateField  cspTradingAccountPasswordUpdate = (CTPCommon::CThostFtdcTradingAccountPasswordUpdateField) Marshal::PtrToStructure(IntPtr(pTradingAccountPasswordUpdate), CTPCommon::CThostFtdcTradingAccountPasswordUpdateField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspTradingAccountPasswordUpdate(cspTradingAccountPasswordUpdate, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 资金账户口令更新请求响应
		/// </summary>
		virtual event RspTradingAccountPasswordUpdate ^OnRspTradingAccountPasswordUpdate;






	private:
		delegate void cppRspAuthenticate(KingstarAPI::CThostFtdcRspAuthenticateField *pRspAuthenticateField, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspAuthenticate(KingstarAPI::CThostFtdcRspAuthenticateField *pRspAuthenticateField, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcRspAuthenticateField  cspRspAuthenticate = (CTPCommon::CThostFtdcRspAuthenticateField) Marshal::PtrToStructure(IntPtr(pRspAuthenticateField), CTPCommon::CThostFtdcRspUserLoginField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspAuthenticate(cspRspAuthenticate, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>

		/// 
		/// </summary>
		virtual event RspAuthenticate ^OnRspAuthenticate;




	private:
		delegate void cppRspUserLogin(KingstarAPI::CThostFtdcRspUserLoginField *pRspUserLogin, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspUserLogin(KingstarAPI::CThostFtdcRspUserLoginField *pRspUserLogin, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcRspUserLoginField  cspRspUserLogin = (CTPCommon::CThostFtdcRspUserLoginField) Marshal::PtrToStructure(IntPtr(pRspUserLogin), CTPCommon::CThostFtdcRspUserLoginField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			FrontID = cspRspUserLogin.FrontID;
			SessionID = cspRspUserLogin.SessionID;
			OnRspUserLogin(cspRspUserLogin, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 登录请求响应
		/// </summary>
		virtual event RspUserLogin ^OnRspUserLogin;




	private:
		delegate void cppRspUserLogout(KingstarAPI::CThostFtdcUserLogoutField *pUserLogout, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspUserLogout(KingstarAPI::CThostFtdcUserLogoutField *pUserLogout, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcUserLogoutField  cspUserLogout = (CTPCommon::CThostFtdcUserLogoutField) Marshal::PtrToStructure(IntPtr(pUserLogout), CTPCommon::CThostFtdcUserLogoutField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspUserLogout(cspUserLogout, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 登出请求响应
		/// </summary>
		virtual event RspUserLogout ^OnRspUserLogout;




	private:
		delegate void cppRspUserPasswordUpdate(KingstarAPI::CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
		void cppcbRspUserPasswordUpdate(KingstarAPI::CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, KingstarAPI::CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
		{
			CTPCommon::CThostFtdcUserPasswordUpdateField  cspUserPasswordUpdate = (CTPCommon::CThostFtdcUserPasswordUpdateField) Marshal::PtrToStructure(IntPtr(pUserPasswordUpdate), CTPCommon::CThostFtdcUserPasswordUpdateField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
			OnRspUserPasswordUpdate(cspUserPasswordUpdate, cspRspInfo, nRequestID, bIsLast);
		}
	public:
		/// <summary>
		/// 用户口令更新请求响应
		/// </summary>
		virtual event RspUserPasswordUpdate ^OnRspUserPasswordUpdate;




	private:
		delegate void cppRtnErrorConditionalOrder(KingstarAPI::CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
		void cppcbRtnErrorConditionalOrder(KingstarAPI::CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder)
		{
			CTPCommon::CThostFtdcErrorConditionalOrderField  cspErrorConditionalOrder = (CTPCommon::CThostFtdcErrorConditionalOrderField) Marshal::PtrToStructure(IntPtr(pErrorConditionalOrder), CTPCommon::CThostFtdcErrorConditionalOrderField::typeid);
			OnRtnErrorConditionalOrder(cspErrorConditionalOrder);
		}
	public:
		/// <summary>
		/// 提示条件单校验错误
		/// </summary>
		virtual event RtnErrorConditionalOrder ^OnRtnErrorConditionalOrder;




	private:
		delegate void cppRtnFromBankToFutureByBank(KingstarAPI::CThostFtdcRspTransferField *pRspTransfer);
		void cppcbRtnFromBankToFutureByBank(KingstarAPI::CThostFtdcRspTransferField *pRspTransfer)
		{
			CTPCommon::CThostFtdcRspTransferField  cspRspTransfer = (CTPCommon::CThostFtdcRspTransferField) Marshal::PtrToStructure(IntPtr(pRspTransfer), CTPCommon::CThostFtdcRspTransferField::typeid);
			OnRtnFromBankToFutureByBank(cspRspTransfer);
		}
	public:
		/// <summary>
		/// 银行发起银行资金转期货通知
		/// </summary>
		virtual event RtnFromBankToFutureByBank ^OnRtnFromBankToFutureByBank;




	private:
		delegate void cppRtnFromBankToFutureByFuture(KingstarAPI::CThostFtdcRspTransferField *pRspTransfer);
		void cppcbRtnFromBankToFutureByFuture(KingstarAPI::CThostFtdcRspTransferField *pRspTransfer)
		{
			CTPCommon::CThostFtdcRspTransferField  cspRspTransfer = (CTPCommon::CThostFtdcRspTransferField) Marshal::PtrToStructure(IntPtr(pRspTransfer), CTPCommon::CThostFtdcRspTransferField::typeid);
			OnRtnFromBankToFutureByFuture(cspRspTransfer);
		}
	public:
		/// <summary>
		/// 期货发起银行资金转期货通知
		/// </summary>
		virtual event RtnFromBankToFutureByFuture ^OnRtnFromBankToFutureByFuture;




	private:
		delegate void cppRtnFromFutureToBankByBank(KingstarAPI::CThostFtdcRspTransferField *pRspTransfer);
		void cppcbRtnFromFutureToBankByBank(KingstarAPI::CThostFtdcRspTransferField *pRspTransfer)
		{
			CTPCommon::CThostFtdcRspTransferField  cspRspTransfer = (CTPCommon::CThostFtdcRspTransferField) Marshal::PtrToStructure(IntPtr(pRspTransfer), CTPCommon::CThostFtdcRspTransferField::typeid);
			OnRtnFromFutureToBankByBank(cspRspTransfer);
		}
	public:
		/// <summary>
		/// 银行发起期货资金转银行通知
		/// </summary>
		virtual event RtnFromFutureToBankByBank ^OnRtnFromFutureToBankByBank;




	private:
		delegate void cppRtnFromFutureToBankByFuture(KingstarAPI::CThostFtdcRspTransferField *pRspTransfer);
		void cppcbRtnFromFutureToBankByFuture(KingstarAPI::CThostFtdcRspTransferField *pRspTransfer)
		{
			CTPCommon::CThostFtdcRspTransferField  cspRspTransfer = (CTPCommon::CThostFtdcRspTransferField) Marshal::PtrToStructure(IntPtr(pRspTransfer), CTPCommon::CThostFtdcRspTransferField::typeid);
			OnRtnFromFutureToBankByFuture(cspRspTransfer);
		}
	public:
		/// <summary>
		/// 期货发起期货资金转银行通知
		/// </summary>
		virtual event RtnFromFutureToBankByFuture ^OnRtnFromFutureToBankByFuture;




	private:
		delegate void cppRtnInstrumentStatus(KingstarAPI::CThostFtdcInstrumentStatusField *pInstrumentStatus);
		void cppcbRtnInstrumentStatus(KingstarAPI::CThostFtdcInstrumentStatusField *pInstrumentStatus)
		{
			CTPCommon::CThostFtdcInstrumentStatusField  cspInstrumentStatus = (CTPCommon::CThostFtdcInstrumentStatusField) Marshal::PtrToStructure(IntPtr(pInstrumentStatus), CTPCommon::CThostFtdcInstrumentStatusField::typeid);
			OnRtnInstrumentStatus(cspInstrumentStatus);
		}
	public:
		/// <summary>
		/// 合约交易状态通知
		/// </summary>
		virtual event RtnInstrumentStatus ^OnRtnInstrumentStatus;




	private:
		delegate void cppRtnOrder(KingstarAPI::CThostFtdcOrderField *pOrder);
		void cppcbRtnOrder(KingstarAPI::CThostFtdcOrderField *pOrder)
		{
			CTPCommon::CThostFtdcOrderField  cspOrder = (CTPCommon::CThostFtdcOrderField) Marshal::PtrToStructure(IntPtr(pOrder), CTPCommon::CThostFtdcOrderField::typeid);
			OnRtnOrder(cspOrder);
		}
	public:
		/// <summary>
		/// 报单通知
		/// </summary>
		virtual event RtnOrder ^OnRtnOrder;




	private:
		delegate void cppRtnQueryBankBalanceByFuture(KingstarAPI::CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
		void cppcbRtnQueryBankBalanceByFuture(KingstarAPI::CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
		{
			CTPCommon::CThostFtdcNotifyQueryAccountField  cspNotifyQueryAccount = (CTPCommon::CThostFtdcNotifyQueryAccountField) Marshal::PtrToStructure(IntPtr(pNotifyQueryAccount), CTPCommon::CThostFtdcNotifyQueryAccountField::typeid);
			OnRtnQueryBankBalanceByFuture(cspNotifyQueryAccount);
		}
	public:
		/// <summary>
		/// 期货发起查询银行余额通知
		/// </summary>
		virtual event RtnQueryBankBalanceByFuture ^OnRtnQueryBankBalanceByFuture;




	private:
		delegate void cppRtnRepealFromBankToFutureByBank(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal);
		void cppcbRtnRepealFromBankToFutureByBank(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal)
		{
			CTPCommon::CThostFtdcRspRepealField  cspRspRepeal = (CTPCommon::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPCommon::CThostFtdcRspRepealField::typeid);
			OnRtnRepealFromBankToFutureByBank(cspRspRepeal);
		}
	public:
		/// <summary>
		/// 银行发起冲正银行转期货通知
		/// </summary>
		virtual event RtnRepealFromBankToFutureByBank ^OnRtnRepealFromBankToFutureByBank;




	private:
		delegate void cppRtnRepealFromBankToFutureByFuture(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal);
		void cppcbRtnRepealFromBankToFutureByFuture(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal)
		{
			CTPCommon::CThostFtdcRspRepealField  cspRspRepeal = (CTPCommon::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPCommon::CThostFtdcRspRepealField::typeid);
			OnRtnRepealFromBankToFutureByFuture(cspRspRepeal);
		}
	public:
		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// </summary>
		virtual event RtnRepealFromBankToFutureByFuture ^OnRtnRepealFromBankToFutureByFuture;




	private:
		delegate void cppRtnRepealFromBankToFutureByFutureManual(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal);
		void cppcbRtnRepealFromBankToFutureByFutureManual(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal)
		{
			CTPCommon::CThostFtdcRspRepealField  cspRspRepeal = (CTPCommon::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPCommon::CThostFtdcRspRepealField::typeid);
			OnRtnRepealFromBankToFutureByFutureManual(cspRspRepeal);
		}
	public:
		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// </summary>
		virtual event RtnRepealFromBankToFutureByFutureManual ^OnRtnRepealFromBankToFutureByFutureManual;




	private:
		delegate void cppRtnRepealFromFutureToBankByBank(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal);
		void cppcbRtnRepealFromFutureToBankByBank(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal)
		{
			CTPCommon::CThostFtdcRspRepealField  cspRspRepeal = (CTPCommon::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPCommon::CThostFtdcRspRepealField::typeid);
			OnRtnRepealFromFutureToBankByBank(cspRspRepeal);
		}
	public:
		/// <summary>
		/// 银行发起冲正期货转银行通知
		/// </summary>
		virtual event RtnRepealFromFutureToBankByBank ^OnRtnRepealFromFutureToBankByBank;




	private:
		delegate void cppRtnRepealFromFutureToBankByFuture(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal);
		void cppcbRtnRepealFromFutureToBankByFuture(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal)
		{
			CTPCommon::CThostFtdcRspRepealField  cspRspRepeal = (CTPCommon::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPCommon::CThostFtdcRspRepealField::typeid);
			OnRtnRepealFromFutureToBankByFuture(cspRspRepeal);
		}
	public:
		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// </summary>
		virtual event RtnRepealFromFutureToBankByFuture ^OnRtnRepealFromFutureToBankByFuture;




	private:
		delegate void cppRtnRepealFromFutureToBankByFutureManual(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal);
		void cppcbRtnRepealFromFutureToBankByFutureManual(KingstarAPI::CThostFtdcRspRepealField *pRspRepeal)
		{
			CTPCommon::CThostFtdcRspRepealField  cspRspRepeal = (CTPCommon::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPCommon::CThostFtdcRspRepealField::typeid);
			OnRtnRepealFromFutureToBankByFutureManual(cspRspRepeal);
		}
	public:
		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// </summary>
		virtual event RtnRepealFromFutureToBankByFutureManual ^OnRtnRepealFromFutureToBankByFutureManual;




	private:
		delegate void cppRtnTrade(KingstarAPI::CThostFtdcTradeField *pTrade);
		void cppcbRtnTrade(KingstarAPI::CThostFtdcTradeField *pTrade)
		{
			CTPCommon::CThostFtdcTradeField  cspTrade = (CTPCommon::CThostFtdcTradeField) Marshal::PtrToStructure(IntPtr(pTrade), CTPCommon::CThostFtdcTradeField::typeid);
			OnRtnTrade(cspTrade);
		}
	public:
		/// <summary>
		/// 成交通知
		/// </summary>
		virtual event RtnTrade ^OnRtnTrade;




	private:
		delegate void cppRtnTradingNotice(KingstarAPI::CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
		void cppcbRtnTradingNotice(KingstarAPI::CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo)
		{
			CTPCommon::CThostFtdcTradingNoticeInfoField  cspTradingNoticeInfo = (CTPCommon::CThostFtdcTradingNoticeInfoField) Marshal::PtrToStructure(IntPtr(pTradingNoticeInfo), CTPCommon::CThostFtdcTradingNoticeInfoField::typeid);
			OnRtnTradingNotice(cspTradingNoticeInfo);
		}
	public:
		/// <summary>
		/// 交易通知
		/// </summary>
		virtual event RtnTradingNotice ^OnRtnTradingNotice;






	private:
		KSTraderSpi *pUserSpi = nullptr;
		KingstarAPI::CThostFtdcTraderApi * pUserApi = nullptr;
		int lRequestID = 0;
	};

}
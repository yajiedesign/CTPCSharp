#include "stdafx.h"
#include "TradeApi.h"
#include <string>


using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;


public ref class TradeApiclr
{
private:

	System::Collections::Generic::List<GCHandle> ^ gchlist = gcnew 	System::Collections::Generic::List<GCHandle>();

	std::string MarshalString(String ^ s ) {
		using namespace Runtime::InteropServices;
		const char* chars =
			(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
		std::string os = chars;
		Marshal::FreeHGlobal(IntPtr((void*)chars));
		return os;
	}

	
public:


	TradeApiclr(System::String ^_investor, System::String ^_pwd, System::String ^_broker ,
		System::String ^_addr , System::String ^_FlowPath)
	{
		FrontAddr = _addr;
		BrokerID = _broker;
		InvestorID = _investor;
		passWord = _pwd;
		FlowPath = _FlowPath;

		pUserApi = CThostFtdcTraderApi::CreateFtdcTraderApi(MarshalString(_FlowPath).c_str());			// 创建UserApi
		pUserSpi = new CTraderSpi();
		pUserApi->RegisterSpi((CThostFtdcTraderSpi*)pUserSpi);			// 注册事件类
		pUserApi->SubscribePublicTopic(THOST_TERT_QUICK/*THOST_TERT_RESTART*/);					// 注册公有流
		pUserApi->SubscribePrivateTopic(THOST_TERT_QUICK/*THOST_TERT_RESTART*/);					// 注册私有流
		pUserApi->RegisterFront((char*)MarshalString(_addr).c_str());							// connect
		EventInit();
		pUserApi->Init();
	}
	
	virtual ~TradeApiclr(){

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
	/// 经纪公司代码
	/// </summary>
	property  System::String ^ BrokerID;
	/// <summary>
	/// 投资者代码
	/// </summary>
	property  System::String ^ InvestorID;
	property  System::String ^ passWord;
	property  System::String ^ FlowPath;

	/// <summary>
	/// 前置编号
	/// </summary>
	property int FrontID;

	/// <summary>
	/// 会话编号
	/// </summary>
	property int SessionID;

	/// <summary>
	/// 最大报单引用
	/// </summary>
	property int MaxOrderRef;


	//投资者结算结果确认
	int SettlementInfoConfirm([Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		CThostFtdcSettlementInfoConfirmField req;
		memset(&req, 0, sizeof(req));
		strcpy_s(req.BrokerID, MarshalString(BrokerID).c_str());
		strcpy_s(req.InvestorID, MarshalString(InvestorID).c_str());
		return pUserApi->ReqSettlementInfoConfirm(&req, nRequestID);
	}

	/// <summary>
	///报单录入请求
	/// </summary>
	int ReqOrderInsert(CTPTradeApi::CThostFtdcInputOrderField pInputOrder, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		pInputOrder.RequestID = nRequestID;
		int size = Marshal::SizeOf(pInputOrder);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pInputOrder, bufferIntPtr, false);
			CThostFtdcInputOrderField* temp = static_cast<CThostFtdcInputOrderField*>(bufferIntPtr.ToPointer());
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
	int ReqOrderAction(CTPTradeApi::CThostFtdcInputOrderActionField pInputOrderAction, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		pInputOrderAction.RequestID = nRequestID;
		int size = Marshal::SizeOf(pInputOrderAction);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pInputOrderAction, bufferIntPtr, false);
			CThostFtdcInputOrderActionField* temp = static_cast<CThostFtdcInputOrderActionField*>(bufferIntPtr.ToPointer());
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
	int ReqAuthenticate(CTPTradeApi::CThostFtdcReqAuthenticateField pReqAuthenticateField, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pReqAuthenticateField);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pReqAuthenticateField, bufferIntPtr, false);
			CThostFtdcReqAuthenticateField* temp = static_cast<CThostFtdcReqAuthenticateField*>(bufferIntPtr.ToPointer());
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
	int ReqUserLogin(CTPTradeApi::CThostFtdcReqUserLoginField pReqUserLoginField, [Out]  int %nRequestID)
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
	int ReqUserLogout(CTPTradeApi::CThostFtdcUserLogoutField pUserLogout, [Out]  int %nRequestID)
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

	/// <summary>
	///用户口令更新请求
	/// </summary>
	int ReqUserPasswordUpdate(CTPTradeApi::CThostFtdcUserPasswordUpdateField pUserPasswordUpdate, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pUserPasswordUpdate);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pUserPasswordUpdate, bufferIntPtr, false);
			CThostFtdcUserPasswordUpdateField* temp = static_cast<CThostFtdcUserPasswordUpdateField*>(bufferIntPtr.ToPointer());
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
	int ReqTradingAccountPasswordUpdate(CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateField pTradingAccountPasswordUpdate, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pTradingAccountPasswordUpdate);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pTradingAccountPasswordUpdate, bufferIntPtr, false);
			CThostFtdcTradingAccountPasswordUpdateField* temp = static_cast<CThostFtdcTradingAccountPasswordUpdateField*>(bufferIntPtr.ToPointer());
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
	int ReqParkedOrderInsert(CTPTradeApi::CThostFtdcParkedOrderField pParkedOrder, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pParkedOrder);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pParkedOrder, bufferIntPtr, false);
			CThostFtdcParkedOrderField* temp = static_cast<CThostFtdcParkedOrderField*>(bufferIntPtr.ToPointer());
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
	int ReqParkedOrderAction(CTPTradeApi::CThostFtdcParkedOrderActionField pParkedOrderAction, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pParkedOrderAction);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pParkedOrderAction, bufferIntPtr, false);
			CThostFtdcParkedOrderActionField* temp = static_cast<CThostFtdcParkedOrderActionField*>(bufferIntPtr.ToPointer());
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
	int ReqQueryMaxOrderVolume(CTPTradeApi::CThostFtdcQueryMaxOrderVolumeField pQueryMaxOrderVolume, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQueryMaxOrderVolume);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQueryMaxOrderVolume, bufferIntPtr, false);
			CThostFtdcQueryMaxOrderVolumeField* temp = static_cast<CThostFtdcQueryMaxOrderVolumeField*>(bufferIntPtr.ToPointer());
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
	int ReqSettlementInfoConfirm(CTPTradeApi::CThostFtdcSettlementInfoConfirmField pSettlementInfoConfirm, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pSettlementInfoConfirm);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pSettlementInfoConfirm, bufferIntPtr, false);
			CThostFtdcSettlementInfoConfirmField* temp = static_cast<CThostFtdcSettlementInfoConfirmField*>(bufferIntPtr.ToPointer());
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
	int ReqRemoveParkedOrder(CTPTradeApi::CThostFtdcRemoveParkedOrderField pRemoveParkedOrder, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pRemoveParkedOrder);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pRemoveParkedOrder, bufferIntPtr, false);
			CThostFtdcRemoveParkedOrderField* temp = static_cast<CThostFtdcRemoveParkedOrderField*>(bufferIntPtr.ToPointer());
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
	int ReqRemoveParkedOrderAction(CTPTradeApi::CThostFtdcRemoveParkedOrderActionField pRemoveParkedOrderAction, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pRemoveParkedOrderAction);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pRemoveParkedOrderAction, bufferIntPtr, false);
			CThostFtdcRemoveParkedOrderActionField* temp = static_cast<CThostFtdcRemoveParkedOrderActionField*>(bufferIntPtr.ToPointer());
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
	int ReqQryOrder(CTPTradeApi::CThostFtdcQryOrderField pQryOrder, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryOrder);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryOrder, bufferIntPtr, false);
			CThostFtdcQryOrderField* temp = static_cast<CThostFtdcQryOrderField*>(bufferIntPtr.ToPointer());
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
	int ReqQryTrade(CTPTradeApi::CThostFtdcQryTradeField pQryTrade, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryTrade);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryTrade, bufferIntPtr, false);
			CThostFtdcQryTradeField* temp = static_cast<CThostFtdcQryTradeField*>(bufferIntPtr.ToPointer());
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
	int ReqQryInvestorPosition(CTPTradeApi::CThostFtdcQryInvestorPositionField pQryInvestorPosition, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryInvestorPosition);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryInvestorPosition, bufferIntPtr, false);
			CThostFtdcQryInvestorPositionField* temp = static_cast<CThostFtdcQryInvestorPositionField*>(bufferIntPtr.ToPointer());
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
	int ReqQryTradingAccount(CTPTradeApi::CThostFtdcQryTradingAccountField pQryTradingAccount, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryTradingAccount);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryTradingAccount, bufferIntPtr, false);
			CThostFtdcQryTradingAccountField* temp = static_cast<CThostFtdcQryTradingAccountField*>(bufferIntPtr.ToPointer());
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
	int ReqQryInvestor(CTPTradeApi::CThostFtdcQryInvestorField pQryInvestor, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryInvestor);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryInvestor, bufferIntPtr, false);
			CThostFtdcQryInvestorField* temp = static_cast<CThostFtdcQryInvestorField*>(bufferIntPtr.ToPointer());
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
	int ReqQryTradingCode(CTPTradeApi::CThostFtdcQryTradingCodeField pQryTradingCode, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryTradingCode);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryTradingCode, bufferIntPtr, false);
			CThostFtdcQryTradingCodeField* temp = static_cast<CThostFtdcQryTradingCodeField*>(bufferIntPtr.ToPointer());
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
	int ReqQryInstrumentMarginRate(CTPTradeApi::CThostFtdcQryInstrumentMarginRateField pQryInstrumentMarginRate, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryInstrumentMarginRate);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryInstrumentMarginRate, bufferIntPtr, false);
			CThostFtdcQryInstrumentMarginRateField* temp = static_cast<CThostFtdcQryInstrumentMarginRateField*>(bufferIntPtr.ToPointer());
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
	int ReqQryInstrumentCommissionRate(CTPTradeApi::CThostFtdcQryInstrumentCommissionRateField pQryInstrumentCommissionRate, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryInstrumentCommissionRate);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryInstrumentCommissionRate, bufferIntPtr, false);
			CThostFtdcQryInstrumentCommissionRateField* temp = static_cast<CThostFtdcQryInstrumentCommissionRateField*>(bufferIntPtr.ToPointer());
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
	int ReqQryExchange(CTPTradeApi::CThostFtdcQryExchangeField pQryExchange, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryExchange);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryExchange, bufferIntPtr, false);
			CThostFtdcQryExchangeField* temp = static_cast<CThostFtdcQryExchangeField*>(bufferIntPtr.ToPointer());
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
	int ReqQryInstrument(CTPTradeApi::CThostFtdcQryInstrumentField pQryInstrument, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryInstrument);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryInstrument, bufferIntPtr, false);
			CThostFtdcQryInstrumentField* temp = static_cast<CThostFtdcQryInstrumentField*>(bufferIntPtr.ToPointer());
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
	int ReqQryDepthMarketData(CTPTradeApi::CThostFtdcQryDepthMarketDataField pQryDepthMarketData, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryDepthMarketData);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryDepthMarketData, bufferIntPtr, false);
			CThostFtdcQryDepthMarketDataField* temp = static_cast<CThostFtdcQryDepthMarketDataField*>(bufferIntPtr.ToPointer());
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
	int ReqQrySettlementInfo(CTPTradeApi::CThostFtdcQrySettlementInfoField pQrySettlementInfo, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQrySettlementInfo);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQrySettlementInfo, bufferIntPtr, false);
			CThostFtdcQrySettlementInfoField* temp = static_cast<CThostFtdcQrySettlementInfoField*>(bufferIntPtr.ToPointer());
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
	int ReqQryTransferBank(CTPTradeApi::CThostFtdcQryTransferBankField pQryTransferBank, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryTransferBank);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryTransferBank, bufferIntPtr, false);
			CThostFtdcQryTransferBankField* temp = static_cast<CThostFtdcQryTransferBankField*>(bufferIntPtr.ToPointer());
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
	int ReqQryInvestorPositionDetail(CTPTradeApi::CThostFtdcQryInvestorPositionDetailField pQryInvestorPositionDetail, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryInvestorPositionDetail);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryInvestorPositionDetail, bufferIntPtr, false);
			CThostFtdcQryInvestorPositionDetailField* temp = static_cast<CThostFtdcQryInvestorPositionDetailField*>(bufferIntPtr.ToPointer());
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
	int ReqQryNotice(CTPTradeApi::CThostFtdcQryNoticeField pQryNotice, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryNotice);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryNotice, bufferIntPtr, false);
			CThostFtdcQryNoticeField* temp = static_cast<CThostFtdcQryNoticeField*>(bufferIntPtr.ToPointer());
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
	int ReqQrySettlementInfoConfirm(CTPTradeApi::CThostFtdcQrySettlementInfoConfirmField pQrySettlementInfoConfirm, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQrySettlementInfoConfirm);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQrySettlementInfoConfirm, bufferIntPtr, false);
			CThostFtdcQrySettlementInfoConfirmField* temp = static_cast<CThostFtdcQrySettlementInfoConfirmField*>(bufferIntPtr.ToPointer());
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
	int ReqQryInvestorPositionCombineDetail(CTPTradeApi::CThostFtdcQryInvestorPositionCombineDetailField pQryInvestorPositionCombineDetail, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryInvestorPositionCombineDetail);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryInvestorPositionCombineDetail, bufferIntPtr, false);
			CThostFtdcQryInvestorPositionCombineDetailField* temp = static_cast<CThostFtdcQryInvestorPositionCombineDetailField*>(bufferIntPtr.ToPointer());
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
	int ReqQryCFMMCTradingAccountKey(CTPTradeApi::CThostFtdcQryCFMMCTradingAccountKeyField pQryCFMMCTradingAccountKey, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryCFMMCTradingAccountKey);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryCFMMCTradingAccountKey, bufferIntPtr, false);
			CThostFtdcQryCFMMCTradingAccountKeyField* temp = static_cast<CThostFtdcQryCFMMCTradingAccountKeyField*>(bufferIntPtr.ToPointer());
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
	int ReqQryEWarrantOffset(CTPTradeApi::CThostFtdcQryEWarrantOffsetField pQryEWarrantOffset, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryEWarrantOffset);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryEWarrantOffset, bufferIntPtr, false);
			CThostFtdcQryEWarrantOffsetField* temp = static_cast<CThostFtdcQryEWarrantOffsetField*>(bufferIntPtr.ToPointer());
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
	int ReqQryInvestorProductGroupMargin(CTPTradeApi::CThostFtdcQryInvestorProductGroupMarginField pQryInvestorProductGroupMargin, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryInvestorProductGroupMargin);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryInvestorProductGroupMargin, bufferIntPtr, false);
			CThostFtdcQryInvestorProductGroupMarginField* temp = static_cast<CThostFtdcQryInvestorProductGroupMarginField*>(bufferIntPtr.ToPointer());
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
	int ReqQryExchangeMarginRate(CTPTradeApi::CThostFtdcQryExchangeMarginRateField pQryExchangeMarginRate, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryExchangeMarginRate);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryExchangeMarginRate, bufferIntPtr, false);
			CThostFtdcQryExchangeMarginRateField* temp = static_cast<CThostFtdcQryExchangeMarginRateField*>(bufferIntPtr.ToPointer());
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
	int ReqQryExchangeMarginRateAdjust(CTPTradeApi::CThostFtdcQryExchangeMarginRateAdjustField pQryExchangeMarginRateAdjust, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryExchangeMarginRateAdjust);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryExchangeMarginRateAdjust, bufferIntPtr, false);
			CThostFtdcQryExchangeMarginRateAdjustField* temp = static_cast<CThostFtdcQryExchangeMarginRateAdjustField*>(bufferIntPtr.ToPointer());
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
	int ReqQryTransferSerial(CTPTradeApi::CThostFtdcQryTransferSerialField pQryTransferSerial, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryTransferSerial);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryTransferSerial, bufferIntPtr, false);
			CThostFtdcQryTransferSerialField* temp = static_cast<CThostFtdcQryTransferSerialField*>(bufferIntPtr.ToPointer());
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
	int ReqQryAccountregister(CTPTradeApi::CThostFtdcQryAccountregisterField pQryAccountregister, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryAccountregister);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryAccountregister, bufferIntPtr, false);
			CThostFtdcQryAccountregisterField* temp = static_cast<CThostFtdcQryAccountregisterField*>(bufferIntPtr.ToPointer());
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
	int ReqQryContractBank(CTPTradeApi::CThostFtdcQryContractBankField pQryContractBank, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryContractBank);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryContractBank, bufferIntPtr, false);
			CThostFtdcQryContractBankField* temp = static_cast<CThostFtdcQryContractBankField*>(bufferIntPtr.ToPointer());
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
	int ReqQryParkedOrder(CTPTradeApi::CThostFtdcQryParkedOrderField pQryParkedOrder, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryParkedOrder);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryParkedOrder, bufferIntPtr, false);
			CThostFtdcQryParkedOrderField* temp = static_cast<CThostFtdcQryParkedOrderField*>(bufferIntPtr.ToPointer());
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
	int ReqQryParkedOrderAction(CTPTradeApi::CThostFtdcQryParkedOrderActionField pQryParkedOrderAction, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryParkedOrderAction);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryParkedOrderAction, bufferIntPtr, false);
			CThostFtdcQryParkedOrderActionField* temp = static_cast<CThostFtdcQryParkedOrderActionField*>(bufferIntPtr.ToPointer());
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
	int ReqQryTradingNotice(CTPTradeApi::CThostFtdcQryTradingNoticeField pQryTradingNotice, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryTradingNotice);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryTradingNotice, bufferIntPtr, false);
			CThostFtdcQryTradingNoticeField* temp = static_cast<CThostFtdcQryTradingNoticeField*>(bufferIntPtr.ToPointer());
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
	int ReqQryBrokerTradingParams(CTPTradeApi::CThostFtdcQryBrokerTradingParamsField pQryBrokerTradingParams, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryBrokerTradingParams);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryBrokerTradingParams, bufferIntPtr, false);
			CThostFtdcQryBrokerTradingParamsField* temp = static_cast<CThostFtdcQryBrokerTradingParamsField*>(bufferIntPtr.ToPointer());
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
	int ReqQryBrokerTradingAlgos(CTPTradeApi::CThostFtdcQryBrokerTradingAlgosField pQryBrokerTradingAlgos, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pQryBrokerTradingAlgos);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pQryBrokerTradingAlgos, bufferIntPtr, false);
			CThostFtdcQryBrokerTradingAlgosField* temp = static_cast<CThostFtdcQryBrokerTradingAlgosField*>(bufferIntPtr.ToPointer());
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
	int ReqFromBankToFutureByFuture(CTPTradeApi::CThostFtdcReqTransferField pReqTransfer, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pReqTransfer);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pReqTransfer, bufferIntPtr, false);
			CThostFtdcReqTransferField* temp = static_cast<CThostFtdcReqTransferField*>(bufferIntPtr.ToPointer());
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
	int ReqFromFutureToBankByFuture(CTPTradeApi::CThostFtdcReqTransferField pReqTransfer, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pReqTransfer);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pReqTransfer, bufferIntPtr, false);
			CThostFtdcReqTransferField* temp = static_cast<CThostFtdcReqTransferField*>(bufferIntPtr.ToPointer());
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
	int ReqQueryBankAccountMoneyByFuture(CTPTradeApi::CThostFtdcReqQueryAccountField pReqQueryAccount, [Out]  int %nRequestID)
	{
		nRequestID = Interlocked::Increment(lRequestID);
		int size = Marshal::SizeOf(pReqQueryAccount);
		IntPtr bufferIntPtr = Marshal::AllocHGlobal(size);
		try
		{
			Marshal::StructureToPtr(pReqQueryAccount, bufferIntPtr, false);
			CThostFtdcReqQueryAccountField* temp = static_cast<CThostFtdcReqQueryAccountField*>(bufferIntPtr.ToPointer());
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
			cppFrontConnect^ fp = gcnew cppFrontConnect(this, &TradeApiclr::cppcbFrontConnect);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnFrontConnected cb = static_cast<CBOnFrontConnected>(ip.ToPointer());
			pUserSpi->cbOnFrontConnected = cb;
		}

		{
			cppDisConnected^ fp = gcnew cppDisConnected(this, &TradeApiclr::cppcbDisConnected);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnFrontDisconnected cb = static_cast<CBOnFrontDisconnected>(ip.ToPointer());
			pUserSpi->cbOnFrontDisconnected = cb;
		}

		{
			cppHeartBeatWarning^ fp = gcnew cppHeartBeatWarning(this, &TradeApiclr::cppcbHeartBeatWarning);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBOnHeartBeatWarning cb = static_cast<CBOnHeartBeatWarning>(ip.ToPointer());
			pUserSpi->cbOnHeartBeatWarning = cb;
		}

		{
			cppErrRtnBankToFutureByFuture^ fp = gcnew cppErrRtnBankToFutureByFuture(this, &TradeApiclr::cppcbErrRtnBankToFutureByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnBankToFutureByFuture cb = static_cast<CBErrRtnBankToFutureByFuture>(ip.ToPointer());
			pUserSpi->cbErrRtnBankToFutureByFuture = cb;
		}

		{
			cppErrRtnFutureToBankByFuture^ fp = gcnew cppErrRtnFutureToBankByFuture(this, &TradeApiclr::cppcbErrRtnFutureToBankByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnFutureToBankByFuture cb = static_cast<CBErrRtnFutureToBankByFuture>(ip.ToPointer());
			pUserSpi->cbErrRtnFutureToBankByFuture = cb;
		}

		{
			cppErrRtnOrderAction^ fp = gcnew cppErrRtnOrderAction(this, &TradeApiclr::cppcbErrRtnOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnOrderAction cb = static_cast<CBErrRtnOrderAction>(ip.ToPointer());
			pUserSpi->cbErrRtnOrderAction = cb;
		}

		{
			cppErrRtnOrderInsert^ fp = gcnew cppErrRtnOrderInsert(this, &TradeApiclr::cppcbErrRtnOrderInsert);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnOrderInsert cb = static_cast<CBErrRtnOrderInsert>(ip.ToPointer());
			pUserSpi->cbErrRtnOrderInsert = cb;
		}

		{
			cppErrRtnQueryBankBalanceByFuture^ fp = gcnew cppErrRtnQueryBankBalanceByFuture(this, &TradeApiclr::cppcbErrRtnQueryBankBalanceByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnQueryBankBalanceByFuture cb = static_cast<CBErrRtnQueryBankBalanceByFuture>(ip.ToPointer());
			pUserSpi->cbErrRtnQueryBankBalanceByFuture = cb;
		}

		{
			cppErrRtnRepealBankToFutureByFutureManual^ fp = gcnew cppErrRtnRepealBankToFutureByFutureManual(this, &TradeApiclr::cppcbErrRtnRepealBankToFutureByFutureManual);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnRepealBankToFutureByFutureManual cb = static_cast<CBErrRtnRepealBankToFutureByFutureManual>(ip.ToPointer());
			pUserSpi->cbErrRtnRepealBankToFutureByFutureManual = cb;
		}

		{
			cppErrRtnRepealFutureToBankByFutureManual^ fp = gcnew cppErrRtnRepealFutureToBankByFutureManual(this, &TradeApiclr::cppcbErrRtnRepealFutureToBankByFutureManual);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBErrRtnRepealFutureToBankByFutureManual cb = static_cast<CBErrRtnRepealFutureToBankByFutureManual>(ip.ToPointer());
			pUserSpi->cbErrRtnRepealFutureToBankByFutureManual = cb;
		}

		{
			cppRspError^ fp = gcnew cppRspError(this, &TradeApiclr::cppcbRspError);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspError cb = static_cast<CBRspError>(ip.ToPointer());
			pUserSpi->cbRspError = cb;
		}

		{
			cppRspFromBankToFutureByFuture^ fp = gcnew cppRspFromBankToFutureByFuture(this, &TradeApiclr::cppcbRspFromBankToFutureByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspFromBankToFutureByFuture cb = static_cast<CBRspFromBankToFutureByFuture>(ip.ToPointer());
			pUserSpi->cbRspFromBankToFutureByFuture = cb;
		}

		{
			cppRspFromFutureToBankByFuture^ fp = gcnew cppRspFromFutureToBankByFuture(this, &TradeApiclr::cppcbRspFromFutureToBankByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspFromFutureToBankByFuture cb = static_cast<CBRspFromFutureToBankByFuture>(ip.ToPointer());
			pUserSpi->cbRspFromFutureToBankByFuture = cb;
		}

		{
			cppRspOrderAction^ fp = gcnew cppRspOrderAction(this, &TradeApiclr::cppcbRspOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspOrderAction cb = static_cast<CBRspOrderAction>(ip.ToPointer());
			pUserSpi->cbRspOrderAction = cb;
		}

		{
			cppRspOrderInsert^ fp = gcnew cppRspOrderInsert(this, &TradeApiclr::cppcbRspOrderInsert);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspOrderInsert cb = static_cast<CBRspOrderInsert>(ip.ToPointer());
			pUserSpi->cbRspOrderInsert = cb;
		}

		{
			cppRspParkedOrderAction^ fp = gcnew cppRspParkedOrderAction(this, &TradeApiclr::cppcbRspParkedOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspParkedOrderAction cb = static_cast<CBRspParkedOrderAction>(ip.ToPointer());
			pUserSpi->cbRspParkedOrderAction = cb;
		}

		{
			cppRspParkedOrderInsert^ fp = gcnew cppRspParkedOrderInsert(this, &TradeApiclr::cppcbRspParkedOrderInsert);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspParkedOrderInsert cb = static_cast<CBRspParkedOrderInsert>(ip.ToPointer());
			pUserSpi->cbRspParkedOrderInsert = cb;
		}

		{
			cppRspQryBrokerTradingAlgos^ fp = gcnew cppRspQryBrokerTradingAlgos(this, &TradeApiclr::cppcbRspQryBrokerTradingAlgos);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryBrokerTradingAlgos cb = static_cast<CBRspQryBrokerTradingAlgos>(ip.ToPointer());
			pUserSpi->cbRspQryBrokerTradingAlgos = cb;
		}

		{
			cppRspQryBrokerTradingParams^ fp = gcnew cppRspQryBrokerTradingParams(this, &TradeApiclr::cppcbRspQryBrokerTradingParams);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryBrokerTradingParams cb = static_cast<CBRspQryBrokerTradingParams>(ip.ToPointer());
			pUserSpi->cbRspQryBrokerTradingParams = cb;
		}

		{
			cppRspQryCFMMCTradingAccountKey^ fp = gcnew cppRspQryCFMMCTradingAccountKey(this, &TradeApiclr::cppcbRspQryCFMMCTradingAccountKey);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryCFMMCTradingAccountKey cb = static_cast<CBRspQryCFMMCTradingAccountKey>(ip.ToPointer());
			pUserSpi->cbRspQryCFMMCTradingAccountKey = cb;
		}

		{
			cppRspQryContractBank^ fp = gcnew cppRspQryContractBank(this, &TradeApiclr::cppcbRspQryContractBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryContractBank cb = static_cast<CBRspQryContractBank>(ip.ToPointer());
			pUserSpi->cbRspQryContractBank = cb;
		}

		{
			cppRspQryDepthMarketData^ fp = gcnew cppRspQryDepthMarketData(this, &TradeApiclr::cppcbRspQryDepthMarketData);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryDepthMarketData cb = static_cast<CBRspQryDepthMarketData>(ip.ToPointer());
			pUserSpi->cbRspQryDepthMarketData = cb;
		}

		{
			cppRspQryExchange^ fp = gcnew cppRspQryExchange(this, &TradeApiclr::cppcbRspQryExchange);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryExchange cb = static_cast<CBRspQryExchange>(ip.ToPointer());
			pUserSpi->cbRspQryExchange = cb;
		}

		{
			cppRspQryInstrument^ fp = gcnew cppRspQryInstrument(this, &TradeApiclr::cppcbRspQryInstrument);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInstrument cb = static_cast<CBRspQryInstrument>(ip.ToPointer());
			pUserSpi->cbRspQryInstrument = cb;
		}

		{
			cppRspQryInstrumentCommissionRate^ fp = gcnew cppRspQryInstrumentCommissionRate(this, &TradeApiclr::cppcbRspQryInstrumentCommissionRate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInstrumentCommissionRate cb = static_cast<CBRspQryInstrumentCommissionRate>(ip.ToPointer());
			pUserSpi->cbRspQryInstrumentCommissionRate = cb;
		}

		{
			cppRspQryInstrumentMarginRate^ fp = gcnew cppRspQryInstrumentMarginRate(this, &TradeApiclr::cppcbRspQryInstrumentMarginRate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInstrumentMarginRate cb = static_cast<CBRspQryInstrumentMarginRate>(ip.ToPointer());
			pUserSpi->cbRspQryInstrumentMarginRate = cb;
		}

		{
			cppRspQryInvestor^ fp = gcnew cppRspQryInvestor(this, &TradeApiclr::cppcbRspQryInvestor);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInvestor cb = static_cast<CBRspQryInvestor>(ip.ToPointer());
			pUserSpi->cbRspQryInvestor = cb;
		}

		{
			cppRspQryInvestorPosition^ fp = gcnew cppRspQryInvestorPosition(this, &TradeApiclr::cppcbRspQryInvestorPosition);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInvestorPosition cb = static_cast<CBRspQryInvestorPosition>(ip.ToPointer());
			pUserSpi->cbRspQryInvestorPosition = cb;
		}

		{
			cppRspQryInvestorPositionCombineDetail^ fp = gcnew cppRspQryInvestorPositionCombineDetail(this, &TradeApiclr::cppcbRspQryInvestorPositionCombineDetail);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInvestorPositionCombineDetail cb = static_cast<CBRspQryInvestorPositionCombineDetail>(ip.ToPointer());
			pUserSpi->cbRspQryInvestorPositionCombineDetail = cb;
		}

		{
			cppRspQryInvestorPositionDetail^ fp = gcnew cppRspQryInvestorPositionDetail(this, &TradeApiclr::cppcbRspQryInvestorPositionDetail);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryInvestorPositionDetail cb = static_cast<CBRspQryInvestorPositionDetail>(ip.ToPointer());
			pUserSpi->cbRspQryInvestorPositionDetail = cb;
		}

		{
			cppRspQryNotice^ fp = gcnew cppRspQryNotice(this, &TradeApiclr::cppcbRspQryNotice);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryNotice cb = static_cast<CBRspQryNotice>(ip.ToPointer());
			pUserSpi->cbRspQryNotice = cb;
		}

		{
			cppRspQryOrder^ fp = gcnew cppRspQryOrder(this, &TradeApiclr::cppcbRspQryOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryOrder cb = static_cast<CBRspQryOrder>(ip.ToPointer());
			pUserSpi->cbRspQryOrder = cb;
		}

		{
			cppRspQryParkedOrder^ fp = gcnew cppRspQryParkedOrder(this, &TradeApiclr::cppcbRspQryParkedOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryParkedOrder cb = static_cast<CBRspQryParkedOrder>(ip.ToPointer());
			pUserSpi->cbRspQryParkedOrder = cb;
		}

		{
			cppRspQryParkedOrderAction^ fp = gcnew cppRspQryParkedOrderAction(this, &TradeApiclr::cppcbRspQryParkedOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryParkedOrderAction cb = static_cast<CBRspQryParkedOrderAction>(ip.ToPointer());
			pUserSpi->cbRspQryParkedOrderAction = cb;
		}

		{
			cppRspQrySettlementInfo^ fp = gcnew cppRspQrySettlementInfo(this, &TradeApiclr::cppcbRspQrySettlementInfo);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQrySettlementInfo cb = static_cast<CBRspQrySettlementInfo>(ip.ToPointer());
			pUserSpi->cbRspQrySettlementInfo = cb;
		}

		{
			cppRspQrySettlementInfoConfirm^ fp = gcnew cppRspQrySettlementInfoConfirm(this, &TradeApiclr::cppcbRspQrySettlementInfoConfirm);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQrySettlementInfoConfirm cb = static_cast<CBRspQrySettlementInfoConfirm>(ip.ToPointer());
			pUserSpi->cbRspQrySettlementInfoConfirm = cb;
		}

		{
			cppRspQryTrade^ fp = gcnew cppRspQryTrade(this, &TradeApiclr::cppcbRspQryTrade);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTrade cb = static_cast<CBRspQryTrade>(ip.ToPointer());
			pUserSpi->cbRspQryTrade = cb;
		}

		{
			cppRspQryTradingAccount^ fp = gcnew cppRspQryTradingAccount(this, &TradeApiclr::cppcbRspQryTradingAccount);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTradingAccount cb = static_cast<CBRspQryTradingAccount>(ip.ToPointer());
			pUserSpi->cbRspQryTradingAccount = cb;
		}

		{
			cppRspQryTradingCode^ fp = gcnew cppRspQryTradingCode(this, &TradeApiclr::cppcbRspQryTradingCode);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTradingCode cb = static_cast<CBRspQryTradingCode>(ip.ToPointer());
			pUserSpi->cbRspQryTradingCode = cb;
		}

		{
			cppRspQryTradingNotice^ fp = gcnew cppRspQryTradingNotice(this, &TradeApiclr::cppcbRspQryTradingNotice);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTradingNotice cb = static_cast<CBRspQryTradingNotice>(ip.ToPointer());
			pUserSpi->cbRspQryTradingNotice = cb;
		}

		{
			cppRspQryTransferBank^ fp = gcnew cppRspQryTransferBank(this, &TradeApiclr::cppcbRspQryTransferBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTransferBank cb = static_cast<CBRspQryTransferBank>(ip.ToPointer());
			pUserSpi->cbRspQryTransferBank = cb;
		}

		{
			cppRspQryTransferSerial^ fp = gcnew cppRspQryTransferSerial(this, &TradeApiclr::cppcbRspQryTransferSerial);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryTransferSerial cb = static_cast<CBRspQryTransferSerial>(ip.ToPointer());
			pUserSpi->cbRspQryTransferSerial = cb;
		}

		{
			cppRspQryAccountregister^ fp = gcnew cppRspQryAccountregister(this, &TradeApiclr::cppcbRspQryAccountregister);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQryAccountregister cb = static_cast<CBRspQryAccountregister>(ip.ToPointer());
			pUserSpi->cbRspQryAccountregister = cb;
		}

		{
			cppRspQueryBankAccountMoneyByFuture^ fp = gcnew cppRspQueryBankAccountMoneyByFuture(this, &TradeApiclr::cppcbRspQueryBankAccountMoneyByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQueryBankAccountMoneyByFuture cb = static_cast<CBRspQueryBankAccountMoneyByFuture>(ip.ToPointer());
			pUserSpi->cbRspQueryBankAccountMoneyByFuture = cb;
		}

		{
			cppRspQueryMaxOrderVolume^ fp = gcnew cppRspQueryMaxOrderVolume(this, &TradeApiclr::cppcbRspQueryMaxOrderVolume);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspQueryMaxOrderVolume cb = static_cast<CBRspQueryMaxOrderVolume>(ip.ToPointer());
			pUserSpi->cbRspQueryMaxOrderVolume = cb;
		}

		{
			cppRspRemoveParkedOrder^ fp = gcnew cppRspRemoveParkedOrder(this, &TradeApiclr::cppcbRspRemoveParkedOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspRemoveParkedOrder cb = static_cast<CBRspRemoveParkedOrder>(ip.ToPointer());
			pUserSpi->cbRspRemoveParkedOrder = cb;
		}

		{
			cppRspRemoveParkedOrderAction^ fp = gcnew cppRspRemoveParkedOrderAction(this, &TradeApiclr::cppcbRspRemoveParkedOrderAction);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspRemoveParkedOrderAction cb = static_cast<CBRspRemoveParkedOrderAction>(ip.ToPointer());
			pUserSpi->cbRspRemoveParkedOrderAction = cb;
		}

		{
			cppRspSettlementInfoConfirm^ fp = gcnew cppRspSettlementInfoConfirm(this, &TradeApiclr::cppcbRspSettlementInfoConfirm);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspSettlementInfoConfirm cb = static_cast<CBRspSettlementInfoConfirm>(ip.ToPointer());
			pUserSpi->cbRspSettlementInfoConfirm = cb;
		}

		{
			cppRspTradingAccountPasswordUpdate^ fp = gcnew cppRspTradingAccountPasswordUpdate(this, &TradeApiclr::cppcbRspTradingAccountPasswordUpdate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspTradingAccountPasswordUpdate cb = static_cast<CBRspTradingAccountPasswordUpdate>(ip.ToPointer());
			pUserSpi->cbRspTradingAccountPasswordUpdate = cb;
		}

		{
			cppRspUserLogin^ fp = gcnew cppRspUserLogin(this, &TradeApiclr::cppcbRspUserLogin);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspUserLogin cb = static_cast<CBRspUserLogin>(ip.ToPointer());
			pUserSpi->cbRspUserLogin = cb;
		}

		{
			cppRspUserLogout^ fp = gcnew cppRspUserLogout(this, &TradeApiclr::cppcbRspUserLogout);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspUserLogout cb = static_cast<CBRspUserLogout>(ip.ToPointer());
			pUserSpi->cbRspUserLogout = cb;
		}

		{
			cppRspUserPasswordUpdate^ fp = gcnew cppRspUserPasswordUpdate(this, &TradeApiclr::cppcbRspUserPasswordUpdate);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRspUserPasswordUpdate cb = static_cast<CBRspUserPasswordUpdate>(ip.ToPointer());
			pUserSpi->cbRspUserPasswordUpdate = cb;
		}

		{
			cppRtnErrorConditionalOrder^ fp = gcnew cppRtnErrorConditionalOrder(this, &TradeApiclr::cppcbRtnErrorConditionalOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnErrorConditionalOrder cb = static_cast<CBRtnErrorConditionalOrder>(ip.ToPointer());
			pUserSpi->cbRtnErrorConditionalOrder = cb;
		}

		{
			cppRtnFromBankToFutureByBank^ fp = gcnew cppRtnFromBankToFutureByBank(this, &TradeApiclr::cppcbRtnFromBankToFutureByBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnFromBankToFutureByBank cb = static_cast<CBRtnFromBankToFutureByBank>(ip.ToPointer());
			pUserSpi->cbRtnFromBankToFutureByBank = cb;
		}

		{
			cppRtnFromBankToFutureByFuture^ fp = gcnew cppRtnFromBankToFutureByFuture(this, &TradeApiclr::cppcbRtnFromBankToFutureByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnFromBankToFutureByFuture cb = static_cast<CBRtnFromBankToFutureByFuture>(ip.ToPointer());
			pUserSpi->cbRtnFromBankToFutureByFuture = cb;
		}

		{
			cppRtnFromFutureToBankByBank^ fp = gcnew cppRtnFromFutureToBankByBank(this, &TradeApiclr::cppcbRtnFromFutureToBankByBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnFromFutureToBankByBank cb = static_cast<CBRtnFromFutureToBankByBank>(ip.ToPointer());
			pUserSpi->cbRtnFromFutureToBankByBank = cb;
		}

		{
			cppRtnFromFutureToBankByFuture^ fp = gcnew cppRtnFromFutureToBankByFuture(this, &TradeApiclr::cppcbRtnFromFutureToBankByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnFromFutureToBankByFuture cb = static_cast<CBRtnFromFutureToBankByFuture>(ip.ToPointer());
			pUserSpi->cbRtnFromFutureToBankByFuture = cb;
		}

		{
			cppRtnInstrumentStatus^ fp = gcnew cppRtnInstrumentStatus(this, &TradeApiclr::cppcbRtnInstrumentStatus);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnInstrumentStatus cb = static_cast<CBRtnInstrumentStatus>(ip.ToPointer());
			pUserSpi->cbRtnInstrumentStatus = cb;
		}

		{
			cppRtnOrder^ fp = gcnew cppRtnOrder(this, &TradeApiclr::cppcbRtnOrder);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnOrder cb = static_cast<CBRtnOrder>(ip.ToPointer());
			pUserSpi->cbRtnOrder = cb;
		}

		{
			cppRtnQueryBankBalanceByFuture^ fp = gcnew cppRtnQueryBankBalanceByFuture(this, &TradeApiclr::cppcbRtnQueryBankBalanceByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnQueryBankBalanceByFuture cb = static_cast<CBRtnQueryBankBalanceByFuture>(ip.ToPointer());
			pUserSpi->cbRtnQueryBankBalanceByFuture = cb;
		}

		{
			cppRtnRepealFromBankToFutureByBank^ fp = gcnew cppRtnRepealFromBankToFutureByBank(this, &TradeApiclr::cppcbRtnRepealFromBankToFutureByBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromBankToFutureByBank cb = static_cast<CBRtnRepealFromBankToFutureByBank>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromBankToFutureByBank = cb;
		}

		{
			cppRtnRepealFromBankToFutureByFuture^ fp = gcnew cppRtnRepealFromBankToFutureByFuture(this, &TradeApiclr::cppcbRtnRepealFromBankToFutureByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromBankToFutureByFuture cb = static_cast<CBRtnRepealFromBankToFutureByFuture>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromBankToFutureByFuture = cb;
		}

		{
			cppRtnRepealFromBankToFutureByFutureManual^ fp = gcnew cppRtnRepealFromBankToFutureByFutureManual(this, &TradeApiclr::cppcbRtnRepealFromBankToFutureByFutureManual);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromBankToFutureByFutureManual cb = static_cast<CBRtnRepealFromBankToFutureByFutureManual>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromBankToFutureByFutureManual = cb;
		}

		{
			cppRtnRepealFromFutureToBankByBank^ fp = gcnew cppRtnRepealFromFutureToBankByBank(this, &TradeApiclr::cppcbRtnRepealFromFutureToBankByBank);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromFutureToBankByBank cb = static_cast<CBRtnRepealFromFutureToBankByBank>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromFutureToBankByBank = cb;
		}

		{
			cppRtnRepealFromFutureToBankByFuture^ fp = gcnew cppRtnRepealFromFutureToBankByFuture(this, &TradeApiclr::cppcbRtnRepealFromFutureToBankByFuture);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromFutureToBankByFuture cb = static_cast<CBRtnRepealFromFutureToBankByFuture>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromFutureToBankByFuture = cb;
		}

		{
			cppRtnRepealFromFutureToBankByFutureManual^ fp = gcnew cppRtnRepealFromFutureToBankByFutureManual(this, &TradeApiclr::cppcbRtnRepealFromFutureToBankByFutureManual);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnRepealFromFutureToBankByFutureManual cb = static_cast<CBRtnRepealFromFutureToBankByFutureManual>(ip.ToPointer());
			pUserSpi->cbRtnRepealFromFutureToBankByFutureManual = cb;
		}

		{
			cppRtnTrade^ fp = gcnew cppRtnTrade(this, &TradeApiclr::cppcbRtnTrade);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnTrade cb = static_cast<CBRtnTrade>(ip.ToPointer());
			pUserSpi->cbRtnTrade = cb;
		}

		{
			cppRtnTradingNotice^ fp = gcnew cppRtnTradingNotice(this, &TradeApiclr::cppcbRtnTradingNotice);
			GCHandle gch = GCHandle::Alloc(fp);
			gchlist->Add(gch);
			IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
			CBRtnTradingNotice cb = static_cast<CBRtnTradingNotice>(ip.ToPointer());
			pUserSpi->cbRtnTradingNotice = cb;
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
	delegate void HeartBeatWarning(int pTimeLapes);
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
	event HeartBeatWarning ^OnHeartBeatWarning;


public:
	delegate void ErrRtnBankToFutureByFuture(CTPTradeApi::CThostFtdcReqTransferField pReqTransfer, CTPTradeApi::CThostFtdcRspInfoField pRspInfo);
private:
	delegate void cppErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
	{
		CTPTradeApi::CThostFtdcReqTransferField  cspReqTransfer = (CTPTradeApi::CThostFtdcReqTransferField) Marshal::PtrToStructure(IntPtr(pReqTransfer), CTPTradeApi::CThostFtdcReqTransferField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnErrRtnBankToFutureByFuture(cspReqTransfer, cspRspInfo);
	}
public:
	/// <summary>
	/// 期货发起银行资金转期货错误回报
	/// </summary>
	event ErrRtnBankToFutureByFuture ^OnErrRtnBankToFutureByFuture;


public:
	delegate void ErrRtnFutureToBankByFuture(CTPTradeApi::CThostFtdcReqTransferField pReqTransfer, CTPTradeApi::CThostFtdcRspInfoField pRspInfo);
private:
	delegate void cppErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
	{
		CTPTradeApi::CThostFtdcReqTransferField  cspReqTransfer = (CTPTradeApi::CThostFtdcReqTransferField) Marshal::PtrToStructure(IntPtr(pReqTransfer), CTPTradeApi::CThostFtdcReqTransferField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnErrRtnFutureToBankByFuture(cspReqTransfer, cspRspInfo);
	}
public:
	/// <summary>
	/// 期货发起期货资金转银行错误回报
	/// </summary>
	event ErrRtnFutureToBankByFuture ^OnErrRtnFutureToBankByFuture;


public:
	delegate void ErrRtnOrderAction(CTPTradeApi::CThostFtdcOrderActionField pOrderAction, CTPTradeApi::CThostFtdcRspInfoField pRspInfo);
private:
	delegate void cppErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo)
	{
		CTPTradeApi::CThostFtdcOrderActionField  cspOrderAction = (CTPTradeApi::CThostFtdcOrderActionField) Marshal::PtrToStructure(IntPtr(pOrderAction), CTPTradeApi::CThostFtdcOrderActionField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnErrRtnOrderAction(cspOrderAction, cspRspInfo);
	}
public:
	/// <summary>
	/// 报单操作错误回报
	/// </summary>
	event ErrRtnOrderAction ^OnErrRtnOrderAction;


public:
	delegate void ErrRtnOrderInsert(CTPTradeApi::CThostFtdcInputOrderField pInputOrder, CTPTradeApi::CThostFtdcRspInfoField pRspInfo);
private:
	delegate void cppErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
	{
		CTPTradeApi::CThostFtdcInputOrderField  cspInputOrder = (CTPTradeApi::CThostFtdcInputOrderField) Marshal::PtrToStructure(IntPtr(pInputOrder), CTPTradeApi::CThostFtdcInputOrderField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnErrRtnOrderInsert(cspInputOrder, cspRspInfo);
	}
public:
	/// <summary>
	/// 报单录入错误回报
	/// </summary>
	event ErrRtnOrderInsert ^OnErrRtnOrderInsert;


public:
	delegate void ErrRtnQueryBankBalanceByFuture(CTPTradeApi::CThostFtdcReqQueryAccountField pReqQueryAccount, CTPTradeApi::CThostFtdcRspInfoField pRspInfo);
private:
	delegate void cppErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo)
	{
		CTPTradeApi::CThostFtdcReqQueryAccountField  cspReqQueryAccount = (CTPTradeApi::CThostFtdcReqQueryAccountField) Marshal::PtrToStructure(IntPtr(pReqQueryAccount), CTPTradeApi::CThostFtdcReqQueryAccountField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnErrRtnQueryBankBalanceByFuture(cspReqQueryAccount, cspRspInfo);
	}
public:
	/// <summary>
	/// 期货发起查询银行余额错误回报
	/// </summary>
	event ErrRtnQueryBankBalanceByFuture ^OnErrRtnQueryBankBalanceByFuture;


public:
	delegate void ErrRtnRepealBankToFutureByFutureManual(CTPTradeApi::CThostFtdcReqRepealField pReqRepeal, CTPTradeApi::CThostFtdcRspInfoField pRspInfo);
private:
	delegate void cppErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
	{
		CTPTradeApi::CThostFtdcReqRepealField  cspReqRepeal = (CTPTradeApi::CThostFtdcReqRepealField) Marshal::PtrToStructure(IntPtr(pReqRepeal), CTPTradeApi::CThostFtdcReqRepealField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnErrRtnRepealBankToFutureByFutureManual(cspReqRepeal, cspRspInfo);
	}
public:
	/// <summary>
	/// 系统运行时期货端手工发起冲正银行转期货错误回报
	/// </summary>
	event ErrRtnRepealBankToFutureByFutureManual ^OnErrRtnRepealBankToFutureByFutureManual;


public:
	delegate void ErrRtnRepealFutureToBankByFutureManual(CTPTradeApi::CThostFtdcReqRepealField pReqRepeal, CTPTradeApi::CThostFtdcRspInfoField pRspInfo);
private:
	delegate void cppErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
	{
		CTPTradeApi::CThostFtdcReqRepealField  cspReqRepeal = (CTPTradeApi::CThostFtdcReqRepealField) Marshal::PtrToStructure(IntPtr(pReqRepeal), CTPTradeApi::CThostFtdcReqRepealField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnErrRtnRepealFutureToBankByFutureManual(cspReqRepeal, cspRspInfo);
	}
public:
	/// <summary>
	/// 系统运行时期货端手工发起冲正期货转银行错误回报
	/// </summary>
	event ErrRtnRepealFutureToBankByFutureManual ^OnErrRtnRepealFutureToBankByFutureManual;


public:
	delegate void RspError(CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspError(cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 错误应答
	/// </summary>
	event RspError ^OnRspError;


public:
	delegate void RspFromBankToFutureByFuture(CTPTradeApi::CThostFtdcReqTransferField pReqTransfer, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcReqTransferField  cspReqTransfer = (CTPTradeApi::CThostFtdcReqTransferField) Marshal::PtrToStructure(IntPtr(pReqTransfer), CTPTradeApi::CThostFtdcReqTransferField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspFromBankToFutureByFuture(cspReqTransfer, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 期货发起银行资金转期货应答
	/// </summary>
	event RspFromBankToFutureByFuture ^OnRspFromBankToFutureByFuture;


public:
	delegate void RspFromFutureToBankByFuture(CTPTradeApi::CThostFtdcReqTransferField pReqTransfer, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcReqTransferField  cspReqTransfer = (CTPTradeApi::CThostFtdcReqTransferField) Marshal::PtrToStructure(IntPtr(pReqTransfer), CTPTradeApi::CThostFtdcReqTransferField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspFromFutureToBankByFuture(cspReqTransfer, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 期货发起期货资金转银行应答
	/// </summary>
	event RspFromFutureToBankByFuture ^OnRspFromFutureToBankByFuture;


public:
	delegate void RspOrderAction(CTPTradeApi::CThostFtdcInputOrderActionField pInputOrderAction, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInputOrderActionField  cspInputOrderAction = (CTPTradeApi::CThostFtdcInputOrderActionField) Marshal::PtrToStructure(IntPtr(pInputOrderAction), CTPTradeApi::CThostFtdcInputOrderActionField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspOrderAction(cspInputOrderAction, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 报单操作请求响应
	/// </summary>
	event RspOrderAction ^OnRspOrderAction;


public:
	delegate void RspOrderInsert(CTPTradeApi::CThostFtdcInputOrderField pInputOrder, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInputOrderField  cspInputOrder = (CTPTradeApi::CThostFtdcInputOrderField) Marshal::PtrToStructure(IntPtr(pInputOrder), CTPTradeApi::CThostFtdcInputOrderField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspOrderInsert(cspInputOrder, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 报单录入请求响应
	/// </summary>
	event RspOrderInsert ^OnRspOrderInsert;


public:
	delegate void RspParkedOrderAction(CTPTradeApi::CThostFtdcParkedOrderActionField pParkedOrderAction, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcParkedOrderActionField  cspParkedOrderAction = (CTPTradeApi::CThostFtdcParkedOrderActionField) Marshal::PtrToStructure(IntPtr(pParkedOrderAction), CTPTradeApi::CThostFtdcParkedOrderActionField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspParkedOrderAction(cspParkedOrderAction, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 预埋撤单录入请求响应
	/// </summary>
	event RspParkedOrderAction ^OnRspParkedOrderAction;


public:
	delegate void RspParkedOrderInsert(CTPTradeApi::CThostFtdcParkedOrderField pParkedOrder, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcParkedOrderField  cspParkedOrder = (CTPTradeApi::CThostFtdcParkedOrderField) Marshal::PtrToStructure(IntPtr(pParkedOrder), CTPTradeApi::CThostFtdcParkedOrderField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspParkedOrderInsert(cspParkedOrder, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 预埋单录入请求响应
	/// </summary>
	event RspParkedOrderInsert ^OnRspParkedOrderInsert;


public:
	delegate void RspQryBrokerTradingAlgos(CTPTradeApi::CThostFtdcBrokerTradingAlgosField pBrokerTradingAlgos, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcBrokerTradingAlgosField  cspBrokerTradingAlgos = (CTPTradeApi::CThostFtdcBrokerTradingAlgosField) Marshal::PtrToStructure(IntPtr(pBrokerTradingAlgos), CTPTradeApi::CThostFtdcBrokerTradingAlgosField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryBrokerTradingAlgos(cspBrokerTradingAlgos, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询经纪公司交易算法响应
	/// </summary>
	event RspQryBrokerTradingAlgos ^OnRspQryBrokerTradingAlgos;


public:
	delegate void RspQryBrokerTradingParams(CTPTradeApi::CThostFtdcBrokerTradingParamsField pBrokerTradingParams, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcBrokerTradingParamsField  cspBrokerTradingParams = (CTPTradeApi::CThostFtdcBrokerTradingParamsField) Marshal::PtrToStructure(IntPtr(pBrokerTradingParams), CTPTradeApi::CThostFtdcBrokerTradingParamsField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryBrokerTradingParams(cspBrokerTradingParams, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询经纪公司交易参数响应
	/// </summary>
	event RspQryBrokerTradingParams ^OnRspQryBrokerTradingParams;


public:
	delegate void RspQryCFMMCTradingAccountKey(CTPTradeApi::CThostFtdcCFMMCTradingAccountKeyField pCFMMCTradingAccountKey, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcCFMMCTradingAccountKeyField  cspCFMMCTradingAccountKey = (CTPTradeApi::CThostFtdcCFMMCTradingAccountKeyField) Marshal::PtrToStructure(IntPtr(pCFMMCTradingAccountKey), CTPTradeApi::CThostFtdcCFMMCTradingAccountKeyField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryCFMMCTradingAccountKey(cspCFMMCTradingAccountKey, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 查询保证金监管系统经纪公司资金账户密钥响应
	/// </summary>
	event RspQryCFMMCTradingAccountKey ^OnRspQryCFMMCTradingAccountKey;


public:
	delegate void RspQryContractBank(CTPTradeApi::CThostFtdcContractBankField pContractBank, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcContractBankField  cspContractBank = (CTPTradeApi::CThostFtdcContractBankField) Marshal::PtrToStructure(IntPtr(pContractBank), CTPTradeApi::CThostFtdcContractBankField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryContractBank(cspContractBank, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询签约银行响应
	/// </summary>
	event RspQryContractBank ^OnRspQryContractBank;


public:
	delegate void RspQryDepthMarketData(CTPTradeApi::CThostFtdcDepthMarketDataField pDepthMarketData, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcDepthMarketDataField  cspDepthMarketData = (CTPTradeApi::CThostFtdcDepthMarketDataField) Marshal::PtrToStructure(IntPtr(pDepthMarketData), CTPTradeApi::CThostFtdcDepthMarketDataField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryDepthMarketData(cspDepthMarketData, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询行情响应
	/// </summary>
	event RspQryDepthMarketData ^OnRspQryDepthMarketData;


public:
	delegate void RspQryExchange(CTPTradeApi::CThostFtdcExchangeField pExchange, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcExchangeField  cspExchange = (CTPTradeApi::CThostFtdcExchangeField) Marshal::PtrToStructure(IntPtr(pExchange), CTPTradeApi::CThostFtdcExchangeField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryExchange(cspExchange, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询交易所响应
	/// </summary>
	event RspQryExchange ^OnRspQryExchange;


public:
	delegate void RspQryInstrument(CTPTradeApi::CThostFtdcInstrumentField pInstrument, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInstrumentField  cspInstrument = (CTPTradeApi::CThostFtdcInstrumentField) Marshal::PtrToStructure(IntPtr(pInstrument), CTPTradeApi::CThostFtdcInstrumentField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryInstrument(cspInstrument, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询合约响应
	/// </summary>
	event RspQryInstrument ^OnRspQryInstrument;


public:
	delegate void RspQryInstrumentCommissionRate(CTPTradeApi::CThostFtdcInstrumentCommissionRateField pInstrumentCommissionRate, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInstrumentCommissionRateField  cspInstrumentCommissionRate = (CTPTradeApi::CThostFtdcInstrumentCommissionRateField) Marshal::PtrToStructure(IntPtr(pInstrumentCommissionRate), CTPTradeApi::CThostFtdcInstrumentCommissionRateField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryInstrumentCommissionRate(cspInstrumentCommissionRate, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询合约手续费率响应
	/// </summary>
	event RspQryInstrumentCommissionRate ^OnRspQryInstrumentCommissionRate;


public:
	delegate void RspQryInstrumentMarginRate(CTPTradeApi::CThostFtdcInstrumentMarginRateField pInstrumentMarginRate, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInstrumentMarginRateField  cspInstrumentMarginRate = (CTPTradeApi::CThostFtdcInstrumentMarginRateField) Marshal::PtrToStructure(IntPtr(pInstrumentMarginRate), CTPTradeApi::CThostFtdcInstrumentMarginRateField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryInstrumentMarginRate(cspInstrumentMarginRate, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询合约保证金率响应
	/// </summary>
	event RspQryInstrumentMarginRate ^OnRspQryInstrumentMarginRate;


public:
	delegate void RspQryInvestor(CTPTradeApi::CThostFtdcInvestorField pInvestor, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInvestorField  cspInvestor = (CTPTradeApi::CThostFtdcInvestorField) Marshal::PtrToStructure(IntPtr(pInvestor), CTPTradeApi::CThostFtdcInvestorField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryInvestor(cspInvestor, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询投资者响应
	/// </summary>
	event RspQryInvestor ^OnRspQryInvestor;


public:
	delegate void RspQryInvestorPosition(CTPTradeApi::CThostFtdcInvestorPositionField pInvestorPosition, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInvestorPositionField  cspInvestorPosition = (CTPTradeApi::CThostFtdcInvestorPositionField) Marshal::PtrToStructure(IntPtr(pInvestorPosition), CTPTradeApi::CThostFtdcInvestorPositionField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryInvestorPosition(cspInvestorPosition, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询投资者持仓响应
	/// </summary>
	event RspQryInvestorPosition ^OnRspQryInvestorPosition;


public:
	delegate void RspQryInvestorPositionCombineDetail(CTPTradeApi::CThostFtdcInvestorPositionCombineDetailField pInvestorPositionCombineDetail, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInvestorPositionCombineDetailField  cspInvestorPositionCombineDetail = (CTPTradeApi::CThostFtdcInvestorPositionCombineDetailField) Marshal::PtrToStructure(IntPtr(pInvestorPositionCombineDetail), CTPTradeApi::CThostFtdcInvestorPositionCombineDetailField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryInvestorPositionCombineDetail(cspInvestorPositionCombineDetail, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询投资者持仓明细响应
	/// </summary>
	event RspQryInvestorPositionCombineDetail ^OnRspQryInvestorPositionCombineDetail;


public:
	delegate void RspQryInvestorPositionDetail(CTPTradeApi::CThostFtdcInvestorPositionDetailField pInvestorPositionDetail, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcInvestorPositionDetailField  cspInvestorPositionDetail = (CTPTradeApi::CThostFtdcInvestorPositionDetailField) Marshal::PtrToStructure(IntPtr(pInvestorPositionDetail), CTPTradeApi::CThostFtdcInvestorPositionDetailField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryInvestorPositionDetail(cspInvestorPositionDetail, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询投资者持仓明细响应
	/// </summary>
	event RspQryInvestorPositionDetail ^OnRspQryInvestorPositionDetail;


public:
	delegate void RspQryNotice(CTPTradeApi::CThostFtdcNoticeField pNotice, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcNoticeField  cspNotice = (CTPTradeApi::CThostFtdcNoticeField) Marshal::PtrToStructure(IntPtr(pNotice), CTPTradeApi::CThostFtdcNoticeField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryNotice(cspNotice, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询客户通知响应
	/// </summary>
	event RspQryNotice ^OnRspQryNotice;


public:
	delegate void RspQryOrder(CTPTradeApi::CThostFtdcOrderField pOrder, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcOrderField  cspOrder = (CTPTradeApi::CThostFtdcOrderField) Marshal::PtrToStructure(IntPtr(pOrder), CTPTradeApi::CThostFtdcOrderField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryOrder(cspOrder, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询报单响应
	/// </summary>
	event RspQryOrder ^OnRspQryOrder;


public:
	delegate void RspQryParkedOrder(CTPTradeApi::CThostFtdcParkedOrderField pParkedOrder, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcParkedOrderField  cspParkedOrder = (CTPTradeApi::CThostFtdcParkedOrderField) Marshal::PtrToStructure(IntPtr(pParkedOrder), CTPTradeApi::CThostFtdcParkedOrderField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryParkedOrder(cspParkedOrder, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询预埋单响应
	/// </summary>
	event RspQryParkedOrder ^OnRspQryParkedOrder;


public:
	delegate void RspQryParkedOrderAction(CTPTradeApi::CThostFtdcParkedOrderActionField pParkedOrderAction, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcParkedOrderActionField  cspParkedOrderAction = (CTPTradeApi::CThostFtdcParkedOrderActionField) Marshal::PtrToStructure(IntPtr(pParkedOrderAction), CTPTradeApi::CThostFtdcParkedOrderActionField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryParkedOrderAction(cspParkedOrderAction, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询预埋撤单响应
	/// </summary>
	event RspQryParkedOrderAction ^OnRspQryParkedOrderAction;


public:
	delegate void RspQrySettlementInfo(CTPTradeApi::CThostFtdcSettlementInfoField pSettlementInfo, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcSettlementInfoField  cspSettlementInfo = (CTPTradeApi::CThostFtdcSettlementInfoField) Marshal::PtrToStructure(IntPtr(pSettlementInfo), CTPTradeApi::CThostFtdcSettlementInfoField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQrySettlementInfo(cspSettlementInfo, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询投资者结算结果响应
	/// </summary>
	event RspQrySettlementInfo ^OnRspQrySettlementInfo;


public:
	delegate void RspQrySettlementInfoConfirm(CTPTradeApi::CThostFtdcSettlementInfoConfirmField pSettlementInfoConfirm, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcSettlementInfoConfirmField  cspSettlementInfoConfirm = (CTPTradeApi::CThostFtdcSettlementInfoConfirmField) Marshal::PtrToStructure(IntPtr(pSettlementInfoConfirm), CTPTradeApi::CThostFtdcSettlementInfoConfirmField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQrySettlementInfoConfirm(cspSettlementInfoConfirm, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询结算信息确认响应
	/// </summary>
	event RspQrySettlementInfoConfirm ^OnRspQrySettlementInfoConfirm;


public:
	delegate void RspQryTrade(CTPTradeApi::CThostFtdcTradeField pTrade, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcTradeField  cspTrade = (CTPTradeApi::CThostFtdcTradeField) Marshal::PtrToStructure(IntPtr(pTrade), CTPTradeApi::CThostFtdcTradeField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryTrade(cspTrade, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询成交响应
	/// </summary>
	event RspQryTrade ^OnRspQryTrade;


public:
	delegate void RspQryTradingAccount(CTPTradeApi::CThostFtdcTradingAccountField pTradingAccount, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcTradingAccountField  cspTradingAccount = (CTPTradeApi::CThostFtdcTradingAccountField) Marshal::PtrToStructure(IntPtr(pTradingAccount), CTPTradeApi::CThostFtdcTradingAccountField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryTradingAccount(cspTradingAccount, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询资金账户响应
	/// </summary>
	event RspQryTradingAccount ^OnRspQryTradingAccount;


public:
	delegate void RspQryTradingCode(CTPTradeApi::CThostFtdcTradingCodeField pTradingCode, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcTradingCodeField  cspTradingCode = (CTPTradeApi::CThostFtdcTradingCodeField) Marshal::PtrToStructure(IntPtr(pTradingCode), CTPTradeApi::CThostFtdcTradingCodeField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryTradingCode(cspTradingCode, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询交易编码响应
	/// </summary>
	event RspQryTradingCode ^OnRspQryTradingCode;


public:
	delegate void RspQryTradingNotice(CTPTradeApi::CThostFtdcTradingNoticeField pTradingNotice, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcTradingNoticeField  cspTradingNotice = (CTPTradeApi::CThostFtdcTradingNoticeField) Marshal::PtrToStructure(IntPtr(pTradingNotice), CTPTradeApi::CThostFtdcTradingNoticeField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryTradingNotice(cspTradingNotice, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询交易通知响应
	/// </summary>
	event RspQryTradingNotice ^OnRspQryTradingNotice;


public:
	delegate void RspQryTransferBank(CTPTradeApi::CThostFtdcTransferBankField pTransferBank, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcTransferBankField  cspTransferBank = (CTPTradeApi::CThostFtdcTransferBankField) Marshal::PtrToStructure(IntPtr(pTransferBank), CTPTradeApi::CThostFtdcTransferBankField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryTransferBank(cspTransferBank, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询转帐银行响应
	/// </summary>
	event RspQryTransferBank ^OnRspQryTransferBank;


public:
	delegate void RspQryTransferSerial(CTPTradeApi::CThostFtdcTransferSerialField pTransferSerial, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcTransferSerialField  cspTransferSerial = (CTPTradeApi::CThostFtdcTransferSerialField) Marshal::PtrToStructure(IntPtr(pTransferSerial), CTPTradeApi::CThostFtdcTransferSerialField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryTransferSerial(cspTransferSerial, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询转帐流水响应
	/// </summary>
	event RspQryTransferSerial ^OnRspQryTransferSerial;


public:
	delegate void RspQryAccountregister(CTPTradeApi::CThostFtdcAccountregisterField pAccountregister, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcAccountregisterField  cspAccountregister = (CTPTradeApi::CThostFtdcAccountregisterField) Marshal::PtrToStructure(IntPtr(pAccountregister), CTPTradeApi::CThostFtdcAccountregisterField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQryAccountregister(cspAccountregister, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询转帐流水响应
	/// </summary>
	event RspQryAccountregister ^OnRspQryAccountregister;


public:
	delegate void RspQueryBankAccountMoneyByFuture(CTPTradeApi::CThostFtdcReqQueryAccountField pReqQueryAccount, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcReqQueryAccountField  cspReqQueryAccount = (CTPTradeApi::CThostFtdcReqQueryAccountField) Marshal::PtrToStructure(IntPtr(pReqQueryAccount), CTPTradeApi::CThostFtdcReqQueryAccountField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQueryBankAccountMoneyByFuture(cspReqQueryAccount, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 期货发起查询银行余额应答
	/// </summary>
	event RspQueryBankAccountMoneyByFuture ^OnRspQueryBankAccountMoneyByFuture;


public:
	delegate void RspQueryMaxOrderVolume(CTPTradeApi::CThostFtdcQueryMaxOrderVolumeField pQueryMaxOrderVolume, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcQueryMaxOrderVolumeField  cspQueryMaxOrderVolume = (CTPTradeApi::CThostFtdcQueryMaxOrderVolumeField) Marshal::PtrToStructure(IntPtr(pQueryMaxOrderVolume), CTPTradeApi::CThostFtdcQueryMaxOrderVolumeField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspQueryMaxOrderVolume(cspQueryMaxOrderVolume, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 查询最大报单数量响应
	/// </summary>
	event RspQueryMaxOrderVolume ^OnRspQueryMaxOrderVolume;


public:
	delegate void RspRemoveParkedOrder(CTPTradeApi::CThostFtdcRemoveParkedOrderField pRemoveParkedOrder, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcRemoveParkedOrderField  cspRemoveParkedOrder = (CTPTradeApi::CThostFtdcRemoveParkedOrderField) Marshal::PtrToStructure(IntPtr(pRemoveParkedOrder), CTPTradeApi::CThostFtdcRemoveParkedOrderField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspRemoveParkedOrder(cspRemoveParkedOrder, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 删除预埋单响应
	/// </summary>
	event RspRemoveParkedOrder ^OnRspRemoveParkedOrder;


public:
	delegate void RspRemoveParkedOrderAction(CTPTradeApi::CThostFtdcRemoveParkedOrderActionField pRemoveParkedOrderAction, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcRemoveParkedOrderActionField  cspRemoveParkedOrderAction = (CTPTradeApi::CThostFtdcRemoveParkedOrderActionField) Marshal::PtrToStructure(IntPtr(pRemoveParkedOrderAction), CTPTradeApi::CThostFtdcRemoveParkedOrderActionField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspRemoveParkedOrderAction(cspRemoveParkedOrderAction, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 删除预埋撤单响应
	/// </summary>
	event RspRemoveParkedOrderAction ^OnRspRemoveParkedOrderAction;


public:
	delegate void RspSettlementInfoConfirm(CTPTradeApi::CThostFtdcSettlementInfoConfirmField pSettlementInfoConfirm, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcSettlementInfoConfirmField  cspSettlementInfoConfirm = (CTPTradeApi::CThostFtdcSettlementInfoConfirmField) Marshal::PtrToStructure(IntPtr(pSettlementInfoConfirm), CTPTradeApi::CThostFtdcSettlementInfoConfirmField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspSettlementInfoConfirm(cspSettlementInfoConfirm, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 投资者结算结果确认响应
	/// </summary>
	event RspSettlementInfoConfirm ^OnRspSettlementInfoConfirm;


public:
	delegate void RspTradingAccountPasswordUpdate(CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateField pTradingAccountPasswordUpdate, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateField  cspTradingAccountPasswordUpdate = (CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateField) Marshal::PtrToStructure(IntPtr(pTradingAccountPasswordUpdate), CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspTradingAccountPasswordUpdate(cspTradingAccountPasswordUpdate, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 资金账户口令更新请求响应
	/// </summary>
	event RspTradingAccountPasswordUpdate ^OnRspTradingAccountPasswordUpdate;


public:
	delegate void RspUserLogin(CTPTradeApi::CThostFtdcRspUserLoginField pRspUserLogin, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcRspUserLoginField  cspRspUserLogin = (CTPTradeApi::CThostFtdcRspUserLoginField) Marshal::PtrToStructure(IntPtr(pRspUserLogin), CTPTradeApi::CThostFtdcRspUserLoginField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspUserLogin(cspRspUserLogin, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 登录请求响应
	/// </summary>
	event RspUserLogin ^OnRspUserLogin;


public:
	delegate void RspUserLogout(CTPTradeApi::CThostFtdcUserLogoutField pUserLogout, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcUserLogoutField  cspUserLogout = (CTPTradeApi::CThostFtdcUserLogoutField) Marshal::PtrToStructure(IntPtr(pUserLogout), CTPTradeApi::CThostFtdcUserLogoutField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspUserLogout(cspUserLogout, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 登出请求响应
	/// </summary>
	event RspUserLogout ^OnRspUserLogout;


public:
	delegate void RspUserPasswordUpdate(CTPTradeApi::CThostFtdcUserPasswordUpdateField pUserPasswordUpdate, CTPTradeApi::CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
private:
	delegate void cppRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPTradeApi::CThostFtdcUserPasswordUpdateField  cspUserPasswordUpdate = (CTPTradeApi::CThostFtdcUserPasswordUpdateField) Marshal::PtrToStructure(IntPtr(pUserPasswordUpdate), CTPTradeApi::CThostFtdcUserPasswordUpdateField::typeid); CTPTradeApi::CThostFtdcRspInfoField  cspRspInfo = (CTPTradeApi::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPTradeApi::CThostFtdcRspInfoField::typeid);
		OnRspUserPasswordUpdate(cspUserPasswordUpdate, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 用户口令更新请求响应
	/// </summary>
	event RspUserPasswordUpdate ^OnRspUserPasswordUpdate;


public:
	delegate void RtnErrorConditionalOrder(CTPTradeApi::CThostFtdcErrorConditionalOrderField pErrorConditionalOrder);
private:
	delegate void cppRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
	void cppcbRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder)
	{
		CTPTradeApi::CThostFtdcErrorConditionalOrderField  cspErrorConditionalOrder = (CTPTradeApi::CThostFtdcErrorConditionalOrderField) Marshal::PtrToStructure(IntPtr(pErrorConditionalOrder), CTPTradeApi::CThostFtdcErrorConditionalOrderField::typeid);
		OnRtnErrorConditionalOrder(cspErrorConditionalOrder);
	}
public:
	/// <summary>
	/// 提示条件单校验错误
	/// </summary>
	event RtnErrorConditionalOrder ^OnRtnErrorConditionalOrder;


public:
	delegate void RtnFromBankToFutureByBank(CTPTradeApi::CThostFtdcRspTransferField pRspTransfer);
private:
	delegate void cppRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);
	void cppcbRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer)
	{
		CTPTradeApi::CThostFtdcRspTransferField  cspRspTransfer = (CTPTradeApi::CThostFtdcRspTransferField) Marshal::PtrToStructure(IntPtr(pRspTransfer), CTPTradeApi::CThostFtdcRspTransferField::typeid);
		OnRtnFromBankToFutureByBank(cspRspTransfer);
	}
public:
	/// <summary>
	/// 银行发起银行资金转期货通知
	/// </summary>
	event RtnFromBankToFutureByBank ^OnRtnFromBankToFutureByBank;


public:
	delegate void RtnFromBankToFutureByFuture(CTPTradeApi::CThostFtdcRspTransferField pRspTransfer);
private:
	delegate void cppRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);
	void cppcbRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
	{
		CTPTradeApi::CThostFtdcRspTransferField  cspRspTransfer = (CTPTradeApi::CThostFtdcRspTransferField) Marshal::PtrToStructure(IntPtr(pRspTransfer), CTPTradeApi::CThostFtdcRspTransferField::typeid);
		OnRtnFromBankToFutureByFuture(cspRspTransfer);
	}
public:
	/// <summary>
	/// 期货发起银行资金转期货通知
	/// </summary>
	event RtnFromBankToFutureByFuture ^OnRtnFromBankToFutureByFuture;


public:
	delegate void RtnFromFutureToBankByBank(CTPTradeApi::CThostFtdcRspTransferField pRspTransfer);
private:
	delegate void cppRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);
	void cppcbRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer)
	{
		CTPTradeApi::CThostFtdcRspTransferField  cspRspTransfer = (CTPTradeApi::CThostFtdcRspTransferField) Marshal::PtrToStructure(IntPtr(pRspTransfer), CTPTradeApi::CThostFtdcRspTransferField::typeid);
		OnRtnFromFutureToBankByBank(cspRspTransfer);
	}
public:
	/// <summary>
	/// 银行发起期货资金转银行通知
	/// </summary>
	event RtnFromFutureToBankByBank ^OnRtnFromFutureToBankByBank;


public:
	delegate void RtnFromFutureToBankByFuture(CTPTradeApi::CThostFtdcRspTransferField pRspTransfer);
private:
	delegate void cppRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
	void cppcbRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
	{
		CTPTradeApi::CThostFtdcRspTransferField  cspRspTransfer = (CTPTradeApi::CThostFtdcRspTransferField) Marshal::PtrToStructure(IntPtr(pRspTransfer), CTPTradeApi::CThostFtdcRspTransferField::typeid);
		OnRtnFromFutureToBankByFuture(cspRspTransfer);
	}
public:
	/// <summary>
	/// 期货发起期货资金转银行通知
	/// </summary>
	event RtnFromFutureToBankByFuture ^OnRtnFromFutureToBankByFuture;


public:
	delegate void RtnInstrumentStatus(CTPTradeApi::CThostFtdcInstrumentStatusField pInstrumentStatus);
private:
	delegate void cppRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);
	void cppcbRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus)
	{
		CTPTradeApi::CThostFtdcInstrumentStatusField  cspInstrumentStatus = (CTPTradeApi::CThostFtdcInstrumentStatusField) Marshal::PtrToStructure(IntPtr(pInstrumentStatus), CTPTradeApi::CThostFtdcInstrumentStatusField::typeid);
		OnRtnInstrumentStatus(cspInstrumentStatus);
	}
public:
	/// <summary>
	/// 合约交易状态通知
	/// </summary>
	event RtnInstrumentStatus ^OnRtnInstrumentStatus;


public:
	delegate void RtnOrder(CTPTradeApi::CThostFtdcOrderField pOrder);
private:
	delegate void cppRtnOrder(CThostFtdcOrderField *pOrder);
	void cppcbRtnOrder(CThostFtdcOrderField *pOrder)
	{
		CTPTradeApi::CThostFtdcOrderField  cspOrder = (CTPTradeApi::CThostFtdcOrderField) Marshal::PtrToStructure(IntPtr(pOrder), CTPTradeApi::CThostFtdcOrderField::typeid);
		OnRtnOrder(cspOrder);
	}
public:
	/// <summary>
	/// 报单通知
	/// </summary>
	event RtnOrder ^OnRtnOrder;


public:
	delegate void RtnQueryBankBalanceByFuture(CTPTradeApi::CThostFtdcNotifyQueryAccountField pNotifyQueryAccount);
private:
	delegate void cppRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
	void cppcbRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
	{
		CTPTradeApi::CThostFtdcNotifyQueryAccountField  cspNotifyQueryAccount = (CTPTradeApi::CThostFtdcNotifyQueryAccountField) Marshal::PtrToStructure(IntPtr(pNotifyQueryAccount), CTPTradeApi::CThostFtdcNotifyQueryAccountField::typeid);
		OnRtnQueryBankBalanceByFuture(cspNotifyQueryAccount);
	}
public:
	/// <summary>
	/// 期货发起查询银行余额通知
	/// </summary>
	event RtnQueryBankBalanceByFuture ^OnRtnQueryBankBalanceByFuture;


public:
	delegate void RtnRepealFromBankToFutureByBank(CTPTradeApi::CThostFtdcRspRepealField pRspRepeal);
private:
	delegate void cppRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal)
	{
		CTPTradeApi::CThostFtdcRspRepealField  cspRspRepeal = (CTPTradeApi::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPTradeApi::CThostFtdcRspRepealField::typeid);
		OnRtnRepealFromBankToFutureByBank(cspRspRepeal);
	}
public:
	/// <summary>
	/// 银行发起冲正银行转期货通知
	/// </summary>
	event RtnRepealFromBankToFutureByBank ^OnRtnRepealFromBankToFutureByBank;


public:
	delegate void RtnRepealFromBankToFutureByFuture(CTPTradeApi::CThostFtdcRspRepealField pRspRepeal);
private:
	delegate void cppRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal)
	{
		CTPTradeApi::CThostFtdcRspRepealField  cspRspRepeal = (CTPTradeApi::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPTradeApi::CThostFtdcRspRepealField::typeid);
		OnRtnRepealFromBankToFutureByFuture(cspRspRepeal);
	}
public:
	/// <summary>
	/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	/// </summary>
	event RtnRepealFromBankToFutureByFuture ^OnRtnRepealFromBankToFutureByFuture;


public:
	delegate void RtnRepealFromBankToFutureByFutureManual(CTPTradeApi::CThostFtdcRspRepealField pRspRepeal);
private:
	delegate void cppRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
	{
		CTPTradeApi::CThostFtdcRspRepealField  cspRspRepeal = (CTPTradeApi::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPTradeApi::CThostFtdcRspRepealField::typeid);
		OnRtnRepealFromBankToFutureByFutureManual(cspRspRepeal);
	}
public:
	/// <summary>
	/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
	/// </summary>
	event RtnRepealFromBankToFutureByFutureManual ^OnRtnRepealFromBankToFutureByFutureManual;


public:
	delegate void RtnRepealFromFutureToBankByBank(CTPTradeApi::CThostFtdcRspRepealField pRspRepeal);
private:
	delegate void cppRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal)
	{
		CTPTradeApi::CThostFtdcRspRepealField  cspRspRepeal = (CTPTradeApi::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPTradeApi::CThostFtdcRspRepealField::typeid);
		OnRtnRepealFromFutureToBankByBank(cspRspRepeal);
	}
public:
	/// <summary>
	/// 银行发起冲正期货转银行通知
	/// </summary>
	event RtnRepealFromFutureToBankByBank ^OnRtnRepealFromFutureToBankByBank;


public:
	delegate void RtnRepealFromFutureToBankByFuture(CTPTradeApi::CThostFtdcRspRepealField pRspRepeal);
private:
	delegate void cppRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal)
	{
		CTPTradeApi::CThostFtdcRspRepealField  cspRspRepeal = (CTPTradeApi::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPTradeApi::CThostFtdcRspRepealField::typeid);
		OnRtnRepealFromFutureToBankByFuture(cspRspRepeal);
	}
public:
	/// <summary>
	/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	/// </summary>
	event RtnRepealFromFutureToBankByFuture ^OnRtnRepealFromFutureToBankByFuture;


public:
	delegate void RtnRepealFromFutureToBankByFutureManual(CTPTradeApi::CThostFtdcRspRepealField pRspRepeal);
private:
	delegate void cppRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
	{
		CTPTradeApi::CThostFtdcRspRepealField  cspRspRepeal = (CTPTradeApi::CThostFtdcRspRepealField) Marshal::PtrToStructure(IntPtr(pRspRepeal), CTPTradeApi::CThostFtdcRspRepealField::typeid);
		OnRtnRepealFromFutureToBankByFutureManual(cspRspRepeal);
	}
public:
	/// <summary>
	/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
	/// </summary>
	event RtnRepealFromFutureToBankByFutureManual ^OnRtnRepealFromFutureToBankByFutureManual;


public:
	delegate void RtnTrade(CTPTradeApi::CThostFtdcTradeField pTrade);
private:
	delegate void cppRtnTrade(CThostFtdcTradeField *pTrade);
	void cppcbRtnTrade(CThostFtdcTradeField *pTrade)
	{
		CTPTradeApi::CThostFtdcTradeField  cspTrade = (CTPTradeApi::CThostFtdcTradeField) Marshal::PtrToStructure(IntPtr(pTrade), CTPTradeApi::CThostFtdcTradeField::typeid);
		OnRtnTrade(cspTrade);
	}
public:
	/// <summary>
	/// 成交通知
	/// </summary>
	event RtnTrade ^OnRtnTrade;


public:
	delegate void RtnTradingNotice(CTPTradeApi::CThostFtdcTradingNoticeInfoField pTradingNoticeInfo);
private:
	delegate void cppRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
	void cppcbRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo)
	{
		CTPTradeApi::CThostFtdcTradingNoticeInfoField  cspTradingNoticeInfo = (CTPTradeApi::CThostFtdcTradingNoticeInfoField) Marshal::PtrToStructure(IntPtr(pTradingNoticeInfo), CTPTradeApi::CThostFtdcTradingNoticeInfoField::typeid);
		OnRtnTradingNotice(cspTradingNoticeInfo);
	}
public:
	/// <summary>
	/// 交易通知
	/// </summary>
	event RtnTradingNotice ^OnRtnTradingNotice;






private:
	CTraderSpi *pUserSpi = nullptr;
	CThostFtdcTraderApi * pUserApi = nullptr;
	int lRequestID = 0;
};


#include "stdafx.h"
#include "TradeApi.h"
#include <string>
#include "ICTPTradeApi.h"

using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

namespace CTPCLR
{
public ref class TradeApiclr :ICTPTradeApi
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
	}
	
	virtual ~TradeApiclr(){

		for each (GCHandle var in gchlist)
		{
			var.Free();
		}
	}

	virtual void Init()
	{
		pUserApi->Init();
	}

	/// <summary>
	/// 前置地址
	/// </summary>
	virtual	property  System::String ^ FrontAddr;
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
		CThostFtdcSettlementInfoConfirmField req;
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
	virtual int ReqOrderAction(CTPCommon::CThostFtdcInputOrderActionField pInputOrderAction, [Out]  int %nRequestID)
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
	virtual int ReqAuthenticate(CTPCommon::CThostFtdcReqAuthenticateField pReqAuthenticateField, [Out]  int %nRequestID)
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
	virtual int ReqUserLogin(CTPCommon::CThostFtdcReqUserLoginField pReqUserLoginField, [Out]  int %nRequestID)
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
	virtual int ReqUserLogout(CTPCommon::CThostFtdcUserLogoutField pUserLogout, [Out]  int %nRequestID)
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
	virtual int ReqUserPasswordUpdate(CTPCommon::CThostFtdcUserPasswordUpdateField pUserPasswordUpdate, [Out]  int %nRequestID)
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
	virtual int ReqTradingAccountPasswordUpdate(CTPCommon::CThostFtdcTradingAccountPasswordUpdateField pTradingAccountPasswordUpdate, [Out]  int %nRequestID)
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
	virtual int ReqParkedOrderInsert(CTPCommon::CThostFtdcParkedOrderField pParkedOrder, [Out]  int %nRequestID)
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
	virtual int ReqParkedOrderAction(CTPCommon::CThostFtdcParkedOrderActionField pParkedOrderAction, [Out]  int %nRequestID)
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
	virtual int ReqQueryMaxOrderVolume(CTPCommon::CThostFtdcQueryMaxOrderVolumeField pQueryMaxOrderVolume, [Out]  int %nRequestID)
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
	virtual int ReqSettlementInfoConfirm(CTPCommon::CThostFtdcSettlementInfoConfirmField pSettlementInfoConfirm, [Out]  int %nRequestID)
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
	virtual int ReqRemoveParkedOrder(CTPCommon::CThostFtdcRemoveParkedOrderField pRemoveParkedOrder, [Out]  int %nRequestID)
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
	virtual int ReqRemoveParkedOrderAction(CTPCommon::CThostFtdcRemoveParkedOrderActionField pRemoveParkedOrderAction, [Out]  int %nRequestID)
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
	virtual int ReqQryOrder(CTPCommon::CThostFtdcQryOrderField pQryOrder, [Out]  int %nRequestID)
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
	virtual int ReqQryTrade(CTPCommon::CThostFtdcQryTradeField pQryTrade, [Out]  int %nRequestID)
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
	virtual int ReqQryInvestorPosition(CTPCommon::CThostFtdcQryInvestorPositionField pQryInvestorPosition, [Out]  int %nRequestID)
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
	virtual int ReqQryTradingAccount(CTPCommon::CThostFtdcQryTradingAccountField pQryTradingAccount, [Out]  int %nRequestID)
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
	virtual int ReqQryInvestor(CTPCommon::CThostFtdcQryInvestorField pQryInvestor, [Out]  int %nRequestID)
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
	virtual int ReqQryTradingCode(CTPCommon::CThostFtdcQryTradingCodeField pQryTradingCode, [Out]  int %nRequestID)
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
	virtual int ReqQryInstrumentMarginRate(CTPCommon::CThostFtdcQryInstrumentMarginRateField pQryInstrumentMarginRate, [Out]  int %nRequestID)
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
	virtual int ReqQryInstrumentCommissionRate(CTPCommon::CThostFtdcQryInstrumentCommissionRateField pQryInstrumentCommissionRate, [Out]  int %nRequestID)
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
	virtual int ReqQryExchange(CTPCommon::CThostFtdcQryExchangeField pQryExchange, [Out]  int %nRequestID)
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
	virtual int ReqQryInstrument(CTPCommon::CThostFtdcQryInstrumentField pQryInstrument, [Out]  int %nRequestID)
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
	virtual int ReqQryDepthMarketData(CTPCommon::CThostFtdcQryDepthMarketDataField pQryDepthMarketData, [Out]  int %nRequestID)
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
	virtual int ReqQrySettlementInfo(CTPCommon::CThostFtdcQrySettlementInfoField pQrySettlementInfo, [Out]  int %nRequestID)
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
	virtual int ReqQryTransferBank(CTPCommon::CThostFtdcQryTransferBankField pQryTransferBank, [Out]  int %nRequestID)
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
	virtual int ReqQryInvestorPositionDetail(CTPCommon::CThostFtdcQryInvestorPositionDetailField pQryInvestorPositionDetail, [Out]  int %nRequestID)
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
	virtual int ReqQryNotice(CTPCommon::CThostFtdcQryNoticeField pQryNotice, [Out]  int %nRequestID)
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
	virtual int ReqQrySettlementInfoConfirm(CTPCommon::CThostFtdcQrySettlementInfoConfirmField pQrySettlementInfoConfirm, [Out]  int %nRequestID)
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
	virtual int ReqQryInvestorPositionCombineDetail(CTPCommon::CThostFtdcQryInvestorPositionCombineDetailField pQryInvestorPositionCombineDetail, [Out]  int %nRequestID)
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
	virtual int ReqQryCFMMCTradingAccountKey(CTPCommon::CThostFtdcQryCFMMCTradingAccountKeyField pQryCFMMCTradingAccountKey, [Out]  int %nRequestID)
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
	virtual int ReqQryEWarrantOffset(CTPCommon::CThostFtdcQryEWarrantOffsetField pQryEWarrantOffset, [Out]  int %nRequestID)
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
	virtual int ReqQryInvestorProductGroupMargin(CTPCommon::CThostFtdcQryInvestorProductGroupMarginField pQryInvestorProductGroupMargin, [Out]  int %nRequestID)
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
	virtual int ReqQryExchangeMarginRate(CTPCommon::CThostFtdcQryExchangeMarginRateField pQryExchangeMarginRate, [Out]  int %nRequestID)
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
	virtual int ReqQryExchangeMarginRateAdjust(CTPCommon::CThostFtdcQryExchangeMarginRateAdjustField pQryExchangeMarginRateAdjust, [Out]  int %nRequestID)
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
	virtual int ReqQryTransferSerial(CTPCommon::CThostFtdcQryTransferSerialField pQryTransferSerial, [Out]  int %nRequestID)
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
	virtual int ReqQryAccountregister(CTPCommon::CThostFtdcQryAccountregisterField pQryAccountregister, [Out]  int %nRequestID)
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
	virtual int ReqQryContractBank(CTPCommon::CThostFtdcQryContractBankField pQryContractBank, [Out]  int %nRequestID)
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
	virtual int ReqQryParkedOrder(CTPCommon::CThostFtdcQryParkedOrderField pQryParkedOrder, [Out]  int %nRequestID)
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
	virtual int ReqQryParkedOrderAction(CTPCommon::CThostFtdcQryParkedOrderActionField pQryParkedOrderAction, [Out]  int %nRequestID)
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
	virtual int ReqQryTradingNotice(CTPCommon::CThostFtdcQryTradingNoticeField pQryTradingNotice, [Out]  int %nRequestID)
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
	virtual int ReqQryBrokerTradingParams(CTPCommon::CThostFtdcQryBrokerTradingParamsField pQryBrokerTradingParams, [Out]  int %nRequestID)
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
	virtual int ReqQryBrokerTradingAlgos(CTPCommon::CThostFtdcQryBrokerTradingAlgosField pQryBrokerTradingAlgos, [Out]  int %nRequestID)
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
	virtual int ReqFromBankToFutureByFuture(CTPCommon::CThostFtdcReqTransferField pReqTransfer, [Out]  int %nRequestID)
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
	virtual int ReqFromFutureToBankByFuture(CTPCommon::CThostFtdcReqTransferField pReqTransfer, [Out]  int %nRequestID)
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
	virtual int ReqQueryBankAccountMoneyByFuture(CTPCommon::CThostFtdcReqQueryAccountField pReqQueryAccount, [Out]  int %nRequestID)
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
				cppRspAuthenticate^ fp = gcnew cppRspAuthenticate(this, &TradeApiclr::cppcbRspAuthenticate);
				GCHandle gch = GCHandle::Alloc(fp);
				gchlist->Add(gch);
				IntPtr ip = Marshal::GetFunctionPointerForDelegate(fp);
				CBRspAuthenticate cb = static_cast<CBRspAuthenticate>(ip.ToPointer());
				pUserSpi->cbRspAuthenticate = cb;
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
	delegate void cppErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
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
	delegate void cppErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
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
	delegate void cppErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo)
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
	delegate void cppErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
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
	delegate void cppErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo)
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
	delegate void cppErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
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
	delegate void cppErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo);
	void cppcbErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
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
	delegate void cppRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
	{
		CTPCommon::CThostFtdcInvestorPositionDetailField  cspInvestorPositionDetail = (CTPCommon::CThostFtdcInvestorPositionDetailField) Marshal::PtrToStructure(IntPtr(pInvestorPositionDetail), CTPCommon::CThostFtdcInvestorPositionDetailField::typeid); CTPCommon::CThostFtdcRspInfoField  cspRspInfo = (CTPCommon::CThostFtdcRspInfoField) Marshal::PtrToStructure(IntPtr(pRspInfo), CTPCommon::CThostFtdcRspInfoField::typeid);
		OnRspQryInvestorPositionDetail(cspInvestorPositionDetail, cspRspInfo, nRequestID, bIsLast);
	}
public:
	/// <summary>
	/// 请求查询投资者持仓明细响应
	/// </summary>
 virtual event RspQryInvestorPositionDetail ^OnRspQryInvestorPositionDetail;


private:
	delegate void cppRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
 virtual event RspUserLogout ^OnRspUserLogout;


private:
	delegate void cppRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
	void cppcbRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
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
	delegate void cppRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder);
	void cppcbRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder)
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
	delegate void cppRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer);
	void cppcbRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer)
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
	delegate void cppRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer);
	void cppcbRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
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
	delegate void cppRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer);
	void cppcbRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer)
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
	delegate void cppRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer);
	void cppcbRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
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
	delegate void cppRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus);
	void cppcbRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus)
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
	delegate void cppRtnOrder(CThostFtdcOrderField *pOrder);
	void cppcbRtnOrder(CThostFtdcOrderField *pOrder)
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
	delegate void cppRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount);
	void cppcbRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
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
	delegate void cppRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal)
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
	delegate void cppRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal)
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
	delegate void cppRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
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
	delegate void cppRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal)
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
	delegate void cppRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal)
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
	delegate void cppRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal);
	void cppcbRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
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
	delegate void cppRtnTrade(CThostFtdcTradeField *pTrade);
	void cppcbRtnTrade(CThostFtdcTradeField *pTrade)
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
	delegate void cppRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo);
	void cppcbRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo)
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
	CTraderSpi *pUserSpi = nullptr;
	CThostFtdcTraderApi * pUserApi = nullptr;
	int lRequestID = 0;
};

}
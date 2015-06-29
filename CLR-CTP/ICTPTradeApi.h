using namespace System;
using namespace System::Runtime::InteropServices;
using namespace System::Threading;

#include "eventDelegate.h"

namespace CTPCLR
{
	public interface class ICTPTradeApi
	{
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
		int SettlementInfoConfirm([Out]  int %nRequestID);


		/// <summary>
		///报单录入请求
		/// </summary>
		int ReqOrderInsert(CTPCommon::CThostFtdcInputOrderField pInputOrder, [Out]  int %nRequestID);

		/// <summary>
		///报单操作请求
		/// </summary>
		int ReqOrderAction(CTPCommon::CThostFtdcInputOrderActionField pInputOrderAction, [Out]  int %nRequestID);



		/// <summary>
		///客户端认证请求
		/// </summary>
		int ReqAuthenticate(CTPCommon::CThostFtdcReqAuthenticateField pReqAuthenticateField, [Out]  int %nRequestID);

		/// <summary>
		///用户登录请求
		/// </summary>
		int ReqUserLogin(CTPCommon::CThostFtdcReqUserLoginField pReqUserLoginField, [Out]  int %nRequestID);

		/// <summary>
		///登出请求
		/// </summary>
		int ReqUserLogout(CTPCommon::CThostFtdcUserLogoutField pUserLogout, [Out]  int %nRequestID);

		/// <summary>
		///用户口令更新请求
		/// </summary>
		int ReqUserPasswordUpdate(CTPCommon::CThostFtdcUserPasswordUpdateField pUserPasswordUpdate, [Out]  int %nRequestID);

		/// <summary>
		///资金账户口令更新请求
		/// </summary>
		int ReqTradingAccountPasswordUpdate(CTPCommon::CThostFtdcTradingAccountPasswordUpdateField pTradingAccountPasswordUpdate, [Out]  int %nRequestID);



		/// <summary>
		///预埋单录入请求
		/// </summary>
		int ReqParkedOrderInsert(CTPCommon::CThostFtdcParkedOrderField pParkedOrder, [Out]  int %nRequestID);

		/// <summary>
		///预埋撤单录入请求
		/// </summary>
		int ReqParkedOrderAction(CTPCommon::CThostFtdcParkedOrderActionField pParkedOrderAction, [Out]  int %nRequestID);



		/// <summary>
		///查询最大报单数量请求
		/// </summary>
		int ReqQueryMaxOrderVolume(CTPCommon::CThostFtdcQueryMaxOrderVolumeField pQueryMaxOrderVolume, [Out]  int %nRequestID);

		/// <summary>
		///投资者结算结果确认
		/// </summary>
		int ReqSettlementInfoConfirm(CTPCommon::CThostFtdcSettlementInfoConfirmField pSettlementInfoConfirm, [Out]  int %nRequestID);

		/// <summary>
		///请求删除预埋单
		/// </summary>
		int ReqRemoveParkedOrder(CTPCommon::CThostFtdcRemoveParkedOrderField pRemoveParkedOrder, [Out]  int %nRequestID);

		/// <summary>
		///请求删除预埋撤单
		/// </summary>
		int ReqRemoveParkedOrderAction(CTPCommon::CThostFtdcRemoveParkedOrderActionField pRemoveParkedOrderAction, [Out]  int %nRequestID);

		/// <summary>
		///请求查询报单
		/// </summary>
		int ReqQryOrder(CTPCommon::CThostFtdcQryOrderField pQryOrder, [Out]  int %nRequestID);

		/// <summary>
		///请求查询成交
		/// </summary>
		int ReqQryTrade(CTPCommon::CThostFtdcQryTradeField pQryTrade, [Out]  int %nRequestID);

		/// <summary>
		///请求查询投资者持仓
		/// </summary>
		int ReqQryInvestorPosition(CTPCommon::CThostFtdcQryInvestorPositionField pQryInvestorPosition, [Out]  int %nRequestID);

		/// <summary>
		///请求查询资金账户
		/// </summary>
		int ReqQryTradingAccount(CTPCommon::CThostFtdcQryTradingAccountField pQryTradingAccount, [Out]  int %nRequestID);

		/// <summary>
		///请求查询投资者
		/// </summary>
		int ReqQryInvestor(CTPCommon::CThostFtdcQryInvestorField pQryInvestor, [Out]  int %nRequestID);

		/// <summary>
		///请求查询交易编码
		/// </summary>
		int ReqQryTradingCode(CTPCommon::CThostFtdcQryTradingCodeField pQryTradingCode, [Out]  int %nRequestID);

		/// <summary>
		///请求查询合约保证金率
		/// </summary>
		int ReqQryInstrumentMarginRate(CTPCommon::CThostFtdcQryInstrumentMarginRateField pQryInstrumentMarginRate, [Out]  int %nRequestID);

		/// <summary>
		///请求查询合约手续费率
		/// </summary>
		int ReqQryInstrumentCommissionRate(CTPCommon::CThostFtdcQryInstrumentCommissionRateField pQryInstrumentCommissionRate, [Out]  int %nRequestID);

		/// <summary>
		///请求查询交易所
		/// </summary>
		int ReqQryExchange(CTPCommon::CThostFtdcQryExchangeField pQryExchange, [Out]  int %nRequestID);

		/// <summary>
		///请求查询合约
		/// </summary>
		int ReqQryInstrument(CTPCommon::CThostFtdcQryInstrumentField pQryInstrument, [Out]  int %nRequestID);

		/// <summary>
		///请求查询行情
		/// </summary>
		int ReqQryDepthMarketData(CTPCommon::CThostFtdcQryDepthMarketDataField pQryDepthMarketData, [Out]  int %nRequestID);

		/// <summary>
		///请求查询投资者结算结果
		/// </summary>
		int ReqQrySettlementInfo(CTPCommon::CThostFtdcQrySettlementInfoField pQrySettlementInfo, [Out]  int %nRequestID);

		/// <summary>
		///请求查询转帐银行
		/// </summary>
		int ReqQryTransferBank(CTPCommon::CThostFtdcQryTransferBankField pQryTransferBank, [Out]  int %nRequestID);

		/// <summary>
		///请求查询投资者持仓明细
		/// </summary>
		int ReqQryInvestorPositionDetail(CTPCommon::CThostFtdcQryInvestorPositionDetailField pQryInvestorPositionDetail, [Out]  int %nRequestID);

		/// <summary>
		///请求查询客户通知
		/// </summary>
		int ReqQryNotice(CTPCommon::CThostFtdcQryNoticeField pQryNotice, [Out]  int %nRequestID);

		/// <summary>
		///请求查询结算信息确认
		/// </summary>
		int ReqQrySettlementInfoConfirm(CTPCommon::CThostFtdcQrySettlementInfoConfirmField pQrySettlementInfoConfirm, [Out]  int %nRequestID);

		/// <summary>
		///请求查询投资者持仓明细
		/// </summary>
		int ReqQryInvestorPositionCombineDetail(CTPCommon::CThostFtdcQryInvestorPositionCombineDetailField pQryInvestorPositionCombineDetail, [Out]  int %nRequestID);

		/// <summary>
		///请求查询保证金监管系统经纪公司资金账户密钥
		/// </summary>
		int ReqQryCFMMCTradingAccountKey(CTPCommon::CThostFtdcQryCFMMCTradingAccountKeyField pQryCFMMCTradingAccountKey, [Out]  int %nRequestID);

		/// <summary>
		///请求查询仓单折抵信息
		/// </summary>
		int ReqQryEWarrantOffset(CTPCommon::CThostFtdcQryEWarrantOffsetField pQryEWarrantOffset, [Out]  int %nRequestID);

		/// <summary>
		///请求查询投资者品种/跨品种保证金
		/// </summary>
		int ReqQryInvestorProductGroupMargin(CTPCommon::CThostFtdcQryInvestorProductGroupMarginField pQryInvestorProductGroupMargin, [Out]  int %nRequestID);

		/// <summary>
		///请求查询交易所保证金率
		/// </summary>
		int ReqQryExchangeMarginRate(CTPCommon::CThostFtdcQryExchangeMarginRateField pQryExchangeMarginRate, [Out]  int %nRequestID);

		/// <summary>
		///请求查询交易所调整保证金率
		/// </summary>
		int ReqQryExchangeMarginRateAdjust(CTPCommon::CThostFtdcQryExchangeMarginRateAdjustField pQryExchangeMarginRateAdjust, [Out]  int %nRequestID);

		/// <summary>
		///请求查询转帐流水
		/// </summary>
		int ReqQryTransferSerial(CTPCommon::CThostFtdcQryTransferSerialField pQryTransferSerial, [Out]  int %nRequestID);

		/// <summary>
		///请求查询银期签约关系
		/// </summary>
		int ReqQryAccountregister(CTPCommon::CThostFtdcQryAccountregisterField pQryAccountregister, [Out]  int %nRequestID);

		/// <summary>
		///请求查询签约银行
		/// </summary>
		int ReqQryContractBank(CTPCommon::CThostFtdcQryContractBankField pQryContractBank, [Out]  int %nRequestID);

		/// <summary>
		///请求查询预埋单
		/// </summary>
		int ReqQryParkedOrder(CTPCommon::CThostFtdcQryParkedOrderField pQryParkedOrder, [Out]  int %nRequestID);

		/// <summary>
		///请求查询预埋撤单
		/// </summary>
		int ReqQryParkedOrderAction(CTPCommon::CThostFtdcQryParkedOrderActionField pQryParkedOrderAction, [Out]  int %nRequestID);

		/// <summary>
		///请求查询交易通知
		/// </summary>
		int ReqQryTradingNotice(CTPCommon::CThostFtdcQryTradingNoticeField pQryTradingNotice, [Out]  int %nRequestID);

		/// <summary>
		///请求查询经纪公司交易参数
		/// </summary>
		int ReqQryBrokerTradingParams(CTPCommon::CThostFtdcQryBrokerTradingParamsField pQryBrokerTradingParams, [Out]  int %nRequestID);

		/// <summary>
		///请求查询经纪公司交易算法
		/// </summary>
		int ReqQryBrokerTradingAlgos(CTPCommon::CThostFtdcQryBrokerTradingAlgosField pQryBrokerTradingAlgos, [Out]  int %nRequestID);

		/// <summary>
		///期货发起银行资金转期货请求
		/// </summary>
		int ReqFromBankToFutureByFuture(CTPCommon::CThostFtdcReqTransferField pReqTransfer, [Out]  int %nRequestID);

		/// <summary>
		///期货发起期货资金转银行请求
		/// </summary>
		int ReqFromFutureToBankByFuture(CTPCommon::CThostFtdcReqTransferField pReqTransfer, [Out]  int %nRequestID);

		/// <summary>
		///期货发起查询银行余额请求
		/// </summary>
		int ReqQueryBankAccountMoneyByFuture(CTPCommon::CThostFtdcReqQueryAccountField pReqQueryAccount, [Out]  int %nRequestID);




		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// </summary>
		event FrontConnect ^OnFrontConnect;

		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// </summary>
		event DisConnected ^OnDisConnected;

		/// <summary>
		/// 心跳超时警告。当长时间未收到报文时，该方法被调用。
		/// </summary>
		event HeartBeatWarning ^OnHeartBeatWarning;

		/// <summary>
		/// 期货发起银行资金转期货错误回报
		/// </summary>
		event ErrRtnBankToFutureByFuture ^OnErrRtnBankToFutureByFuture;

		/// <summary>
		/// 期货发起期货资金转银行错误回报
		/// </summary>
		event ErrRtnFutureToBankByFuture ^OnErrRtnFutureToBankByFuture;

		/// <summary>
		/// 报单操作错误回报
		/// </summary>
		event ErrRtnOrderAction ^OnErrRtnOrderAction;

		/// <summary>
		/// 报单录入错误回报
		/// </summary>
		event ErrRtnOrderInsert ^OnErrRtnOrderInsert;

		/// <summary>
		/// 期货发起查询银行余额错误回报
		/// </summary>
		event ErrRtnQueryBankBalanceByFuture ^OnErrRtnQueryBankBalanceByFuture;

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报
		/// </summary>
		event ErrRtnRepealBankToFutureByFutureManual ^OnErrRtnRepealBankToFutureByFutureManual;

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报
		/// </summary>
		event ErrRtnRepealFutureToBankByFutureManual ^OnErrRtnRepealFutureToBankByFutureManual;

		/// <summary>
		/// 错误应答
		/// </summary>
		event RspError ^OnRspError;

		/// <summary>
		/// 期货发起银行资金转期货应答
		/// </summary>
		event RspFromBankToFutureByFuture ^OnRspFromBankToFutureByFuture;

		/// <summary>
		/// 期货发起期货资金转银行应答
		/// </summary>
		event RspFromFutureToBankByFuture ^OnRspFromFutureToBankByFuture;

		/// <summary>
		/// 报单操作请求响应
		/// </summary>
		event RspOrderAction ^OnRspOrderAction;

		/// <summary>
		/// 报单录入请求响应
		/// </summary>
		event RspOrderInsert ^OnRspOrderInsert;

		/// <summary>
		/// 预埋撤单录入请求响应
		/// </summary>
		event RspParkedOrderAction ^OnRspParkedOrderAction;

		/// <summary>
		/// 预埋单录入请求响应
		/// </summary>
		event RspParkedOrderInsert ^OnRspParkedOrderInsert;

		/// <summary>
		/// 请求查询经纪公司交易算法响应
		/// </summary>
		event RspQryBrokerTradingAlgos ^OnRspQryBrokerTradingAlgos;

		/// <summary>
		/// 请求查询经纪公司交易参数响应
		/// </summary>
		event RspQryBrokerTradingParams ^OnRspQryBrokerTradingParams;

		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应
		/// </summary>
		event RspQryCFMMCTradingAccountKey ^OnRspQryCFMMCTradingAccountKey;

		/// <summary>
		/// 请求查询签约银行响应
		/// </summary>
		event RspQryContractBank ^OnRspQryContractBank;

		/// <summary>
		/// 请求查询行情响应
		/// </summary>
		event RspQryDepthMarketData ^OnRspQryDepthMarketData;

		/// <summary>
		/// 请求查询交易所响应
		/// </summary>
		event RspQryExchange ^OnRspQryExchange;

		/// <summary>
		/// 请求查询合约响应
		/// </summary>
		event RspQryInstrument ^OnRspQryInstrument;

		/// <summary>
		/// 请求查询合约手续费率响应
		/// </summary>
		event RspQryInstrumentCommissionRate ^OnRspQryInstrumentCommissionRate;

		/// <summary>
		/// 请求查询合约保证金率响应
		/// </summary>
		event RspQryInstrumentMarginRate ^OnRspQryInstrumentMarginRate;

		/// <summary>
		/// 请求查询投资者响应
		/// </summary>
		event RspQryInvestor ^OnRspQryInvestor;

		/// <summary>
		/// 请求查询投资者持仓响应
		/// </summary>
		event RspQryInvestorPosition ^OnRspQryInvestorPosition;

		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// </summary>
		event RspQryInvestorPositionCombineDetail ^OnRspQryInvestorPositionCombineDetail;

		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// </summary>
		event RspQryInvestorPositionDetail ^OnRspQryInvestorPositionDetail;

		/// <summary>
		/// 请求查询客户通知响应
		/// </summary>
		event RspQryNotice ^OnRspQryNotice;

		/// <summary>
		/// 请求查询报单响应
		/// </summary>
		event RspQryOrder ^OnRspQryOrder;

		/// <summary>
		/// 请求查询预埋单响应
		/// </summary>
		event RspQryParkedOrder ^OnRspQryParkedOrder;

		/// <summary>
		/// 请求查询预埋撤单响应
		/// </summary>
		event RspQryParkedOrderAction ^OnRspQryParkedOrderAction;

		/// <summary>
		/// 请求查询投资者结算结果响应
		/// </summary>
		event RspQrySettlementInfo ^OnRspQrySettlementInfo;

		/// <summary>
		/// 请求查询结算信息确认响应
		/// </summary>
		event RspQrySettlementInfoConfirm ^OnRspQrySettlementInfoConfirm;

		/// <summary>
		/// 请求查询成交响应
		/// </summary>
		event RspQryTrade ^OnRspQryTrade;

		/// <summary>
		/// 请求查询资金账户响应
		/// </summary>
		event RspQryTradingAccount ^OnRspQryTradingAccount;

		/// <summary>
		/// 请求查询交易编码响应
		/// </summary>
		event RspQryTradingCode ^OnRspQryTradingCode;

		/// <summary>
		/// 请求查询交易通知响应
		/// </summary>
		event RspQryTradingNotice ^OnRspQryTradingNotice;

		/// <summary>
		/// 请求查询转帐银行响应
		/// </summary>
		event RspQryTransferBank ^OnRspQryTransferBank;

		/// <summary>
		/// 请求查询转帐流水响应
		/// </summary>
		event RspQryTransferSerial ^OnRspQryTransferSerial;

		/// <summary>
		/// 请求查询转帐流水响应
		/// </summary>
		event RspQryAccountregister ^OnRspQryAccountregister;

		/// <summary>
		/// 期货发起查询银行余额应答
		/// </summary>
		event RspQueryBankAccountMoneyByFuture ^OnRspQueryBankAccountMoneyByFuture;

		/// <summary>
		/// 查询最大报单数量响应
		/// </summary>
		event RspQueryMaxOrderVolume ^OnRspQueryMaxOrderVolume;

		/// <summary>
		/// 删除预埋单响应
		/// </summary>
		event RspRemoveParkedOrder ^OnRspRemoveParkedOrder;

		/// <summary>
		/// 删除预埋撤单响应
		/// </summary>
		event RspRemoveParkedOrderAction ^OnRspRemoveParkedOrderAction;

		/// <summary>
		/// 投资者结算结果确认响应
		/// </summary>
		event RspSettlementInfoConfirm ^OnRspSettlementInfoConfirm;

		/// <summary>
		/// 资金账户口令更新请求响应
		/// </summary>
		event RspTradingAccountPasswordUpdate ^OnRspTradingAccountPasswordUpdate;


		/// <summary>
		/// 
		/// </summary>
		event RspAuthenticate ^OnRspAuthenticate;

		/// <summary>
		/// 登录请求响应
		/// </summary>
		event RspUserLogin ^OnRspUserLogin;

		/// <summary>
		/// 登出请求响应
		/// </summary>
		event RspUserLogout ^OnRspUserLogout;

		/// <summary>
		/// 用户口令更新请求响应
		/// </summary>
		event RspUserPasswordUpdate ^OnRspUserPasswordUpdate;

		/// <summary>
		/// 提示条件单校验错误
		/// </summary>
		event RtnErrorConditionalOrder ^OnRtnErrorConditionalOrder;

		/// <summary>
		/// 银行发起银行资金转期货通知
		/// </summary>
		event RtnFromBankToFutureByBank ^OnRtnFromBankToFutureByBank;

		/// <summary>
		/// 期货发起银行资金转期货通知
		/// </summary>
		event RtnFromBankToFutureByFuture ^OnRtnFromBankToFutureByFuture;

		/// <summary>
		/// 银行发起期货资金转银行通知
		/// </summary>
		event RtnFromFutureToBankByBank ^OnRtnFromFutureToBankByBank;

		/// <summary>
		/// 期货发起期货资金转银行通知
		/// </summary>
		event RtnFromFutureToBankByFuture ^OnRtnFromFutureToBankByFuture;

		/// <summary>
		/// 合约交易状态通知
		/// </summary>
		event RtnInstrumentStatus ^OnRtnInstrumentStatus;

		/// <summary>
		/// 报单通知
		/// </summary>
		event RtnOrder ^OnRtnOrder;

		/// <summary>
		/// 期货发起查询银行余额通知
		/// </summary>
		event RtnQueryBankBalanceByFuture ^OnRtnQueryBankBalanceByFuture;

		/// <summary>
		/// 银行发起冲正银行转期货通知
		/// </summary>
		event RtnRepealFromBankToFutureByBank ^OnRtnRepealFromBankToFutureByBank;

		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// </summary>
		event RtnRepealFromBankToFutureByFuture ^OnRtnRepealFromBankToFutureByFuture;

		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// </summary>
		event RtnRepealFromBankToFutureByFutureManual ^OnRtnRepealFromBankToFutureByFutureManual;

		/// <summary>
		/// 银行发起冲正期货转银行通知
		/// </summary>
		event RtnRepealFromFutureToBankByBank ^OnRtnRepealFromFutureToBankByBank;

		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// </summary>
		event RtnRepealFromFutureToBankByFuture ^OnRtnRepealFromFutureToBankByFuture;

		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// </summary>
		event RtnRepealFromFutureToBankByFutureManual ^OnRtnRepealFromFutureToBankByFutureManual;

		/// <summary>
		/// 成交通知
		/// </summary>
		event RtnTrade ^OnRtnTrade;

		/// <summary>
		/// 交易通知
		/// </summary>
		event RtnTradingNotice ^OnRtnTradingNotice;

	};
}
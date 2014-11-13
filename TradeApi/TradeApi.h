// 下列 ifdef 块是创建使从 DLL 导出更简单的
// 宏的标准方法。此 DLL 中的所有文件都是用命令行上定义的 TRADEAPI_EXPORTS
// 符号编译的。在使用此 DLL 的
// 任何其他项目上不应定义此符号。这样，源文件中包含此文件的任何其他项目都会将
// TRADEAPI_API 函数视为是从 DLL 导入的，而此 DLL 则将用此宏定义的
// 符号视为是被导出的。
#ifdef TRADEAPI_EXPORTS
#define TRADEAPI_API __declspec(dllexport)
#else
#define TRADEAPI_API __declspec(dllimport)
#endif

#include "..\api\ThostFtdcTraderApi.h"
#include "..\api\ThostFtdcUserApiDataType.h"
#include "..\api\ThostFtdcUserApiStruct.h"

// 此类是从 TradeApi.dll 导出的
class CTraderSpi : public CThostFtdcTraderSpi
{
public:
	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
virtual void OnFrontConnected();

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
virtual void OnFrontDisconnected(int nReason);
	
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
virtual void OnHeartBeatWarning(int nTimeLapse);
///登录请求响应
virtual void OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///登出请求响应
virtual void OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///用户口令更新请求响应
virtual void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///资金账户口令更新请求响应
virtual void OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///报单录入请求响应
virtual void OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///预埋单录入请求响应
virtual void OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///预埋撤单录入请求响应
virtual void OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///报单操作请求响应
virtual void OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///查询最大报单数量响应
virtual void OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///投资者结算结果确认响应
virtual void OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///删除预埋单响应
virtual void OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///删除预埋撤单响应
virtual void OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询报单响应
virtual void OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询成交响应
virtual void OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者持仓响应
virtual void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询资金账户响应
virtual void OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者响应
virtual void OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询交易编码响应
virtual void OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询合约保证金率响应
virtual void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询合约手续费率响应
virtual void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询交易所响应
virtual void OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询合约响应
virtual void OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询行情响应
virtual void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者结算结果响应
virtual void OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询转帐银行响应
virtual void OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者持仓明细响应
virtual void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询客户通知响应
virtual void OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询结算信息确认响应
virtual void OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者持仓明细响应
virtual void OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///查询保证金监管系统经纪公司资金账户密钥响应
virtual void OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询转帐流水响应
virtual void OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询银期签约关系响应
virtual void OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///错误应答
virtual void OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///报单通知
virtual void OnRtnOrder(CThostFtdcOrderField *pOrder) ;
///成交通知
virtual void OnRtnTrade(CThostFtdcTradeField *pTrade) ;
///报单录入错误回报
virtual void OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) ;
///报单操作错误回报
virtual void OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) ;
///合约交易状态通知
virtual void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus) ;
///交易通知
virtual void OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) ;
///提示条件单校验错误
virtual void OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) ;
///请求查询签约银行响应
virtual void OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询预埋单响应
virtual void OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询预埋撤单响应
virtual void OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询交易通知响应
virtual void OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询经纪公司交易参数响应
virtual void OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询经纪公司交易算法响应
virtual void OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///银行发起银行资金转期货通知
virtual void OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer) ;
///银行发起期货资金转银行通知
virtual void OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer) ;
///银行发起冲正银行转期货通知
virtual void OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal) ;
///银行发起冲正期货转银行通知
virtual void OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal) ;
///期货发起银行资金转期货通知
virtual void OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer) ;
///期货发起期货资金转银行通知
virtual void OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer) ;
///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
virtual void OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal) ;
///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
virtual void OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal) ;
///期货发起查询银行余额通知
virtual void OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) ;
///期货发起银行资金转期货错误回报
virtual void OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) ;
///期货发起期货资金转银行错误回报
virtual void OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) ;
///系统运行时期货端手工发起冲正银行转期货错误回报
virtual void OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) ;
///系统运行时期货端手工发起冲正期货转银行错误回报
virtual void OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) ;
///期货发起查询银行余额错误回报
virtual void OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) ;
///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
virtual void OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal) ;
///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
virtual void OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal) ;
///期货发起银行资金转期货应答
virtual void OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///期货发起期货资金转银行应答
virtual void OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///期货发起查询银行余额应答
virtual void OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;

//====================================
private:
	CThostFtdcRspInfoField* repareInfo(CThostFtdcRspInfoField *pRspInfo);
	// 是否收到成功的响应
	bool IsErrorRspInfo(CThostFtdcRspInfoField *pRspInfo);
	// 是否我的报单回报
	bool IsMyOrder(CThostFtdcOrderField *pOrder);
	// 是否正在交易的报单
	bool IsTradingOrder(CThostFtdcOrderField *pOrder);
};

	///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
typedef int (WINAPI *CBOnFrontConnected)();

	///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
typedef int (WINAPI *CBOnFrontDisconnected)(int nReason);
	
	///心跳超时警告。当长时间未收到报文时，该方法被调用。
typedef int (WINAPI *CBOnHeartBeatWarning)(int nTimeLapse);
///登录请求响应
typedef int (WINAPI *CBRspUserLogin)(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///登出请求响应
typedef int (WINAPI *CBRspUserLogout)(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///用户口令更新请求响应
typedef int (WINAPI *CBRspUserPasswordUpdate)(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///资金账户口令更新请求响应
typedef int (WINAPI *CBRspTradingAccountPasswordUpdate)(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///报单录入请求响应
typedef int (WINAPI *CBRspOrderInsert)(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///预埋单录入请求响应
typedef int (WINAPI *CBRspParkedOrderInsert)(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///预埋撤单录入请求响应
typedef int (WINAPI *CBRspParkedOrderAction)(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///报单操作请求响应
typedef int (WINAPI *CBRspOrderAction)(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///查询最大报单数量响应
typedef int (WINAPI *CBRspQueryMaxOrderVolume)(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///投资者结算结果确认响应
typedef int (WINAPI *CBRspSettlementInfoConfirm)(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///删除预埋单响应
typedef int (WINAPI *CBRspRemoveParkedOrder)(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///删除预埋撤单响应
typedef int (WINAPI *CBRspRemoveParkedOrderAction)(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询报单响应
typedef int (WINAPI *CBRspQryOrder)(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询成交响应
typedef int (WINAPI *CBRspQryTrade)(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者持仓响应
typedef int (WINAPI *CBRspQryInvestorPosition)(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询资金账户响应
typedef int (WINAPI *CBRspQryTradingAccount)(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者响应
typedef int (WINAPI *CBRspQryInvestor)(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询交易编码响应
typedef int (WINAPI *CBRspQryTradingCode)(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询合约保证金率响应
typedef int (WINAPI *CBRspQryInstrumentMarginRate)(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询合约手续费率响应
typedef int (WINAPI *CBRspQryInstrumentCommissionRate)(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询交易所响应
typedef int (WINAPI *CBRspQryExchange)(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询合约响应
typedef int (WINAPI *CBRspQryInstrument)(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询行情响应
typedef int (WINAPI *CBRspQryDepthMarketData)(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者结算结果响应
typedef int (WINAPI *CBRspQrySettlementInfo)(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询转帐银行响应
typedef int (WINAPI *CBRspQryTransferBank)(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者持仓明细响应
typedef int (WINAPI *CBRspQryInvestorPositionDetail)(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询客户通知响应
typedef int (WINAPI *CBRspQryNotice)(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询结算信息确认响应
typedef int (WINAPI *CBRspQrySettlementInfoConfirm)(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询投资者持仓明细响应
typedef int (WINAPI *CBRspQryInvestorPositionCombineDetail)(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///查询保证金监管系统经纪公司资金账户密钥响应
typedef int (WINAPI *CBRspQryCFMMCTradingAccountKey)(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询转帐流水响应
typedef int (WINAPI *CBRspQryTransferSerial)(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询银期签约关系响应
typedef int (WINAPI *CBRspQryAccountregister)(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
///错误应答
typedef int (WINAPI *CBRspError)(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///报单通知
typedef int (WINAPI *CBRtnOrder)(CThostFtdcOrderField *pOrder) ;
///成交通知
typedef int (WINAPI *CBRtnTrade)(CThostFtdcTradeField *pTrade) ;
///报单录入错误回报
typedef int (WINAPI *CBErrRtnOrderInsert)(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo) ;
///报单操作错误回报
typedef int (WINAPI *CBErrRtnOrderAction)(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo) ;
///合约交易状态通知
typedef int (WINAPI *CBRtnInstrumentStatus)(CThostFtdcInstrumentStatusField *pInstrumentStatus) ;
///交易通知
typedef int (WINAPI *CBRtnTradingNotice)(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo) ;
///提示条件单校验错误
typedef int (WINAPI *CBRtnErrorConditionalOrder)(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder) ;
///请求查询签约银行响应
typedef int (WINAPI *CBRspQryContractBank)(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询预埋单响应
typedef int (WINAPI *CBRspQryParkedOrder)(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询预埋撤单响应
typedef int (WINAPI *CBRspQryParkedOrderAction)(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询交易通知响应
typedef int (WINAPI *CBRspQryTradingNotice)(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询经纪公司交易参数响应
typedef int (WINAPI *CBRspQryBrokerTradingParams)(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///请求查询经纪公司交易算法响应
typedef int (WINAPI *CBRspQryBrokerTradingAlgos)(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///银行发起银行资金转期货通知
typedef int (WINAPI *CBRtnFromBankToFutureByBank)(CThostFtdcRspTransferField *pRspTransfer) ;
///银行发起期货资金转银行通知
typedef int (WINAPI *CBRtnFromFutureToBankByBank)(CThostFtdcRspTransferField *pRspTransfer) ;
///银行发起冲正银行转期货通知
typedef int (WINAPI *CBRtnRepealFromBankToFutureByBank)(CThostFtdcRspRepealField *pRspRepeal) ;
///银行发起冲正期货转银行通知
typedef int (WINAPI *CBRtnRepealFromFutureToBankByBank)(CThostFtdcRspRepealField *pRspRepeal) ;
///期货发起银行资金转期货通知
typedef int (WINAPI *CBRtnFromBankToFutureByFuture)(CThostFtdcRspTransferField *pRspTransfer) ;
///期货发起期货资金转银行通知
typedef int (WINAPI *CBRtnFromFutureToBankByFuture)(CThostFtdcRspTransferField *pRspTransfer) ;
///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
typedef int (WINAPI *CBRtnRepealFromBankToFutureByFutureManual)(CThostFtdcRspRepealField *pRspRepeal) ;
///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
typedef int (WINAPI *CBRtnRepealFromFutureToBankByFutureManual)(CThostFtdcRspRepealField *pRspRepeal) ;
///期货发起查询银行余额通知
typedef int (WINAPI *CBRtnQueryBankBalanceByFuture)(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount) ;
///期货发起银行资金转期货错误回报
typedef int (WINAPI *CBErrRtnBankToFutureByFuture)(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) ;
///期货发起期货资金转银行错误回报
typedef int (WINAPI *CBErrRtnFutureToBankByFuture)(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo) ;
///系统运行时期货端手工发起冲正银行转期货错误回报
typedef int (WINAPI *CBErrRtnRepealBankToFutureByFutureManual)(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) ;
///系统运行时期货端手工发起冲正期货转银行错误回报
typedef int (WINAPI *CBErrRtnRepealFutureToBankByFutureManual)(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo) ;
///期货发起查询银行余额错误回报
typedef int (WINAPI *CBErrRtnQueryBankBalanceByFuture)(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo) ;
///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
typedef int (WINAPI *CBRtnRepealFromBankToFutureByFuture)(CThostFtdcRspRepealField *pRspRepeal) ;
///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
typedef int (WINAPI *CBRtnRepealFromFutureToBankByFuture)(CThostFtdcRspRepealField *pRspRepeal) ;
///期货发起银行资金转期货应答
typedef int (WINAPI *CBRspFromBankToFutureByFuture)(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///期货发起期货资金转银行应答
typedef int (WINAPI *CBRspFromFutureToBankByFuture)(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;
///期货发起查询银行余额应答
typedef int (WINAPI *CBRspQueryBankAccountMoneyByFuture)(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) ;


#include "stdafx.h"
#include "CmsTradeApi.h"
#include <iostream>
using namespace std;


#pragma warning(disable : 4996)
//====================
// 配置参数
//extern char FRONT_ADDR[];		// 前置地址
//extern char BROKER_ID[];		// 经纪公司代码
//extern char INVESTOR_ID[];		// 投资者代码
//extern char PASSWORD[];			// 用户密码
//extern char INSTRUMENT_ID[];	// 合约代码
//extern TThostFtdcPriceType	LIMIT_PRICE;	// 价格
//extern TThostFtdcDirectionType	DIRECTION;	// 买卖方向

// 请求编号
//extern int iRequestID;
///当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
void CmsTraderSpi::OnFrontConnected(){
	if (cbOnFrontConnected != NULL) 		
		cbOnFrontConnected(); 
}

///当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
void CmsTraderSpi::OnFrontDisconnected(int nReason){ if (cbOnFrontDisconnected != NULL) cbOnFrontDisconnected(nReason); }

///心跳超时警告。当长时间未收到报文时，该方法被调用。  @param nTimeLapse 距离上次接收报文的时间
void CmsTraderSpi::OnHeartBeatWarning(int nTimeLapse){ if (cbOnHeartBeatWarning != NULL) cbOnHeartBeatWarning(nTimeLapse); }



///客户端认证响应
void CmsTraderSpi::OnRspAuthenticate(CThostFtdcRspAuthenticateField *pRspAuthenticateField, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspAuthenticate != NULL)
	{
		if (pRspAuthenticateField == NULL)
		{
			CThostFtdcRspAuthenticateField req;
			memset(&req, 0, sizeof(req));
			cbRspAuthenticate(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspAuthenticate(pRspAuthenticateField, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}


///登录请求响应
void CmsTraderSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspUserLogin != NULL)
	{
		if (pRspUserLogin == NULL)
		{
			CThostFtdcRspUserLoginField req;
			memset(&req, 0, sizeof(req));
			cbRspUserLogin(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspUserLogin(pRspUserLogin, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///登出请求响应
void CmsTraderSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspUserLogout != NULL)
	{
		if (pUserLogout == NULL)
		{
			CThostFtdcUserLogoutField req;
			memset(&req, 0, sizeof(req));
			cbRspUserLogout(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspUserLogout(pUserLogout, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///用户口令更新请求响应
void CmsTraderSpi::OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField *pUserPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspUserPasswordUpdate != NULL)
	{
		if (pUserPasswordUpdate == NULL)
		{
			CThostFtdcUserPasswordUpdateField req;
			memset(&req, 0, sizeof(req));
			cbRspUserPasswordUpdate(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspUserPasswordUpdate(pUserPasswordUpdate, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///资金账户口令更新请求响应
void CmsTraderSpi::OnRspTradingAccountPasswordUpdate(CThostFtdcTradingAccountPasswordUpdateField *pTradingAccountPasswordUpdate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspTradingAccountPasswordUpdate != NULL)
	{
		if (pTradingAccountPasswordUpdate == NULL)
		{
			CThostFtdcTradingAccountPasswordUpdateField req;
			memset(&req, 0, sizeof(req));
			cbRspTradingAccountPasswordUpdate(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspTradingAccountPasswordUpdate(pTradingAccountPasswordUpdate, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///报单录入请求响应
void CmsTraderSpi::OnRspOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspOrderInsert != NULL)
	{
		if (pInputOrder == NULL)
		{
			CThostFtdcInputOrderField req;
			memset(&req, 0, sizeof(req));
			cbRspOrderInsert(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspOrderInsert(pInputOrder, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///预埋单录入请求响应
void CmsTraderSpi::OnRspParkedOrderInsert(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspParkedOrderInsert != NULL)
	{
		if (pParkedOrder == NULL)
		{
			CThostFtdcParkedOrderField req;
			memset(&req, 0, sizeof(req));
			cbRspParkedOrderInsert(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspParkedOrderInsert(pParkedOrder, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///预埋撤单录入请求响应
void CmsTraderSpi::OnRspParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspParkedOrderAction != NULL)
	{
		if (pParkedOrderAction == NULL)
		{
			CThostFtdcParkedOrderActionField req;
			memset(&req, 0, sizeof(req));
			cbRspParkedOrderAction(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspParkedOrderAction(pParkedOrderAction, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///报单操作请求响应
void CmsTraderSpi::OnRspOrderAction(CThostFtdcInputOrderActionField *pInputOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspOrderAction != NULL)
	{
		if (pInputOrderAction == NULL)
		{
			CThostFtdcInputOrderActionField req;
			memset(&req, 0, sizeof(req));
			cbRspOrderAction(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspOrderAction(pInputOrderAction, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///查询最大报单数量响应
void CmsTraderSpi::OnRspQueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField *pQueryMaxOrderVolume, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQueryMaxOrderVolume != NULL)
	{
		if (pQueryMaxOrderVolume == NULL)
		{
			CThostFtdcQueryMaxOrderVolumeField req;
			memset(&req, 0, sizeof(req));
			cbRspQueryMaxOrderVolume(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQueryMaxOrderVolume(pQueryMaxOrderVolume, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///投资者结算结果确认响应
void CmsTraderSpi::OnRspSettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspSettlementInfoConfirm != NULL)
	{
		if (pSettlementInfoConfirm == NULL)
		{
			CThostFtdcSettlementInfoConfirmField req;
			memset(&req, 0, sizeof(req));
			cbRspSettlementInfoConfirm(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspSettlementInfoConfirm(pSettlementInfoConfirm, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///删除预埋单响应
void CmsTraderSpi::OnRspRemoveParkedOrder(CThostFtdcRemoveParkedOrderField *pRemoveParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspRemoveParkedOrder != NULL)
	{
		if (pRemoveParkedOrder == NULL)
		{
			CThostFtdcRemoveParkedOrderField req;
			memset(&req, 0, sizeof(req));
			cbRspRemoveParkedOrder(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspRemoveParkedOrder(pRemoveParkedOrder, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///删除预埋撤单响应
void CmsTraderSpi::OnRspRemoveParkedOrderAction(CThostFtdcRemoveParkedOrderActionField *pRemoveParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspRemoveParkedOrderAction != NULL)
	{
		if (pRemoveParkedOrderAction == NULL)
		{
			CThostFtdcRemoveParkedOrderActionField req;
			memset(&req, 0, sizeof(req));
			cbRspRemoveParkedOrderAction(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspRemoveParkedOrderAction(pRemoveParkedOrderAction, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询报单响应
void CmsTraderSpi::OnRspQryOrder(CThostFtdcOrderField *pOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryOrder != NULL)
	{
		if (pOrder == NULL)
		{
			CThostFtdcOrderField req;
			memset(&req, 0, sizeof(req));
			cbRspQryOrder(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryOrder(pOrder, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询成交响应
void CmsTraderSpi::OnRspQryTrade(CThostFtdcTradeField *pTrade, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryTrade != NULL)
	{
		if (pTrade == NULL)
		{
			CThostFtdcTradeField req;
			memset(&req, 0, sizeof(req));
			cbRspQryTrade(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryTrade(pTrade, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询投资者持仓响应
void CmsTraderSpi::OnRspQryInvestorPosition(CThostFtdcInvestorPositionField *pInvestorPosition, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryInvestorPosition != NULL)
	{
		if (pInvestorPosition == NULL)
		{
			CThostFtdcInvestorPositionField req;
			memset(&req, 0, sizeof(req));
			cbRspQryInvestorPosition(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryInvestorPosition(pInvestorPosition, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询资金账户响应
void CmsTraderSpi::OnRspQryTradingAccount(CThostFtdcTradingAccountField *pTradingAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryTradingAccount != NULL)
	{
		if (pTradingAccount == NULL)
		{
			CThostFtdcTradingAccountField req;
			memset(&req, 0, sizeof(req));
			cbRspQryTradingAccount(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryTradingAccount(pTradingAccount, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询投资者响应
void CmsTraderSpi::OnRspQryInvestor(CThostFtdcInvestorField *pInvestor, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryInvestor != NULL)
	{
		if (pInvestor == NULL)
		{
			CThostFtdcInvestorField req;
			memset(&req, 0, sizeof(req));
			cbRspQryInvestor(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryInvestor(pInvestor, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询交易编码响应
void CmsTraderSpi::OnRspQryTradingCode(CThostFtdcTradingCodeField *pTradingCode, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryTradingCode != NULL)
	{
		if (pTradingCode == NULL)
		{
			CThostFtdcTradingCodeField req;
			memset(&req, 0, sizeof(req));
			cbRspQryTradingCode(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryTradingCode(pTradingCode, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询合约保证金率响应
void CmsTraderSpi::OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField *pInstrumentMarginRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryInstrumentMarginRate != NULL)
	{
		if (pInstrumentMarginRate == NULL)
		{
			CThostFtdcInstrumentMarginRateField req;
			memset(&req, 0, sizeof(req));
			cbRspQryInstrumentMarginRate(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryInstrumentMarginRate(pInstrumentMarginRate, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询合约手续费率响应
void CmsTraderSpi::OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField *pInstrumentCommissionRate, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryInstrumentCommissionRate != NULL)
	{
		if (pInstrumentCommissionRate == NULL)
		{
			CThostFtdcInstrumentCommissionRateField req;
			memset(&req, 0, sizeof(req));
			cbRspQryInstrumentCommissionRate(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryInstrumentCommissionRate(pInstrumentCommissionRate, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询交易所响应
void CmsTraderSpi::OnRspQryExchange(CThostFtdcExchangeField *pExchange, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryExchange != NULL)
	{
		if (pExchange == NULL)
		{
			CThostFtdcExchangeField req;
			memset(&req, 0, sizeof(req));
			cbRspQryExchange(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryExchange(pExchange, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询合约响应
void CmsTraderSpi::OnRspQryInstrument(CThostFtdcInstrumentField *pInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryInstrument != NULL)
	{
		if (pInstrument == NULL)
		{
			CThostFtdcInstrumentField req;
			memset(&req, 0, sizeof(req));
			cbRspQryInstrument(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryInstrument(pInstrument, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询行情响应
void CmsTraderSpi::OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryDepthMarketData != NULL)
	{
		if (pDepthMarketData == NULL)
		{
			CThostFtdcDepthMarketDataField req;
			memset(&req, 0, sizeof(req));
			cbRspQryDepthMarketData(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryDepthMarketData(pDepthMarketData, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询投资者结算结果响应
void CmsTraderSpi::OnRspQrySettlementInfo(CThostFtdcSettlementInfoField *pSettlementInfo, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQrySettlementInfo != NULL)
	{
		if (pSettlementInfo == NULL)
		{
			CThostFtdcSettlementInfoField req;
			memset(&req, 0, sizeof(req));
			cbRspQrySettlementInfo(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQrySettlementInfo(pSettlementInfo, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询转帐银行响应
void CmsTraderSpi::OnRspQryTransferBank(CThostFtdcTransferBankField *pTransferBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryTransferBank != NULL)
	{
		if (pTransferBank == NULL)
		{
			CThostFtdcTransferBankField req;
			memset(&req, 0, sizeof(req));
			cbRspQryTransferBank(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryTransferBank(pTransferBank, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询投资者持仓明细响应
void CmsTraderSpi::OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField *pInvestorPositionDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryInvestorPositionDetail != NULL)
	{
		if (pInvestorPositionDetail == NULL)
		{
			CThostFtdcInvestorPositionDetailField req;
			memset(&req, 0, sizeof(req));
			cbRspQryInvestorPositionDetail(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryInvestorPositionDetail(pInvestorPositionDetail, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询客户通知响应
void CmsTraderSpi::OnRspQryNotice(CThostFtdcNoticeField *pNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryNotice != NULL)
	{
		if (pNotice == NULL)
		{
			CThostFtdcNoticeField req;
			memset(&req, 0, sizeof(req));
			cbRspQryNotice(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryNotice(pNotice, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询结算信息确认响应
void CmsTraderSpi::OnRspQrySettlementInfoConfirm(CThostFtdcSettlementInfoConfirmField *pSettlementInfoConfirm, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQrySettlementInfoConfirm != NULL)
	{
		if (pSettlementInfoConfirm == NULL)
		{
			CThostFtdcSettlementInfoConfirmField req;
			memset(&req, 0, sizeof(req));
			cbRspQrySettlementInfoConfirm(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQrySettlementInfoConfirm(pSettlementInfoConfirm, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询投资者持仓明细响应
void CmsTraderSpi::OnRspQryInvestorPositionCombineDetail(CThostFtdcInvestorPositionCombineDetailField *pInvestorPositionCombineDetail, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryInvestorPositionCombineDetail != NULL)
	{
		if (pInvestorPositionCombineDetail == NULL)
		{
			CThostFtdcInvestorPositionCombineDetailField req;
			memset(&req, 0, sizeof(req));
			cbRspQryInvestorPositionCombineDetail(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryInvestorPositionCombineDetail(pInvestorPositionCombineDetail, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///查询保证金监管系统经纪公司资金账户密钥响应
void CmsTraderSpi::OnRspQryCFMMCTradingAccountKey(CThostFtdcCFMMCTradingAccountKeyField *pCFMMCTradingAccountKey, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryCFMMCTradingAccountKey != NULL)
	{
		if (pCFMMCTradingAccountKey == NULL)
		{
			CThostFtdcCFMMCTradingAccountKeyField req;
			memset(&req, 0, sizeof(req));
			cbRspQryCFMMCTradingAccountKey(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryCFMMCTradingAccountKey(pCFMMCTradingAccountKey, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询转帐流水响应
void CmsTraderSpi::OnRspQryTransferSerial(CThostFtdcTransferSerialField *pTransferSerial, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryTransferSerial != NULL)
	{
		if (pTransferSerial == NULL)
		{
			CThostFtdcTransferSerialField req;
			memset(&req, 0, sizeof(req));
			cbRspQryTransferSerial(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryTransferSerial(pTransferSerial, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询银期签约关系响应
void CmsTraderSpi::OnRspQryAccountregister(CThostFtdcAccountregisterField *pAccountregister, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryAccountregister != NULL)
	{
		if (pAccountregister == NULL)
		{
			CThostFtdcAccountregisterField req;
			memset(&req, 0, sizeof(req));
			cbRspQryAccountregister(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryAccountregister(pAccountregister, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
};

///错误应答
void CmsTraderSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspError != NULL)
	{
		if (pRspInfo == NULL)
		{
			CThostFtdcRspInfoField req;
			memset(&req, 0, sizeof(req));
			cbRspError(&req, nRequestID, bIsLast);
		}
		else
			cbRspError(pRspInfo, nRequestID, bIsLast);
	}
}

///报单通知
void CmsTraderSpi::OnRtnOrder(CThostFtdcOrderField *pOrder)
{
	if (cbRtnOrder != NULL)
	{
		if (pOrder == NULL)
		{
			CThostFtdcOrderField req;
			memset(&req, 0, sizeof(req));
			cbRtnOrder(&req);
		}
		else
			cbRtnOrder(pOrder);
	}
}

///成交通知
void CmsTraderSpi::OnRtnTrade(CThostFtdcTradeField *pTrade)
{
	if (cbRtnTrade != NULL)
	{
		if (pTrade == NULL)
		{
			CThostFtdcTradeField req;
			memset(&req, 0, sizeof(req));
			cbRtnTrade(&req);
		}
		else
			cbRtnTrade(pTrade);
	}
}

///报单录入错误回报
void CmsTraderSpi::OnErrRtnOrderInsert(CThostFtdcInputOrderField *pInputOrder, CThostFtdcRspInfoField *pRspInfo)
{
	if (cbErrRtnOrderInsert != NULL)
	{
		if (pInputOrder == NULL)
		{
			CThostFtdcInputOrderField req;
			memset(&req, 0, sizeof(req));
			cbErrRtnOrderInsert(&req, repareInfo(pRspInfo));
		}
		else
			cbErrRtnOrderInsert(pInputOrder, repareInfo(pRspInfo));
	}
}

///报单操作错误回报
void CmsTraderSpi::OnErrRtnOrderAction(CThostFtdcOrderActionField *pOrderAction, CThostFtdcRspInfoField *pRspInfo)
{
	if (cbErrRtnOrderAction != NULL)
	{
		if (pOrderAction == NULL)
		{
			CThostFtdcOrderActionField req;
			memset(&req, 0, sizeof(req));
			cbErrRtnOrderAction(&req, repareInfo(pRspInfo));
		}
		else
			cbErrRtnOrderAction(pOrderAction, repareInfo(pRspInfo));
	}
}

///合约交易状态通知
void CmsTraderSpi::OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField *pInstrumentStatus)
{
	if (cbRtnInstrumentStatus != NULL)
	{
		if (pInstrumentStatus == NULL)
		{
			CThostFtdcInstrumentStatusField req;
			memset(&req, 0, sizeof(req));
			cbRtnInstrumentStatus(&req);
		}
		else
			cbRtnInstrumentStatus(pInstrumentStatus);
	}
}

///交易通知
void CmsTraderSpi::OnRtnTradingNotice(CThostFtdcTradingNoticeInfoField *pTradingNoticeInfo)
{
	if (cbRtnTradingNotice != NULL)
	{
		if (pTradingNoticeInfo == NULL)
		{
			CThostFtdcTradingNoticeInfoField req;
			memset(&req, 0, sizeof(req));
			cbRtnTradingNotice(&req);
		}
		else
			cbRtnTradingNotice(pTradingNoticeInfo);
	}
}

///提示条件单校验错误
void CmsTraderSpi::OnRtnErrorConditionalOrder(CThostFtdcErrorConditionalOrderField *pErrorConditionalOrder)
{
	if (cbRtnErrorConditionalOrder != NULL)
	{
		if (pErrorConditionalOrder == NULL)
		{
			CThostFtdcErrorConditionalOrderField req;
			memset(&req, 0, sizeof(req));
			cbRtnErrorConditionalOrder(&req);
		}
		else
			cbRtnErrorConditionalOrder(pErrorConditionalOrder);
	}
}

///请求查询签约银行响应
void CmsTraderSpi::OnRspQryContractBank(CThostFtdcContractBankField *pContractBank, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryContractBank != NULL)
	{
		if (pContractBank == NULL)
		{
			CThostFtdcContractBankField req;
			memset(&req, 0, sizeof(req));
			cbRspQryContractBank(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryContractBank(pContractBank, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询预埋单响应
void CmsTraderSpi::OnRspQryParkedOrder(CThostFtdcParkedOrderField *pParkedOrder, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryParkedOrder != NULL)
	{
		if (pParkedOrder == NULL)
		{
			CThostFtdcParkedOrderField req;
			memset(&req, 0, sizeof(req));
			cbRspQryParkedOrder(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryParkedOrder(pParkedOrder, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询预埋撤单响应
void CmsTraderSpi::OnRspQryParkedOrderAction(CThostFtdcParkedOrderActionField *pParkedOrderAction, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryParkedOrderAction != NULL)
	{
		if (pParkedOrderAction == NULL)
		{
			CThostFtdcParkedOrderActionField req;
			memset(&req, 0, sizeof(req));
			cbRspQryParkedOrderAction(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryParkedOrderAction(pParkedOrderAction, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询交易通知响应
void CmsTraderSpi::OnRspQryTradingNotice(CThostFtdcTradingNoticeField *pTradingNotice, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryTradingNotice != NULL)
	{
		if (pTradingNotice == NULL)
		{
			CThostFtdcTradingNoticeField req;
			memset(&req, 0, sizeof(req));
			cbRspQryTradingNotice(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryTradingNotice(pTradingNotice, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询经纪公司交易参数响应
void CmsTraderSpi::OnRspQryBrokerTradingParams(CThostFtdcBrokerTradingParamsField *pBrokerTradingParams, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryBrokerTradingParams != NULL)
	{
		if (pBrokerTradingParams == NULL)
		{
			CThostFtdcBrokerTradingParamsField req;
			memset(&req, 0, sizeof(req));
			cbRspQryBrokerTradingParams(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryBrokerTradingParams(pBrokerTradingParams, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///请求查询经纪公司交易算法响应
void CmsTraderSpi::OnRspQryBrokerTradingAlgos(CThostFtdcBrokerTradingAlgosField *pBrokerTradingAlgos, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQryBrokerTradingAlgos != NULL)
	{
		if (pBrokerTradingAlgos == NULL)
		{
			CThostFtdcBrokerTradingAlgosField req;
			memset(&req, 0, sizeof(req));
			cbRspQryBrokerTradingAlgos(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQryBrokerTradingAlgos(pBrokerTradingAlgos, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///银行发起银行资金转期货通知
void CmsTraderSpi::OnRtnFromBankToFutureByBank(CThostFtdcRspTransferField *pRspTransfer)
{
	if (cbRtnFromBankToFutureByBank != NULL)
	{
		if (pRspTransfer == NULL)
		{
			CThostFtdcRspTransferField req;
			memset(&req, 0, sizeof(req));
			cbRtnFromBankToFutureByBank(&req);
		}
		else
			cbRtnFromBankToFutureByBank(pRspTransfer);
	}
}

///银行发起期货资金转银行通知
void CmsTraderSpi::OnRtnFromFutureToBankByBank(CThostFtdcRspTransferField *pRspTransfer)
{
	if (cbRtnFromFutureToBankByBank != NULL)
	{
		if (pRspTransfer == NULL)
		{
			CThostFtdcRspTransferField req;
			memset(&req, 0, sizeof(req));
			cbRtnFromFutureToBankByBank(&req);
		}
		else
			cbRtnFromFutureToBankByBank(pRspTransfer);
	}
}

///银行发起冲正银行转期货通知
void CmsTraderSpi::OnRtnRepealFromBankToFutureByBank(CThostFtdcRspRepealField *pRspRepeal)
{
	if (cbRtnRepealFromBankToFutureByBank != NULL)
	{
		if (pRspRepeal == NULL)
		{
			CThostFtdcRspRepealField req;
			memset(&req, 0, sizeof(req));
			cbRtnRepealFromBankToFutureByBank(&req);
		}
		else
			cbRtnRepealFromBankToFutureByBank(pRspRepeal);
	}
}

///银行发起冲正期货转银行通知
void CmsTraderSpi::OnRtnRepealFromFutureToBankByBank(CThostFtdcRspRepealField *pRspRepeal)
{
	if (cbRtnRepealFromFutureToBankByBank != NULL)
	{
		if (pRspRepeal == NULL)
		{
			CThostFtdcRspRepealField req;
			memset(&req, 0, sizeof(req));
			cbRtnRepealFromFutureToBankByBank(&req);
		}
		else
			cbRtnRepealFromFutureToBankByBank(pRspRepeal);
	}
}

///期货发起银行资金转期货通知
void CmsTraderSpi::OnRtnFromBankToFutureByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	if (cbRtnFromBankToFutureByFuture != NULL)
	{
		if (pRspTransfer == NULL)
		{
			CThostFtdcRspTransferField req;
			memset(&req, 0, sizeof(req));
			cbRtnFromBankToFutureByFuture(&req);
		}
		else
			cbRtnFromBankToFutureByFuture(pRspTransfer);
	}
}

///期货发起期货资金转银行通知
void CmsTraderSpi::OnRtnFromFutureToBankByFuture(CThostFtdcRspTransferField *pRspTransfer)
{
	if (cbRtnFromFutureToBankByFuture != NULL)
	{
		if (pRspTransfer == NULL)
		{
			CThostFtdcRspTransferField req;
			memset(&req, 0, sizeof(req));
			cbRtnFromFutureToBankByFuture(&req);
		}
		else
			cbRtnFromFutureToBankByFuture(pRspTransfer);
	}
}

///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void CmsTraderSpi::OnRtnRepealFromBankToFutureByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	if (cbRtnRepealFromBankToFutureByFutureManual != NULL)
	{
		if (pRspRepeal == NULL)
		{
			CThostFtdcRspRepealField req;
			memset(&req, 0, sizeof(req));
			cbRtnRepealFromBankToFutureByFutureManual(&req);
		}
		else
			cbRtnRepealFromBankToFutureByFutureManual(pRspRepeal);
	}
}

///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void CmsTraderSpi::OnRtnRepealFromFutureToBankByFutureManual(CThostFtdcRspRepealField *pRspRepeal)
{
	if (cbRtnRepealFromFutureToBankByFutureManual != NULL)
	{
		if (pRspRepeal == NULL)
		{
			CThostFtdcRspRepealField req;
			memset(&req, 0, sizeof(req));
			cbRtnRepealFromFutureToBankByFutureManual(&req);
		}
		else
			cbRtnRepealFromFutureToBankByFutureManual(pRspRepeal);
	}
}

///期货发起查询银行余额通知
void CmsTraderSpi::OnRtnQueryBankBalanceByFuture(CThostFtdcNotifyQueryAccountField *pNotifyQueryAccount)
{
	if (cbRtnQueryBankBalanceByFuture != NULL)
	{
		if (pNotifyQueryAccount == NULL)
		{
			CThostFtdcNotifyQueryAccountField req;
			memset(&req, 0, sizeof(req));
			cbRtnQueryBankBalanceByFuture(&req);
		}
		else
			cbRtnQueryBankBalanceByFuture(pNotifyQueryAccount);
	}
}

///期货发起银行资金转期货错误回报
void CmsTraderSpi::OnErrRtnBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
{
	if (cbErrRtnBankToFutureByFuture != NULL)
	{
		if (pReqTransfer == NULL)
		{
			CThostFtdcReqTransferField req;
			memset(&req, 0, sizeof(req));
			cbErrRtnBankToFutureByFuture(&req, repareInfo(pRspInfo));
		}
		else
			cbErrRtnBankToFutureByFuture(pReqTransfer, repareInfo(pRspInfo));
	}
}

///期货发起期货资金转银行错误回报
void CmsTraderSpi::OnErrRtnFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo)
{
	if (cbErrRtnFutureToBankByFuture != NULL)
	{
		if (pReqTransfer == NULL)
		{
			CThostFtdcReqTransferField req;
			memset(&req, 0, sizeof(req));
			cbErrRtnFutureToBankByFuture(&req, repareInfo(pRspInfo));
		}
		else
			cbErrRtnFutureToBankByFuture(pReqTransfer, repareInfo(pRspInfo));
	}
}

///系统运行时期货端手工发起冲正银行转期货错误回报
void CmsTraderSpi::OnErrRtnRepealBankToFutureByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
{
	if (cbErrRtnRepealBankToFutureByFutureManual != NULL)
	{
		if (pReqRepeal == NULL)
		{
			CThostFtdcReqRepealField req;
			memset(&req, 0, sizeof(req));
			cbErrRtnRepealBankToFutureByFutureManual(&req, repareInfo(pRspInfo));
		}
		else
			cbErrRtnRepealBankToFutureByFutureManual(pReqRepeal, repareInfo(pRspInfo));
	}
}

///系统运行时期货端手工发起冲正期货转银行错误回报
void CmsTraderSpi::OnErrRtnRepealFutureToBankByFutureManual(CThostFtdcReqRepealField *pReqRepeal, CThostFtdcRspInfoField *pRspInfo)
{
	if (cbErrRtnRepealFutureToBankByFutureManual != NULL)
	{
		if (pReqRepeal == NULL)
		{
			CThostFtdcReqRepealField req;
			memset(&req, 0, sizeof(req));
			cbErrRtnRepealFutureToBankByFutureManual(&req, repareInfo(pRspInfo));
		}
		else
			cbErrRtnRepealFutureToBankByFutureManual(pReqRepeal, repareInfo(pRspInfo));
	}
}

///期货发起查询银行余额错误回报
void CmsTraderSpi::OnErrRtnQueryBankBalanceByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo)
{
	if (cbErrRtnQueryBankBalanceByFuture != NULL)
	{
		if (pReqQueryAccount == NULL)
		{
			CThostFtdcReqQueryAccountField req;
			memset(&req, 0, sizeof(req));
			cbErrRtnQueryBankBalanceByFuture(&req, repareInfo(pRspInfo));
		}
		else
			cbErrRtnQueryBankBalanceByFuture(pReqQueryAccount, repareInfo(pRspInfo));
	}
}

///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
void CmsTraderSpi::OnRtnRepealFromBankToFutureByFuture(CThostFtdcRspRepealField *pRspRepeal)
{
	if (cbRtnRepealFromBankToFutureByFuture != NULL)
	{
		if (pRspRepeal == NULL)
		{
			CThostFtdcRspRepealField req;
			memset(&req, 0, sizeof(req));
			cbRtnRepealFromBankToFutureByFuture(&req);
		}
		else
			cbRtnRepealFromBankToFutureByFuture(pRspRepeal);
	}
}

///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
void CmsTraderSpi::OnRtnRepealFromFutureToBankByFuture(CThostFtdcRspRepealField *pRspRepeal)
{
	if (cbRtnRepealFromFutureToBankByFuture != NULL)
	{
		if (pRspRepeal == NULL)
		{
			CThostFtdcRspRepealField req;
			memset(&req, 0, sizeof(req));
			cbRtnRepealFromFutureToBankByFuture(&req);
		}
		else
			cbRtnRepealFromFutureToBankByFuture(pRspRepeal);
	}
}

///期货发起银行资金转期货应答
void CmsTraderSpi::OnRspFromBankToFutureByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspFromBankToFutureByFuture != NULL)
	{
		if (pReqTransfer == NULL)
		{
			CThostFtdcReqTransferField req;
			memset(&req, 0, sizeof(req));
			cbRspFromBankToFutureByFuture(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspFromBankToFutureByFuture(pReqTransfer, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///期货发起期货资金转银行应答
void CmsTraderSpi::OnRspFromFutureToBankByFuture(CThostFtdcReqTransferField *pReqTransfer, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspFromFutureToBankByFuture != NULL)
	{
		if (pReqTransfer == NULL)
		{
			CThostFtdcReqTransferField req;
			memset(&req, 0, sizeof(req));
			cbRspFromFutureToBankByFuture(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspFromFutureToBankByFuture(pReqTransfer, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}

///期货发起查询银行余额应答
void CmsTraderSpi::OnRspQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField *pReqQueryAccount, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbRspQueryBankAccountMoneyByFuture != NULL)
	{
		if (pReqQueryAccount == NULL)
		{
			CThostFtdcReqQueryAccountField req;
			memset(&req, 0, sizeof(req));
			cbRspQueryBankAccountMoneyByFuture(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
		else
			cbRspQueryBankAccountMoneyByFuture(pReqQueryAccount, repareInfo(pRspInfo), nRequestID, bIsLast);
	}
}



//针对收到空反馈的处理

CThostFtdcRspInfoField* CmsTraderSpi::repareInfo(CThostFtdcRspInfoField *pRspInfo)
{
	static CThostFtdcRspInfoField rif;
	if (pRspInfo == NULL)
	{
		memset(&rif, 0, sizeof(rif));
		return &rif;
	}
	else
		return pRspInfo;
}
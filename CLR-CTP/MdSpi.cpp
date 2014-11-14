#include "stdafx.h"
#include "MdApi.h"
#include <iostream>
using namespace std;


#pragma warning(disable : 4996)




// 这是已导出类的构造函数。
// 有关类定义的信息，请参阅 MdApi.h
CMdSpi::CMdSpi()
{
	return;
}


void CMdSpi::OnRspError(CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspError != NULL)
		cbOnRspError(pRspInfo, nRequestID, bIsLast);
}

void CMdSpi::OnFrontDisconnected(int nReason)
{
	//cerr << "--->>> " << __FUNCTION__ << endl;
	//cerr << "--->>> Reason = " << nReason << endl;
	if (cbOnFrontDisconnected != NULL)
		cbOnFrontDisconnected(nReason);
}

void CMdSpi::OnHeartBeatWarning(int nTimeLapse)
{
	if (cbOnHeartBeatWarning != NULL)
		cbOnHeartBeatWarning(nTimeLapse);
}

void CMdSpi::OnFrontConnected()
{
	//cerr << "--->>> " << __FUNCTION__ << endl;
	if (cbOnFrontConnected != NULL)
		cbOnFrontConnected();
}

void CMdSpi::OnRspUserLogin(CThostFtdcRspUserLoginField *pRspUserLogin,
	CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspUserLogin != NULL)
	{
		if (pRspUserLogin == NULL)
		{
			CThostFtdcRspUserLoginField req;
			memset(&req, 0, sizeof(req));
			cbOnRspUserLogin(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
	else
		cbOnRspUserLogin(pRspUserLogin, pRspInfo, nRequestID, bIsLast);
}

void CMdSpi::OnRspUserLogout(CThostFtdcUserLogoutField *pUserLogout, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	if (cbOnRspUserLogout != NULL)	
	{
		if (pUserLogout == NULL)
		{
			CThostFtdcUserLogoutField req;
			memset(&req, 0, sizeof(req));
			cbOnRspUserLogout(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
	else
		cbOnRspUserLogout(pUserLogout, pRspInfo, nRequestID, bIsLast);
}

void CMdSpi::OnRspSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	//cerr << __FUNCTION__ << endl;
	if (cbOnRspSubMarketData != NULL)
	{
		if (pSpecificInstrument == NULL)
		{
			CThostFtdcSpecificInstrumentField req;
			memset(&req, 0, sizeof(req));
			cbOnRspSubMarketData(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
	else
		cbOnRspSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

void CMdSpi::OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField *pSpecificInstrument, CThostFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
	//cerr << __FUNCTION__ << endl;
	if (cbOnRspUnSubMarketData != NULL)
	{
		if (pSpecificInstrument == NULL)
		{
			CThostFtdcSpecificInstrumentField req;
			memset(&req, 0, sizeof(req));
			cbOnRspUnSubMarketData(&req, repareInfo(pRspInfo), nRequestID, bIsLast);
		}
	}
	else
		cbOnRspUnSubMarketData(pSpecificInstrument, pRspInfo, nRequestID, bIsLast);
}

void CMdSpi::OnRtnDepthMarketData(CThostFtdcDepthMarketDataField *pDepthMarketData)
{
	//cerr << "深度行情" << endl;
	if (cbOnRtnDepthMarketData != NULL)
	{
		if (pDepthMarketData == NULL)
		{
			CThostFtdcDepthMarketDataField req;
			memset(&req, 0, sizeof(req));
			cbOnRtnDepthMarketData(&req);
		}
	}
	else
		cbOnRtnDepthMarketData(pDepthMarketData);
}


//针对收到空反馈的处理

CThostFtdcRspInfoField* CMdSpi::repareInfo(CThostFtdcRspInfoField *pRspInfo)
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
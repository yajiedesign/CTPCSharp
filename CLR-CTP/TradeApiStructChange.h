#pragma once

#include "KSTradeApi.h"

namespace CTPTradeApi
{
#include "../api/ThostFtdcTraderApi.h"
}


void *  __cdecl localmemcpy(_Out_writes_bytes_all_(_Size) void * _Dst, _In_reads_bytes_(_Size) const void * _Src, _In_ size_t _Size)
{
	return memcpy(_Dst, _Src, _Size);
}
template <typename  T>
inline void *  __cdecl localmemcpy(_Out_writes_bytes_all_(_Size) T & _Dst, _In_reads_bytes_(_Size) const T & _Src, _In_ size_t _Size)
{
	return memcpy(&_Dst, &_Src, _Size);
}
CTPTradeApi::CThostFtdcDisseminationField KStoCTPChange(KingstarAPI::CThostFtdcDisseminationField *input)
{
	CTPTradeApi::CThostFtdcDisseminationField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.SequenceSeries, input->SequenceSeries, sizeof(field.SequenceSeries));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	return field;
}
KingstarAPI::CThostFtdcDisseminationField CTPtoKSChange(CTPTradeApi::CThostFtdcDisseminationField *input)
{
	KingstarAPI::CThostFtdcDisseminationField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.SequenceSeries, input->SequenceSeries, sizeof(field.SequenceSeries));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	return field;
}
CTPTradeApi::CThostFtdcReqUserLoginField KStoCTPChange(KingstarAPI::CThostFtdcReqUserLoginField *input)
{
	CTPTradeApi::CThostFtdcReqUserLoginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.InterfaceProductInfo, input->InterfaceProductInfo, sizeof(field.InterfaceProductInfo));
	localmemcpy(field.ProtocolInfo, input->ProtocolInfo, sizeof(field.ProtocolInfo));
	localmemcpy(field.MacAddress, input->MacAddress, sizeof(field.MacAddress));
	localmemcpy(field.OneTimePassword, input->OneTimePassword, sizeof(field.OneTimePassword));
	localmemcpy(field.ClientIPAddress, input->ClientIPAddress, sizeof(field.ClientIPAddress));
	return field;
}
KingstarAPI::CThostFtdcReqUserLoginField CTPtoKSChange(CTPTradeApi::CThostFtdcReqUserLoginField *input)
{
	KingstarAPI::CThostFtdcReqUserLoginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.InterfaceProductInfo, input->InterfaceProductInfo, sizeof(field.InterfaceProductInfo));
	localmemcpy(field.ProtocolInfo, input->ProtocolInfo, sizeof(field.ProtocolInfo));
	localmemcpy(field.MacAddress, input->MacAddress, sizeof(field.MacAddress));
	localmemcpy(field.OneTimePassword, input->OneTimePassword, sizeof(field.OneTimePassword));
	localmemcpy(field.ClientIPAddress, input->ClientIPAddress, sizeof(field.ClientIPAddress));
	return field;
}
CTPTradeApi::CThostFtdcRspUserLoginField KStoCTPChange(KingstarAPI::CThostFtdcRspUserLoginField *input)
{
	CTPTradeApi::CThostFtdcRspUserLoginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.LoginTime, input->LoginTime, sizeof(field.LoginTime));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.SystemName, input->SystemName, sizeof(field.SystemName));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.MaxOrderRef, input->MaxOrderRef, sizeof(field.MaxOrderRef));
	localmemcpy(field.SHFETime, input->SHFETime, sizeof(field.SHFETime));
	localmemcpy(field.DCETime, input->DCETime, sizeof(field.DCETime));
	localmemcpy(field.CZCETime, input->CZCETime, sizeof(field.CZCETime));
	localmemcpy(field.FFEXTime, input->FFEXTime, sizeof(field.FFEXTime));
	localmemcpy(field.INETime, input->INETime, sizeof(field.INETime));
	return field;
}
KingstarAPI::CThostFtdcRspUserLoginField CTPtoKSChange(CTPTradeApi::CThostFtdcRspUserLoginField *input)
{
	KingstarAPI::CThostFtdcRspUserLoginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.LoginTime, input->LoginTime, sizeof(field.LoginTime));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.SystemName, input->SystemName, sizeof(field.SystemName));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.MaxOrderRef, input->MaxOrderRef, sizeof(field.MaxOrderRef));
	localmemcpy(field.SHFETime, input->SHFETime, sizeof(field.SHFETime));
	localmemcpy(field.DCETime, input->DCETime, sizeof(field.DCETime));
	localmemcpy(field.CZCETime, input->CZCETime, sizeof(field.CZCETime));
	localmemcpy(field.FFEXTime, input->FFEXTime, sizeof(field.FFEXTime));
	localmemcpy(field.INETime, input->INETime, sizeof(field.INETime));
	return field;
}
CTPTradeApi::CThostFtdcUserLogoutField KStoCTPChange(KingstarAPI::CThostFtdcUserLogoutField *input)
{
	CTPTradeApi::CThostFtdcUserLogoutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcUserLogoutField CTPtoKSChange(CTPTradeApi::CThostFtdcUserLogoutField *input)
{
	KingstarAPI::CThostFtdcUserLogoutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcForceUserLogoutField KStoCTPChange(KingstarAPI::CThostFtdcForceUserLogoutField *input)
{
	CTPTradeApi::CThostFtdcForceUserLogoutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcForceUserLogoutField CTPtoKSChange(CTPTradeApi::CThostFtdcForceUserLogoutField *input)
{
	KingstarAPI::CThostFtdcForceUserLogoutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcReqAuthenticateField KStoCTPChange(KingstarAPI::CThostFtdcReqAuthenticateField *input)
{
	CTPTradeApi::CThostFtdcReqAuthenticateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.AuthCode, input->AuthCode, sizeof(field.AuthCode));
	return field;
}
KingstarAPI::CThostFtdcReqAuthenticateField CTPtoKSChange(CTPTradeApi::CThostFtdcReqAuthenticateField *input)
{
	KingstarAPI::CThostFtdcReqAuthenticateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.AuthCode, input->AuthCode, sizeof(field.AuthCode));
	return field;
}
CTPTradeApi::CThostFtdcRspAuthenticateField KStoCTPChange(KingstarAPI::CThostFtdcRspAuthenticateField *input)
{
	CTPTradeApi::CThostFtdcRspAuthenticateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	return field;
}
KingstarAPI::CThostFtdcRspAuthenticateField CTPtoKSChange(CTPTradeApi::CThostFtdcRspAuthenticateField *input)
{
	KingstarAPI::CThostFtdcRspAuthenticateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	return field;
}
CTPTradeApi::CThostFtdcAuthenticationInfoField KStoCTPChange(KingstarAPI::CThostFtdcAuthenticationInfoField *input)
{
	CTPTradeApi::CThostFtdcAuthenticationInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.AuthInfo, input->AuthInfo, sizeof(field.AuthInfo));
	localmemcpy(field.IsResult, input->IsResult, sizeof(field.IsResult));
	return field;
}
KingstarAPI::CThostFtdcAuthenticationInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcAuthenticationInfoField *input)
{
	KingstarAPI::CThostFtdcAuthenticationInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.AuthInfo, input->AuthInfo, sizeof(field.AuthInfo));
	localmemcpy(field.IsResult, input->IsResult, sizeof(field.IsResult));
	return field;
}
CTPTradeApi::CThostFtdcTransferHeaderField KStoCTPChange(KingstarAPI::CThostFtdcTransferHeaderField *input)
{
	CTPTradeApi::CThostFtdcTransferHeaderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.Version, input->Version, sizeof(field.Version));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeSerial, input->TradeSerial, sizeof(field.TradeSerial));
	localmemcpy(field.FutureID, input->FutureID, sizeof(field.FutureID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.RecordNum, input->RecordNum, sizeof(field.RecordNum));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	return field;
}
KingstarAPI::CThostFtdcTransferHeaderField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferHeaderField *input)
{
	KingstarAPI::CThostFtdcTransferHeaderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.Version, input->Version, sizeof(field.Version));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeSerial, input->TradeSerial, sizeof(field.TradeSerial));
	localmemcpy(field.FutureID, input->FutureID, sizeof(field.FutureID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.RecordNum, input->RecordNum, sizeof(field.RecordNum));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	return field;
}
CTPTradeApi::CThostFtdcTransferBankToFutureReqField KStoCTPChange(KingstarAPI::CThostFtdcTransferBankToFutureReqField *input)
{
	CTPTradeApi::CThostFtdcTransferBankToFutureReqField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.FuturePwdFlag, input->FuturePwdFlag, sizeof(field.FuturePwdFlag));
	localmemcpy(field.FutureAccPwd, input->FutureAccPwd, sizeof(field.FutureAccPwd));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
KingstarAPI::CThostFtdcTransferBankToFutureReqField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferBankToFutureReqField *input)
{
	KingstarAPI::CThostFtdcTransferBankToFutureReqField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.FuturePwdFlag, input->FuturePwdFlag, sizeof(field.FuturePwdFlag));
	localmemcpy(field.FutureAccPwd, input->FutureAccPwd, sizeof(field.FutureAccPwd));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
CTPTradeApi::CThostFtdcTransferBankToFutureRspField KStoCTPChange(KingstarAPI::CThostFtdcTransferBankToFutureRspField *input)
{
	CTPTradeApi::CThostFtdcTransferBankToFutureRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RetCode, input->RetCode, sizeof(field.RetCode));
	localmemcpy(field.RetInfo, input->RetInfo, sizeof(field.RetInfo));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
KingstarAPI::CThostFtdcTransferBankToFutureRspField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferBankToFutureRspField *input)
{
	KingstarAPI::CThostFtdcTransferBankToFutureRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RetCode, input->RetCode, sizeof(field.RetCode));
	localmemcpy(field.RetInfo, input->RetInfo, sizeof(field.RetInfo));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
CTPTradeApi::CThostFtdcTransferFutureToBankReqField KStoCTPChange(KingstarAPI::CThostFtdcTransferFutureToBankReqField *input)
{
	CTPTradeApi::CThostFtdcTransferFutureToBankReqField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.FuturePwdFlag, input->FuturePwdFlag, sizeof(field.FuturePwdFlag));
	localmemcpy(field.FutureAccPwd, input->FutureAccPwd, sizeof(field.FutureAccPwd));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
KingstarAPI::CThostFtdcTransferFutureToBankReqField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferFutureToBankReqField *input)
{
	KingstarAPI::CThostFtdcTransferFutureToBankReqField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.FuturePwdFlag, input->FuturePwdFlag, sizeof(field.FuturePwdFlag));
	localmemcpy(field.FutureAccPwd, input->FutureAccPwd, sizeof(field.FutureAccPwd));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
CTPTradeApi::CThostFtdcTransferFutureToBankRspField KStoCTPChange(KingstarAPI::CThostFtdcTransferFutureToBankRspField *input)
{
	CTPTradeApi::CThostFtdcTransferFutureToBankRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RetCode, input->RetCode, sizeof(field.RetCode));
	localmemcpy(field.RetInfo, input->RetInfo, sizeof(field.RetInfo));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
KingstarAPI::CThostFtdcTransferFutureToBankRspField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferFutureToBankRspField *input)
{
	KingstarAPI::CThostFtdcTransferFutureToBankRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RetCode, input->RetCode, sizeof(field.RetCode));
	localmemcpy(field.RetInfo, input->RetInfo, sizeof(field.RetInfo));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
CTPTradeApi::CThostFtdcTransferQryBankReqField KStoCTPChange(KingstarAPI::CThostFtdcTransferQryBankReqField *input)
{
	CTPTradeApi::CThostFtdcTransferQryBankReqField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.FuturePwdFlag, input->FuturePwdFlag, sizeof(field.FuturePwdFlag));
	localmemcpy(field.FutureAccPwd, input->FutureAccPwd, sizeof(field.FutureAccPwd));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
KingstarAPI::CThostFtdcTransferQryBankReqField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferQryBankReqField *input)
{
	KingstarAPI::CThostFtdcTransferQryBankReqField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.FuturePwdFlag, input->FuturePwdFlag, sizeof(field.FuturePwdFlag));
	localmemcpy(field.FutureAccPwd, input->FutureAccPwd, sizeof(field.FutureAccPwd));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
CTPTradeApi::CThostFtdcTransferQryBankRspField KStoCTPChange(KingstarAPI::CThostFtdcTransferQryBankRspField *input)
{
	CTPTradeApi::CThostFtdcTransferQryBankRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RetCode, input->RetCode, sizeof(field.RetCode));
	localmemcpy(field.RetInfo, input->RetInfo, sizeof(field.RetInfo));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.UseAmt, input->UseAmt, sizeof(field.UseAmt));
	localmemcpy(field.FetchAmt, input->FetchAmt, sizeof(field.FetchAmt));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
KingstarAPI::CThostFtdcTransferQryBankRspField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferQryBankRspField *input)
{
	KingstarAPI::CThostFtdcTransferQryBankRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RetCode, input->RetCode, sizeof(field.RetCode));
	localmemcpy(field.RetInfo, input->RetInfo, sizeof(field.RetInfo));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.TradeAmt, input->TradeAmt, sizeof(field.TradeAmt));
	localmemcpy(field.UseAmt, input->UseAmt, sizeof(field.UseAmt));
	localmemcpy(field.FetchAmt, input->FetchAmt, sizeof(field.FetchAmt));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	return field;
}
CTPTradeApi::CThostFtdcTransferQryDetailReqField KStoCTPChange(KingstarAPI::CThostFtdcTransferQryDetailReqField *input)
{
	CTPTradeApi::CThostFtdcTransferQryDetailReqField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	return field;
}
KingstarAPI::CThostFtdcTransferQryDetailReqField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferQryDetailReqField *input)
{
	KingstarAPI::CThostFtdcTransferQryDetailReqField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	return field;
}
CTPTradeApi::CThostFtdcTransferQryDetailRspField KStoCTPChange(KingstarAPI::CThostFtdcTransferQryDetailRspField *input)
{
	CTPTradeApi::CThostFtdcTransferQryDetailRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.FutureID, input->FutureID, sizeof(field.FutureID));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.CertCode, input->CertCode, sizeof(field.CertCode));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	localmemcpy(field.TxAmount, input->TxAmount, sizeof(field.TxAmount));
	localmemcpy(field.Flag, input->Flag, sizeof(field.Flag));
	return field;
}
KingstarAPI::CThostFtdcTransferQryDetailRspField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferQryDetailRspField *input)
{
	KingstarAPI::CThostFtdcTransferQryDetailRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.FutureID, input->FutureID, sizeof(field.FutureID));
	localmemcpy(field.FutureAccount, input->FutureAccount, sizeof(field.FutureAccount));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.CertCode, input->CertCode, sizeof(field.CertCode));
	localmemcpy(field.CurrencyCode, input->CurrencyCode, sizeof(field.CurrencyCode));
	localmemcpy(field.TxAmount, input->TxAmount, sizeof(field.TxAmount));
	localmemcpy(field.Flag, input->Flag, sizeof(field.Flag));
	return field;
}
CTPTradeApi::CThostFtdcRspInfoField KStoCTPChange(KingstarAPI::CThostFtdcRspInfoField *input)
{
	CTPTradeApi::CThostFtdcRspInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcRspInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcRspInfoField *input)
{
	KingstarAPI::CThostFtdcRspInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcExchangeField KStoCTPChange(KingstarAPI::CThostFtdcExchangeField *input)
{
	CTPTradeApi::CThostFtdcExchangeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeName, input->ExchangeName, sizeof(field.ExchangeName));
	localmemcpy(field.ExchangeProperty, input->ExchangeProperty, sizeof(field.ExchangeProperty));
	return field;
}
KingstarAPI::CThostFtdcExchangeField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeField *input)
{
	KingstarAPI::CThostFtdcExchangeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeName, input->ExchangeName, sizeof(field.ExchangeName));
	localmemcpy(field.ExchangeProperty, input->ExchangeProperty, sizeof(field.ExchangeProperty));
	return field;
}
CTPTradeApi::CThostFtdcProductField KStoCTPChange(KingstarAPI::CThostFtdcProductField *input)
{
	CTPTradeApi::CThostFtdcProductField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ProductID, input->ProductID, sizeof(field.ProductID));
	localmemcpy(field.ProductName, input->ProductName, sizeof(field.ProductName));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ProductClass, input->ProductClass, sizeof(field.ProductClass));
	localmemcpy(field.VolumeMultiple, input->VolumeMultiple, sizeof(field.VolumeMultiple));
	localmemcpy(field.PriceTick, input->PriceTick, sizeof(field.PriceTick));
	localmemcpy(field.MaxMarketOrderVolume, input->MaxMarketOrderVolume, sizeof(field.MaxMarketOrderVolume));
	localmemcpy(field.MinMarketOrderVolume, input->MinMarketOrderVolume, sizeof(field.MinMarketOrderVolume));
	localmemcpy(field.MaxLimitOrderVolume, input->MaxLimitOrderVolume, sizeof(field.MaxLimitOrderVolume));
	localmemcpy(field.MinLimitOrderVolume, input->MinLimitOrderVolume, sizeof(field.MinLimitOrderVolume));
	localmemcpy(field.PositionType, input->PositionType, sizeof(field.PositionType));
	localmemcpy(field.PositionDateType, input->PositionDateType, sizeof(field.PositionDateType));
	localmemcpy(field.CloseDealType, input->CloseDealType, sizeof(field.CloseDealType));
	localmemcpy(field.TradeCurrencyID, input->TradeCurrencyID, sizeof(field.TradeCurrencyID));
	localmemcpy(field.MortgageFundUseRange, input->MortgageFundUseRange, sizeof(field.MortgageFundUseRange));
	localmemcpy(field.ExchangeProductID, input->ExchangeProductID, sizeof(field.ExchangeProductID));
	localmemcpy(field.UnderlyingMultiple, input->UnderlyingMultiple, sizeof(field.UnderlyingMultiple));
	return field;
}
KingstarAPI::CThostFtdcProductField CTPtoKSChange(CTPTradeApi::CThostFtdcProductField *input)
{
	KingstarAPI::CThostFtdcProductField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ProductID, input->ProductID, sizeof(field.ProductID));
	localmemcpy(field.ProductName, input->ProductName, sizeof(field.ProductName));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ProductClass, input->ProductClass, sizeof(field.ProductClass));
	localmemcpy(field.VolumeMultiple, input->VolumeMultiple, sizeof(field.VolumeMultiple));
	localmemcpy(field.PriceTick, input->PriceTick, sizeof(field.PriceTick));
	localmemcpy(field.MaxMarketOrderVolume, input->MaxMarketOrderVolume, sizeof(field.MaxMarketOrderVolume));
	localmemcpy(field.MinMarketOrderVolume, input->MinMarketOrderVolume, sizeof(field.MinMarketOrderVolume));
	localmemcpy(field.MaxLimitOrderVolume, input->MaxLimitOrderVolume, sizeof(field.MaxLimitOrderVolume));
	localmemcpy(field.MinLimitOrderVolume, input->MinLimitOrderVolume, sizeof(field.MinLimitOrderVolume));
	localmemcpy(field.PositionType, input->PositionType, sizeof(field.PositionType));
	localmemcpy(field.PositionDateType, input->PositionDateType, sizeof(field.PositionDateType));
	localmemcpy(field.CloseDealType, input->CloseDealType, sizeof(field.CloseDealType));
	localmemcpy(field.TradeCurrencyID, input->TradeCurrencyID, sizeof(field.TradeCurrencyID));
	localmemcpy(field.MortgageFundUseRange, input->MortgageFundUseRange, sizeof(field.MortgageFundUseRange));
	localmemcpy(field.ExchangeProductID, input->ExchangeProductID, sizeof(field.ExchangeProductID));
	localmemcpy(field.UnderlyingMultiple, input->UnderlyingMultiple, sizeof(field.UnderlyingMultiple));
	return field;
}
CTPTradeApi::CThostFtdcInstrumentField KStoCTPChange(KingstarAPI::CThostFtdcInstrumentField *input)
{
	CTPTradeApi::CThostFtdcInstrumentField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentName, input->InstrumentName, sizeof(field.InstrumentName));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ProductID, input->ProductID, sizeof(field.ProductID));
	localmemcpy(field.ProductClass, input->ProductClass, sizeof(field.ProductClass));
	localmemcpy(field.DeliveryYear, input->DeliveryYear, sizeof(field.DeliveryYear));
	localmemcpy(field.DeliveryMonth, input->DeliveryMonth, sizeof(field.DeliveryMonth));
	localmemcpy(field.MaxMarketOrderVolume, input->MaxMarketOrderVolume, sizeof(field.MaxMarketOrderVolume));
	localmemcpy(field.MinMarketOrderVolume, input->MinMarketOrderVolume, sizeof(field.MinMarketOrderVolume));
	localmemcpy(field.MaxLimitOrderVolume, input->MaxLimitOrderVolume, sizeof(field.MaxLimitOrderVolume));
	localmemcpy(field.MinLimitOrderVolume, input->MinLimitOrderVolume, sizeof(field.MinLimitOrderVolume));
	localmemcpy(field.VolumeMultiple, input->VolumeMultiple, sizeof(field.VolumeMultiple));
	localmemcpy(field.PriceTick, input->PriceTick, sizeof(field.PriceTick));
	localmemcpy(field.CreateDate, input->CreateDate, sizeof(field.CreateDate));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.ExpireDate, input->ExpireDate, sizeof(field.ExpireDate));
	localmemcpy(field.StartDelivDate, input->StartDelivDate, sizeof(field.StartDelivDate));
	localmemcpy(field.EndDelivDate, input->EndDelivDate, sizeof(field.EndDelivDate));
	localmemcpy(field.InstLifePhase, input->InstLifePhase, sizeof(field.InstLifePhase));
	localmemcpy(field.IsTrading, input->IsTrading, sizeof(field.IsTrading));
	localmemcpy(field.PositionType, input->PositionType, sizeof(field.PositionType));
	localmemcpy(field.PositionDateType, input->PositionDateType, sizeof(field.PositionDateType));
	localmemcpy(field.LongMarginRatio, input->LongMarginRatio, sizeof(field.LongMarginRatio));
	localmemcpy(field.ShortMarginRatio, input->ShortMarginRatio, sizeof(field.ShortMarginRatio));
	localmemcpy(field.MaxMarginSideAlgorithm, input->MaxMarginSideAlgorithm, sizeof(field.MaxMarginSideAlgorithm));
	localmemcpy(field.UnderlyingInstrID, input->UnderlyingInstrID, sizeof(field.UnderlyingInstrID));
	localmemcpy(field.StrikePrice, input->StrikePrice, sizeof(field.StrikePrice));
	localmemcpy(field.OptionsType, input->OptionsType, sizeof(field.OptionsType));
	localmemcpy(field.UnderlyingMultiple, input->UnderlyingMultiple, sizeof(field.UnderlyingMultiple));
	localmemcpy(field.CombinationType, input->CombinationType, sizeof(field.CombinationType));
	return field;
}
KingstarAPI::CThostFtdcInstrumentField CTPtoKSChange(CTPTradeApi::CThostFtdcInstrumentField *input)
{
	KingstarAPI::CThostFtdcInstrumentField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentName, input->InstrumentName, sizeof(field.InstrumentName));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ProductID, input->ProductID, sizeof(field.ProductID));
	localmemcpy(field.ProductClass, input->ProductClass, sizeof(field.ProductClass));
	localmemcpy(field.DeliveryYear, input->DeliveryYear, sizeof(field.DeliveryYear));
	localmemcpy(field.DeliveryMonth, input->DeliveryMonth, sizeof(field.DeliveryMonth));
	localmemcpy(field.MaxMarketOrderVolume, input->MaxMarketOrderVolume, sizeof(field.MaxMarketOrderVolume));
	localmemcpy(field.MinMarketOrderVolume, input->MinMarketOrderVolume, sizeof(field.MinMarketOrderVolume));
	localmemcpy(field.MaxLimitOrderVolume, input->MaxLimitOrderVolume, sizeof(field.MaxLimitOrderVolume));
	localmemcpy(field.MinLimitOrderVolume, input->MinLimitOrderVolume, sizeof(field.MinLimitOrderVolume));
	localmemcpy(field.VolumeMultiple, input->VolumeMultiple, sizeof(field.VolumeMultiple));
	localmemcpy(field.PriceTick, input->PriceTick, sizeof(field.PriceTick));
	localmemcpy(field.CreateDate, input->CreateDate, sizeof(field.CreateDate));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.ExpireDate, input->ExpireDate, sizeof(field.ExpireDate));
	localmemcpy(field.StartDelivDate, input->StartDelivDate, sizeof(field.StartDelivDate));
	localmemcpy(field.EndDelivDate, input->EndDelivDate, sizeof(field.EndDelivDate));
	localmemcpy(field.InstLifePhase, input->InstLifePhase, sizeof(field.InstLifePhase));
	localmemcpy(field.IsTrading, input->IsTrading, sizeof(field.IsTrading));
	localmemcpy(field.PositionType, input->PositionType, sizeof(field.PositionType));
	localmemcpy(field.PositionDateType, input->PositionDateType, sizeof(field.PositionDateType));
	localmemcpy(field.LongMarginRatio, input->LongMarginRatio, sizeof(field.LongMarginRatio));
	localmemcpy(field.ShortMarginRatio, input->ShortMarginRatio, sizeof(field.ShortMarginRatio));
	localmemcpy(field.MaxMarginSideAlgorithm, input->MaxMarginSideAlgorithm, sizeof(field.MaxMarginSideAlgorithm));
	localmemcpy(field.UnderlyingInstrID, input->UnderlyingInstrID, sizeof(field.UnderlyingInstrID));
	localmemcpy(field.StrikePrice, input->StrikePrice, sizeof(field.StrikePrice));
	localmemcpy(field.OptionsType, input->OptionsType, sizeof(field.OptionsType));
	localmemcpy(field.UnderlyingMultiple, input->UnderlyingMultiple, sizeof(field.UnderlyingMultiple));
	localmemcpy(field.CombinationType, input->CombinationType, sizeof(field.CombinationType));
	return field;
}
CTPTradeApi::CThostFtdcBrokerField KStoCTPChange(KingstarAPI::CThostFtdcBrokerField *input)
{
	CTPTradeApi::CThostFtdcBrokerField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerAbbr, input->BrokerAbbr, sizeof(field.BrokerAbbr));
	localmemcpy(field.BrokerName, input->BrokerName, sizeof(field.BrokerName));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
KingstarAPI::CThostFtdcBrokerField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerField *input)
{
	KingstarAPI::CThostFtdcBrokerField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerAbbr, input->BrokerAbbr, sizeof(field.BrokerAbbr));
	localmemcpy(field.BrokerName, input->BrokerName, sizeof(field.BrokerName));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
CTPTradeApi::CThostFtdcTraderField KStoCTPChange(KingstarAPI::CThostFtdcTraderField *input)
{
	CTPTradeApi::CThostFtdcTraderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallCount, input->InstallCount, sizeof(field.InstallCount));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
KingstarAPI::CThostFtdcTraderField CTPtoKSChange(CTPTradeApi::CThostFtdcTraderField *input)
{
	KingstarAPI::CThostFtdcTraderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallCount, input->InstallCount, sizeof(field.InstallCount));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
CTPTradeApi::CThostFtdcInvestorField KStoCTPChange(KingstarAPI::CThostFtdcInvestorField *input)
{
	CTPTradeApi::CThostFtdcInvestorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorGroupID, input->InvestorGroupID, sizeof(field.InvestorGroupID));
	localmemcpy(field.InvestorName, input->InvestorName, sizeof(field.InvestorName));
	localmemcpy(field.IdentifiedCardType, input->IdentifiedCardType, sizeof(field.IdentifiedCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.Mobile, input->Mobile, sizeof(field.Mobile));
	localmemcpy(field.CommModelID, input->CommModelID, sizeof(field.CommModelID));
	localmemcpy(field.MarginModelID, input->MarginModelID, sizeof(field.MarginModelID));
	return field;
}
KingstarAPI::CThostFtdcInvestorField CTPtoKSChange(CTPTradeApi::CThostFtdcInvestorField *input)
{
	KingstarAPI::CThostFtdcInvestorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorGroupID, input->InvestorGroupID, sizeof(field.InvestorGroupID));
	localmemcpy(field.InvestorName, input->InvestorName, sizeof(field.InvestorName));
	localmemcpy(field.IdentifiedCardType, input->IdentifiedCardType, sizeof(field.IdentifiedCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.Mobile, input->Mobile, sizeof(field.Mobile));
	localmemcpy(field.CommModelID, input->CommModelID, sizeof(field.CommModelID));
	localmemcpy(field.MarginModelID, input->MarginModelID, sizeof(field.MarginModelID));
	return field;
}
CTPTradeApi::CThostFtdcTradingCodeField KStoCTPChange(KingstarAPI::CThostFtdcTradingCodeField *input)
{
	CTPTradeApi::CThostFtdcTradingCodeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.ClientIDType, input->ClientIDType, sizeof(field.ClientIDType));
	return field;
}
KingstarAPI::CThostFtdcTradingCodeField CTPtoKSChange(CTPTradeApi::CThostFtdcTradingCodeField *input)
{
	KingstarAPI::CThostFtdcTradingCodeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.ClientIDType, input->ClientIDType, sizeof(field.ClientIDType));
	return field;
}
CTPTradeApi::CThostFtdcPartBrokerField KStoCTPChange(KingstarAPI::CThostFtdcPartBrokerField *input)
{
	CTPTradeApi::CThostFtdcPartBrokerField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
KingstarAPI::CThostFtdcPartBrokerField CTPtoKSChange(CTPTradeApi::CThostFtdcPartBrokerField *input)
{
	KingstarAPI::CThostFtdcPartBrokerField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
CTPTradeApi::CThostFtdcSuperUserField KStoCTPChange(KingstarAPI::CThostFtdcSuperUserField *input)
{
	CTPTradeApi::CThostFtdcSuperUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserName, input->UserName, sizeof(field.UserName));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
KingstarAPI::CThostFtdcSuperUserField CTPtoKSChange(CTPTradeApi::CThostFtdcSuperUserField *input)
{
	KingstarAPI::CThostFtdcSuperUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserName, input->UserName, sizeof(field.UserName));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
CTPTradeApi::CThostFtdcSuperUserFunctionField KStoCTPChange(KingstarAPI::CThostFtdcSuperUserFunctionField *input)
{
	CTPTradeApi::CThostFtdcSuperUserFunctionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.FunctionCode, input->FunctionCode, sizeof(field.FunctionCode));
	return field;
}
KingstarAPI::CThostFtdcSuperUserFunctionField CTPtoKSChange(CTPTradeApi::CThostFtdcSuperUserFunctionField *input)
{
	KingstarAPI::CThostFtdcSuperUserFunctionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.FunctionCode, input->FunctionCode, sizeof(field.FunctionCode));
	return field;
}
CTPTradeApi::CThostFtdcInvestorGroupField KStoCTPChange(KingstarAPI::CThostFtdcInvestorGroupField *input)
{
	CTPTradeApi::CThostFtdcInvestorGroupField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorGroupID, input->InvestorGroupID, sizeof(field.InvestorGroupID));
	localmemcpy(field.InvestorGroupName, input->InvestorGroupName, sizeof(field.InvestorGroupName));
	return field;
}
KingstarAPI::CThostFtdcInvestorGroupField CTPtoKSChange(CTPTradeApi::CThostFtdcInvestorGroupField *input)
{
	KingstarAPI::CThostFtdcInvestorGroupField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorGroupID, input->InvestorGroupID, sizeof(field.InvestorGroupID));
	localmemcpy(field.InvestorGroupName, input->InvestorGroupName, sizeof(field.InvestorGroupName));
	return field;
}
CTPTradeApi::CThostFtdcTradingAccountField KStoCTPChange(KingstarAPI::CThostFtdcTradingAccountField *input)
{
	CTPTradeApi::CThostFtdcTradingAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.PreMortgage, input->PreMortgage, sizeof(field.PreMortgage));
	localmemcpy(field.PreCredit, input->PreCredit, sizeof(field.PreCredit));
	localmemcpy(field.PreDeposit, input->PreDeposit, sizeof(field.PreDeposit));
	localmemcpy(field.PreBalance, input->PreBalance, sizeof(field.PreBalance));
	localmemcpy(field.PreMargin, input->PreMargin, sizeof(field.PreMargin));
	localmemcpy(field.InterestBase, input->InterestBase, sizeof(field.InterestBase));
	localmemcpy(field.Interest, input->Interest, sizeof(field.Interest));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.Withdraw, input->Withdraw, sizeof(field.Withdraw));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.CurrMargin, input->CurrMargin, sizeof(field.CurrMargin));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.Balance, input->Balance, sizeof(field.Balance));
	localmemcpy(field.Available, input->Available, sizeof(field.Available));
	localmemcpy(field.WithdrawQuota, input->WithdrawQuota, sizeof(field.WithdrawQuota));
	localmemcpy(field.Reserve, input->Reserve, sizeof(field.Reserve));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.Credit, input->Credit, sizeof(field.Credit));
	localmemcpy(field.Mortgage, input->Mortgage, sizeof(field.Mortgage));
	localmemcpy(field.ExchangeMargin, input->ExchangeMargin, sizeof(field.ExchangeMargin));
	localmemcpy(field.DeliveryMargin, input->DeliveryMargin, sizeof(field.DeliveryMargin));
	localmemcpy(field.ExchangeDeliveryMargin, input->ExchangeDeliveryMargin, sizeof(field.ExchangeDeliveryMargin));
	localmemcpy(field.ReserveBalance, input->ReserveBalance, sizeof(field.ReserveBalance));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.PreFundMortgageIn, input->PreFundMortgageIn, sizeof(field.PreFundMortgageIn));
	localmemcpy(field.PreFundMortgageOut, input->PreFundMortgageOut, sizeof(field.PreFundMortgageOut));
	localmemcpy(field.FundMortgageIn, input->FundMortgageIn, sizeof(field.FundMortgageIn));
	localmemcpy(field.FundMortgageOut, input->FundMortgageOut, sizeof(field.FundMortgageOut));
	localmemcpy(field.FundMortgageAvailable, input->FundMortgageAvailable, sizeof(field.FundMortgageAvailable));
	localmemcpy(field.MortgageableFund, input->MortgageableFund, sizeof(field.MortgageableFund));
	localmemcpy(field.SpecProductMargin, input->SpecProductMargin, sizeof(field.SpecProductMargin));
	localmemcpy(field.SpecProductFrozenMargin, input->SpecProductFrozenMargin, sizeof(field.SpecProductFrozenMargin));
	localmemcpy(field.SpecProductCommission, input->SpecProductCommission, sizeof(field.SpecProductCommission));
	localmemcpy(field.SpecProductFrozenCommission, input->SpecProductFrozenCommission, sizeof(field.SpecProductFrozenCommission));
	localmemcpy(field.SpecProductPositionProfit, input->SpecProductPositionProfit, sizeof(field.SpecProductPositionProfit));
	localmemcpy(field.SpecProductCloseProfit, input->SpecProductCloseProfit, sizeof(field.SpecProductCloseProfit));
	localmemcpy(field.SpecProductPositionProfitByAlg, input->SpecProductPositionProfitByAlg, sizeof(field.SpecProductPositionProfitByAlg));
	localmemcpy(field.SpecProductExchangeMargin, input->SpecProductExchangeMargin, sizeof(field.SpecProductExchangeMargin));
	return field;
}
KingstarAPI::CThostFtdcTradingAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcTradingAccountField *input)
{
	KingstarAPI::CThostFtdcTradingAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.PreMortgage, input->PreMortgage, sizeof(field.PreMortgage));
	localmemcpy(field.PreCredit, input->PreCredit, sizeof(field.PreCredit));
	localmemcpy(field.PreDeposit, input->PreDeposit, sizeof(field.PreDeposit));
	localmemcpy(field.PreBalance, input->PreBalance, sizeof(field.PreBalance));
	localmemcpy(field.PreMargin, input->PreMargin, sizeof(field.PreMargin));
	localmemcpy(field.InterestBase, input->InterestBase, sizeof(field.InterestBase));
	localmemcpy(field.Interest, input->Interest, sizeof(field.Interest));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.Withdraw, input->Withdraw, sizeof(field.Withdraw));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.CurrMargin, input->CurrMargin, sizeof(field.CurrMargin));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.Balance, input->Balance, sizeof(field.Balance));
	localmemcpy(field.Available, input->Available, sizeof(field.Available));
	localmemcpy(field.WithdrawQuota, input->WithdrawQuota, sizeof(field.WithdrawQuota));
	localmemcpy(field.Reserve, input->Reserve, sizeof(field.Reserve));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.Credit, input->Credit, sizeof(field.Credit));
	localmemcpy(field.Mortgage, input->Mortgage, sizeof(field.Mortgage));
	localmemcpy(field.ExchangeMargin, input->ExchangeMargin, sizeof(field.ExchangeMargin));
	localmemcpy(field.DeliveryMargin, input->DeliveryMargin, sizeof(field.DeliveryMargin));
	localmemcpy(field.ExchangeDeliveryMargin, input->ExchangeDeliveryMargin, sizeof(field.ExchangeDeliveryMargin));
	localmemcpy(field.ReserveBalance, input->ReserveBalance, sizeof(field.ReserveBalance));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.PreFundMortgageIn, input->PreFundMortgageIn, sizeof(field.PreFundMortgageIn));
	localmemcpy(field.PreFundMortgageOut, input->PreFundMortgageOut, sizeof(field.PreFundMortgageOut));
	localmemcpy(field.FundMortgageIn, input->FundMortgageIn, sizeof(field.FundMortgageIn));
	localmemcpy(field.FundMortgageOut, input->FundMortgageOut, sizeof(field.FundMortgageOut));
	localmemcpy(field.FundMortgageAvailable, input->FundMortgageAvailable, sizeof(field.FundMortgageAvailable));
	localmemcpy(field.MortgageableFund, input->MortgageableFund, sizeof(field.MortgageableFund));
	localmemcpy(field.SpecProductMargin, input->SpecProductMargin, sizeof(field.SpecProductMargin));
	localmemcpy(field.SpecProductFrozenMargin, input->SpecProductFrozenMargin, sizeof(field.SpecProductFrozenMargin));
	localmemcpy(field.SpecProductCommission, input->SpecProductCommission, sizeof(field.SpecProductCommission));
	localmemcpy(field.SpecProductFrozenCommission, input->SpecProductFrozenCommission, sizeof(field.SpecProductFrozenCommission));
	localmemcpy(field.SpecProductPositionProfit, input->SpecProductPositionProfit, sizeof(field.SpecProductPositionProfit));
	localmemcpy(field.SpecProductCloseProfit, input->SpecProductCloseProfit, sizeof(field.SpecProductCloseProfit));
	localmemcpy(field.SpecProductPositionProfitByAlg, input->SpecProductPositionProfitByAlg, sizeof(field.SpecProductPositionProfitByAlg));
	localmemcpy(field.SpecProductExchangeMargin, input->SpecProductExchangeMargin, sizeof(field.SpecProductExchangeMargin));
	return field;
}
CTPTradeApi::CThostFtdcInvestorPositionField KStoCTPChange(KingstarAPI::CThostFtdcInvestorPositionField *input)
{
	CTPTradeApi::CThostFtdcInvestorPositionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.PositionDate, input->PositionDate, sizeof(field.PositionDate));
	localmemcpy(field.YdPosition, input->YdPosition, sizeof(field.YdPosition));
	localmemcpy(field.Position, input->Position, sizeof(field.Position));
	localmemcpy(field.LongFrozen, input->LongFrozen, sizeof(field.LongFrozen));
	localmemcpy(field.ShortFrozen, input->ShortFrozen, sizeof(field.ShortFrozen));
	localmemcpy(field.LongFrozenAmount, input->LongFrozenAmount, sizeof(field.LongFrozenAmount));
	localmemcpy(field.ShortFrozenAmount, input->ShortFrozenAmount, sizeof(field.ShortFrozenAmount));
	localmemcpy(field.OpenVolume, input->OpenVolume, sizeof(field.OpenVolume));
	localmemcpy(field.CloseVolume, input->CloseVolume, sizeof(field.CloseVolume));
	localmemcpy(field.OpenAmount, input->OpenAmount, sizeof(field.OpenAmount));
	localmemcpy(field.CloseAmount, input->CloseAmount, sizeof(field.CloseAmount));
	localmemcpy(field.PositionCost, input->PositionCost, sizeof(field.PositionCost));
	localmemcpy(field.PreMargin, input->PreMargin, sizeof(field.PreMargin));
	localmemcpy(field.UseMargin, input->UseMargin, sizeof(field.UseMargin));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OpenCost, input->OpenCost, sizeof(field.OpenCost));
	localmemcpy(field.ExchangeMargin, input->ExchangeMargin, sizeof(field.ExchangeMargin));
	localmemcpy(field.CombPosition, input->CombPosition, sizeof(field.CombPosition));
	localmemcpy(field.CombLongFrozen, input->CombLongFrozen, sizeof(field.CombLongFrozen));
	localmemcpy(field.CombShortFrozen, input->CombShortFrozen, sizeof(field.CombShortFrozen));
	localmemcpy(field.CloseProfitByDate, input->CloseProfitByDate, sizeof(field.CloseProfitByDate));
	localmemcpy(field.CloseProfitByTrade, input->CloseProfitByTrade, sizeof(field.CloseProfitByTrade));
	localmemcpy(field.TodayPosition, input->TodayPosition, sizeof(field.TodayPosition));
	localmemcpy(field.MarginRateByMoney, input->MarginRateByMoney, sizeof(field.MarginRateByMoney));
	localmemcpy(field.MarginRateByVolume, input->MarginRateByVolume, sizeof(field.MarginRateByVolume));
	localmemcpy(field.StrikeFrozen, input->StrikeFrozen, sizeof(field.StrikeFrozen));
	localmemcpy(field.StrikeFrozenAmount, input->StrikeFrozenAmount, sizeof(field.StrikeFrozenAmount));
	localmemcpy(field.AbandonFrozen, input->AbandonFrozen, sizeof(field.AbandonFrozen));
	return field;
}
KingstarAPI::CThostFtdcInvestorPositionField CTPtoKSChange(CTPTradeApi::CThostFtdcInvestorPositionField *input)
{
	KingstarAPI::CThostFtdcInvestorPositionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.PositionDate, input->PositionDate, sizeof(field.PositionDate));
	localmemcpy(field.YdPosition, input->YdPosition, sizeof(field.YdPosition));
	localmemcpy(field.Position, input->Position, sizeof(field.Position));
	localmemcpy(field.LongFrozen, input->LongFrozen, sizeof(field.LongFrozen));
	localmemcpy(field.ShortFrozen, input->ShortFrozen, sizeof(field.ShortFrozen));
	localmemcpy(field.LongFrozenAmount, input->LongFrozenAmount, sizeof(field.LongFrozenAmount));
	localmemcpy(field.ShortFrozenAmount, input->ShortFrozenAmount, sizeof(field.ShortFrozenAmount));
	localmemcpy(field.OpenVolume, input->OpenVolume, sizeof(field.OpenVolume));
	localmemcpy(field.CloseVolume, input->CloseVolume, sizeof(field.CloseVolume));
	localmemcpy(field.OpenAmount, input->OpenAmount, sizeof(field.OpenAmount));
	localmemcpy(field.CloseAmount, input->CloseAmount, sizeof(field.CloseAmount));
	localmemcpy(field.PositionCost, input->PositionCost, sizeof(field.PositionCost));
	localmemcpy(field.PreMargin, input->PreMargin, sizeof(field.PreMargin));
	localmemcpy(field.UseMargin, input->UseMargin, sizeof(field.UseMargin));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OpenCost, input->OpenCost, sizeof(field.OpenCost));
	localmemcpy(field.ExchangeMargin, input->ExchangeMargin, sizeof(field.ExchangeMargin));
	localmemcpy(field.CombPosition, input->CombPosition, sizeof(field.CombPosition));
	localmemcpy(field.CombLongFrozen, input->CombLongFrozen, sizeof(field.CombLongFrozen));
	localmemcpy(field.CombShortFrozen, input->CombShortFrozen, sizeof(field.CombShortFrozen));
	localmemcpy(field.CloseProfitByDate, input->CloseProfitByDate, sizeof(field.CloseProfitByDate));
	localmemcpy(field.CloseProfitByTrade, input->CloseProfitByTrade, sizeof(field.CloseProfitByTrade));
	localmemcpy(field.TodayPosition, input->TodayPosition, sizeof(field.TodayPosition));
	localmemcpy(field.MarginRateByMoney, input->MarginRateByMoney, sizeof(field.MarginRateByMoney));
	localmemcpy(field.MarginRateByVolume, input->MarginRateByVolume, sizeof(field.MarginRateByVolume));
	localmemcpy(field.StrikeFrozen, input->StrikeFrozen, sizeof(field.StrikeFrozen));
	localmemcpy(field.StrikeFrozenAmount, input->StrikeFrozenAmount, sizeof(field.StrikeFrozenAmount));
	localmemcpy(field.AbandonFrozen, input->AbandonFrozen, sizeof(field.AbandonFrozen));
	return field;
}
CTPTradeApi::CThostFtdcInstrumentMarginRateField KStoCTPChange(KingstarAPI::CThostFtdcInstrumentMarginRateField *input)
{
	CTPTradeApi::CThostFtdcInstrumentMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
KingstarAPI::CThostFtdcInstrumentMarginRateField CTPtoKSChange(CTPTradeApi::CThostFtdcInstrumentMarginRateField *input)
{
	KingstarAPI::CThostFtdcInstrumentMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
CTPTradeApi::CThostFtdcInstrumentCommissionRateField KStoCTPChange(KingstarAPI::CThostFtdcInstrumentCommissionRateField *input)
{
	CTPTradeApi::CThostFtdcInstrumentCommissionRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OpenRatioByMoney, input->OpenRatioByMoney, sizeof(field.OpenRatioByMoney));
	localmemcpy(field.OpenRatioByVolume, input->OpenRatioByVolume, sizeof(field.OpenRatioByVolume));
	localmemcpy(field.CloseRatioByMoney, input->CloseRatioByMoney, sizeof(field.CloseRatioByMoney));
	localmemcpy(field.CloseRatioByVolume, input->CloseRatioByVolume, sizeof(field.CloseRatioByVolume));
	localmemcpy(field.CloseTodayRatioByMoney, input->CloseTodayRatioByMoney, sizeof(field.CloseTodayRatioByMoney));
	localmemcpy(field.CloseTodayRatioByVolume, input->CloseTodayRatioByVolume, sizeof(field.CloseTodayRatioByVolume));
	return field;
}
KingstarAPI::CThostFtdcInstrumentCommissionRateField CTPtoKSChange(CTPTradeApi::CThostFtdcInstrumentCommissionRateField *input)
{
	KingstarAPI::CThostFtdcInstrumentCommissionRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OpenRatioByMoney, input->OpenRatioByMoney, sizeof(field.OpenRatioByMoney));
	localmemcpy(field.OpenRatioByVolume, input->OpenRatioByVolume, sizeof(field.OpenRatioByVolume));
	localmemcpy(field.CloseRatioByMoney, input->CloseRatioByMoney, sizeof(field.CloseRatioByMoney));
	localmemcpy(field.CloseRatioByVolume, input->CloseRatioByVolume, sizeof(field.CloseRatioByVolume));
	localmemcpy(field.CloseTodayRatioByMoney, input->CloseTodayRatioByMoney, sizeof(field.CloseTodayRatioByMoney));
	localmemcpy(field.CloseTodayRatioByVolume, input->CloseTodayRatioByVolume, sizeof(field.CloseTodayRatioByVolume));
	return field;
}
CTPTradeApi::CThostFtdcDepthMarketDataField KStoCTPChange(KingstarAPI::CThostFtdcDepthMarketDataField *input)
{
	CTPTradeApi::CThostFtdcDepthMarketDataField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.LastPrice, input->LastPrice, sizeof(field.LastPrice));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.PreClosePrice, input->PreClosePrice, sizeof(field.PreClosePrice));
	localmemcpy(field.PreOpenInterest, input->PreOpenInterest, sizeof(field.PreOpenInterest));
	localmemcpy(field.OpenPrice, input->OpenPrice, sizeof(field.OpenPrice));
	localmemcpy(field.HighestPrice, input->HighestPrice, sizeof(field.HighestPrice));
	localmemcpy(field.LowestPrice, input->LowestPrice, sizeof(field.LowestPrice));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.Turnover, input->Turnover, sizeof(field.Turnover));
	localmemcpy(field.OpenInterest, input->OpenInterest, sizeof(field.OpenInterest));
	localmemcpy(field.ClosePrice, input->ClosePrice, sizeof(field.ClosePrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.UpperLimitPrice, input->UpperLimitPrice, sizeof(field.UpperLimitPrice));
	localmemcpy(field.LowerLimitPrice, input->LowerLimitPrice, sizeof(field.LowerLimitPrice));
	localmemcpy(field.PreDelta, input->PreDelta, sizeof(field.PreDelta));
	localmemcpy(field.CurrDelta, input->CurrDelta, sizeof(field.CurrDelta));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.UpdateMillisec, input->UpdateMillisec, sizeof(field.UpdateMillisec));
	localmemcpy(field.BidPrice1, input->BidPrice1, sizeof(field.BidPrice1));
	localmemcpy(field.BidVolume1, input->BidVolume1, sizeof(field.BidVolume1));
	localmemcpy(field.AskPrice1, input->AskPrice1, sizeof(field.AskPrice1));
	localmemcpy(field.AskVolume1, input->AskVolume1, sizeof(field.AskVolume1));
	localmemcpy(field.BidPrice2, input->BidPrice2, sizeof(field.BidPrice2));
	localmemcpy(field.BidVolume2, input->BidVolume2, sizeof(field.BidVolume2));
	localmemcpy(field.AskPrice2, input->AskPrice2, sizeof(field.AskPrice2));
	localmemcpy(field.AskVolume2, input->AskVolume2, sizeof(field.AskVolume2));
	localmemcpy(field.BidPrice3, input->BidPrice3, sizeof(field.BidPrice3));
	localmemcpy(field.BidVolume3, input->BidVolume3, sizeof(field.BidVolume3));
	localmemcpy(field.AskPrice3, input->AskPrice3, sizeof(field.AskPrice3));
	localmemcpy(field.AskVolume3, input->AskVolume3, sizeof(field.AskVolume3));
	localmemcpy(field.BidPrice4, input->BidPrice4, sizeof(field.BidPrice4));
	localmemcpy(field.BidVolume4, input->BidVolume4, sizeof(field.BidVolume4));
	localmemcpy(field.AskPrice4, input->AskPrice4, sizeof(field.AskPrice4));
	localmemcpy(field.AskVolume4, input->AskVolume4, sizeof(field.AskVolume4));
	localmemcpy(field.BidPrice5, input->BidPrice5, sizeof(field.BidPrice5));
	localmemcpy(field.BidVolume5, input->BidVolume5, sizeof(field.BidVolume5));
	localmemcpy(field.AskPrice5, input->AskPrice5, sizeof(field.AskPrice5));
	localmemcpy(field.AskVolume5, input->AskVolume5, sizeof(field.AskVolume5));
	localmemcpy(field.AveragePrice, input->AveragePrice, sizeof(field.AveragePrice));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	return field;
}
KingstarAPI::CThostFtdcDepthMarketDataField CTPtoKSChange(CTPTradeApi::CThostFtdcDepthMarketDataField *input)
{
	KingstarAPI::CThostFtdcDepthMarketDataField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.LastPrice, input->LastPrice, sizeof(field.LastPrice));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.PreClosePrice, input->PreClosePrice, sizeof(field.PreClosePrice));
	localmemcpy(field.PreOpenInterest, input->PreOpenInterest, sizeof(field.PreOpenInterest));
	localmemcpy(field.OpenPrice, input->OpenPrice, sizeof(field.OpenPrice));
	localmemcpy(field.HighestPrice, input->HighestPrice, sizeof(field.HighestPrice));
	localmemcpy(field.LowestPrice, input->LowestPrice, sizeof(field.LowestPrice));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.Turnover, input->Turnover, sizeof(field.Turnover));
	localmemcpy(field.OpenInterest, input->OpenInterest, sizeof(field.OpenInterest));
	localmemcpy(field.ClosePrice, input->ClosePrice, sizeof(field.ClosePrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.UpperLimitPrice, input->UpperLimitPrice, sizeof(field.UpperLimitPrice));
	localmemcpy(field.LowerLimitPrice, input->LowerLimitPrice, sizeof(field.LowerLimitPrice));
	localmemcpy(field.PreDelta, input->PreDelta, sizeof(field.PreDelta));
	localmemcpy(field.CurrDelta, input->CurrDelta, sizeof(field.CurrDelta));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.UpdateMillisec, input->UpdateMillisec, sizeof(field.UpdateMillisec));
	localmemcpy(field.BidPrice1, input->BidPrice1, sizeof(field.BidPrice1));
	localmemcpy(field.BidVolume1, input->BidVolume1, sizeof(field.BidVolume1));
	localmemcpy(field.AskPrice1, input->AskPrice1, sizeof(field.AskPrice1));
	localmemcpy(field.AskVolume1, input->AskVolume1, sizeof(field.AskVolume1));
	localmemcpy(field.BidPrice2, input->BidPrice2, sizeof(field.BidPrice2));
	localmemcpy(field.BidVolume2, input->BidVolume2, sizeof(field.BidVolume2));
	localmemcpy(field.AskPrice2, input->AskPrice2, sizeof(field.AskPrice2));
	localmemcpy(field.AskVolume2, input->AskVolume2, sizeof(field.AskVolume2));
	localmemcpy(field.BidPrice3, input->BidPrice3, sizeof(field.BidPrice3));
	localmemcpy(field.BidVolume3, input->BidVolume3, sizeof(field.BidVolume3));
	localmemcpy(field.AskPrice3, input->AskPrice3, sizeof(field.AskPrice3));
	localmemcpy(field.AskVolume3, input->AskVolume3, sizeof(field.AskVolume3));
	localmemcpy(field.BidPrice4, input->BidPrice4, sizeof(field.BidPrice4));
	localmemcpy(field.BidVolume4, input->BidVolume4, sizeof(field.BidVolume4));
	localmemcpy(field.AskPrice4, input->AskPrice4, sizeof(field.AskPrice4));
	localmemcpy(field.AskVolume4, input->AskVolume4, sizeof(field.AskVolume4));
	localmemcpy(field.BidPrice5, input->BidPrice5, sizeof(field.BidPrice5));
	localmemcpy(field.BidVolume5, input->BidVolume5, sizeof(field.BidVolume5));
	localmemcpy(field.AskPrice5, input->AskPrice5, sizeof(field.AskPrice5));
	localmemcpy(field.AskVolume5, input->AskVolume5, sizeof(field.AskVolume5));
	localmemcpy(field.AveragePrice, input->AveragePrice, sizeof(field.AveragePrice));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	return field;
}
CTPTradeApi::CThostFtdcInstrumentTradingRightField KStoCTPChange(KingstarAPI::CThostFtdcInstrumentTradingRightField *input)
{
	CTPTradeApi::CThostFtdcInstrumentTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.TradingRight, input->TradingRight, sizeof(field.TradingRight));
	return field;
}
KingstarAPI::CThostFtdcInstrumentTradingRightField CTPtoKSChange(CTPTradeApi::CThostFtdcInstrumentTradingRightField *input)
{
	KingstarAPI::CThostFtdcInstrumentTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.TradingRight, input->TradingRight, sizeof(field.TradingRight));
	return field;
}
CTPTradeApi::CThostFtdcBrokerUserField KStoCTPChange(KingstarAPI::CThostFtdcBrokerUserField *input)
{
	CTPTradeApi::CThostFtdcBrokerUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserName, input->UserName, sizeof(field.UserName));
	localmemcpy(field.UserType, input->UserType, sizeof(field.UserType));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.IsUsingOTP, input->IsUsingOTP, sizeof(field.IsUsingOTP));
	return field;
}
KingstarAPI::CThostFtdcBrokerUserField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerUserField *input)
{
	KingstarAPI::CThostFtdcBrokerUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserName, input->UserName, sizeof(field.UserName));
	localmemcpy(field.UserType, input->UserType, sizeof(field.UserType));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.IsUsingOTP, input->IsUsingOTP, sizeof(field.IsUsingOTP));
	return field;
}
CTPTradeApi::CThostFtdcBrokerUserPasswordField KStoCTPChange(KingstarAPI::CThostFtdcBrokerUserPasswordField *input)
{
	CTPTradeApi::CThostFtdcBrokerUserPasswordField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	return field;
}
KingstarAPI::CThostFtdcBrokerUserPasswordField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerUserPasswordField *input)
{
	KingstarAPI::CThostFtdcBrokerUserPasswordField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	return field;
}
CTPTradeApi::CThostFtdcBrokerUserFunctionField KStoCTPChange(KingstarAPI::CThostFtdcBrokerUserFunctionField *input)
{
	CTPTradeApi::CThostFtdcBrokerUserFunctionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.BrokerFunctionCode, input->BrokerFunctionCode, sizeof(field.BrokerFunctionCode));
	return field;
}
KingstarAPI::CThostFtdcBrokerUserFunctionField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerUserFunctionField *input)
{
	KingstarAPI::CThostFtdcBrokerUserFunctionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.BrokerFunctionCode, input->BrokerFunctionCode, sizeof(field.BrokerFunctionCode));
	return field;
}
CTPTradeApi::CThostFtdcTraderOfferField KStoCTPChange(KingstarAPI::CThostFtdcTraderOfferField *input)
{
	CTPTradeApi::CThostFtdcTraderOfferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.TraderConnectStatus, input->TraderConnectStatus, sizeof(field.TraderConnectStatus));
	localmemcpy(field.ConnectRequestDate, input->ConnectRequestDate, sizeof(field.ConnectRequestDate));
	localmemcpy(field.ConnectRequestTime, input->ConnectRequestTime, sizeof(field.ConnectRequestTime));
	localmemcpy(field.LastReportDate, input->LastReportDate, sizeof(field.LastReportDate));
	localmemcpy(field.LastReportTime, input->LastReportTime, sizeof(field.LastReportTime));
	localmemcpy(field.ConnectDate, input->ConnectDate, sizeof(field.ConnectDate));
	localmemcpy(field.ConnectTime, input->ConnectTime, sizeof(field.ConnectTime));
	localmemcpy(field.StartDate, input->StartDate, sizeof(field.StartDate));
	localmemcpy(field.StartTime, input->StartTime, sizeof(field.StartTime));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MaxTradeID, input->MaxTradeID, sizeof(field.MaxTradeID));
	localmemcpy(field.MaxOrderMessageReference, input->MaxOrderMessageReference, sizeof(field.MaxOrderMessageReference));
	return field;
}
KingstarAPI::CThostFtdcTraderOfferField CTPtoKSChange(CTPTradeApi::CThostFtdcTraderOfferField *input)
{
	KingstarAPI::CThostFtdcTraderOfferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.TraderConnectStatus, input->TraderConnectStatus, sizeof(field.TraderConnectStatus));
	localmemcpy(field.ConnectRequestDate, input->ConnectRequestDate, sizeof(field.ConnectRequestDate));
	localmemcpy(field.ConnectRequestTime, input->ConnectRequestTime, sizeof(field.ConnectRequestTime));
	localmemcpy(field.LastReportDate, input->LastReportDate, sizeof(field.LastReportDate));
	localmemcpy(field.LastReportTime, input->LastReportTime, sizeof(field.LastReportTime));
	localmemcpy(field.ConnectDate, input->ConnectDate, sizeof(field.ConnectDate));
	localmemcpy(field.ConnectTime, input->ConnectTime, sizeof(field.ConnectTime));
	localmemcpy(field.StartDate, input->StartDate, sizeof(field.StartDate));
	localmemcpy(field.StartTime, input->StartTime, sizeof(field.StartTime));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MaxTradeID, input->MaxTradeID, sizeof(field.MaxTradeID));
	localmemcpy(field.MaxOrderMessageReference, input->MaxOrderMessageReference, sizeof(field.MaxOrderMessageReference));
	return field;
}
CTPTradeApi::CThostFtdcSettlementInfoField KStoCTPChange(KingstarAPI::CThostFtdcSettlementInfoField *input)
{
	CTPTradeApi::CThostFtdcSettlementInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.Content, input->Content, sizeof(field.Content));
	return field;
}
KingstarAPI::CThostFtdcSettlementInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcSettlementInfoField *input)
{
	KingstarAPI::CThostFtdcSettlementInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.Content, input->Content, sizeof(field.Content));
	return field;
}
CTPTradeApi::CThostFtdcInstrumentMarginRateAdjustField KStoCTPChange(KingstarAPI::CThostFtdcInstrumentMarginRateAdjustField *input)
{
	CTPTradeApi::CThostFtdcInstrumentMarginRateAdjustField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
KingstarAPI::CThostFtdcInstrumentMarginRateAdjustField CTPtoKSChange(CTPTradeApi::CThostFtdcInstrumentMarginRateAdjustField *input)
{
	KingstarAPI::CThostFtdcInstrumentMarginRateAdjustField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
CTPTradeApi::CThostFtdcExchangeMarginRateField KStoCTPChange(KingstarAPI::CThostFtdcExchangeMarginRateField *input)
{
	CTPTradeApi::CThostFtdcExchangeMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	return field;
}
KingstarAPI::CThostFtdcExchangeMarginRateField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeMarginRateField *input)
{
	KingstarAPI::CThostFtdcExchangeMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	return field;
}
CTPTradeApi::CThostFtdcExchangeMarginRateAdjustField KStoCTPChange(KingstarAPI::CThostFtdcExchangeMarginRateAdjustField *input)
{
	CTPTradeApi::CThostFtdcExchangeMarginRateAdjustField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	localmemcpy(field.ExchLongMarginRatioByMoney, input->ExchLongMarginRatioByMoney, sizeof(field.ExchLongMarginRatioByMoney));
	localmemcpy(field.ExchLongMarginRatioByVolume, input->ExchLongMarginRatioByVolume, sizeof(field.ExchLongMarginRatioByVolume));
	localmemcpy(field.ExchShortMarginRatioByMoney, input->ExchShortMarginRatioByMoney, sizeof(field.ExchShortMarginRatioByMoney));
	localmemcpy(field.ExchShortMarginRatioByVolume, input->ExchShortMarginRatioByVolume, sizeof(field.ExchShortMarginRatioByVolume));
	localmemcpy(field.NoLongMarginRatioByMoney, input->NoLongMarginRatioByMoney, sizeof(field.NoLongMarginRatioByMoney));
	localmemcpy(field.NoLongMarginRatioByVolume, input->NoLongMarginRatioByVolume, sizeof(field.NoLongMarginRatioByVolume));
	localmemcpy(field.NoShortMarginRatioByMoney, input->NoShortMarginRatioByMoney, sizeof(field.NoShortMarginRatioByMoney));
	localmemcpy(field.NoShortMarginRatioByVolume, input->NoShortMarginRatioByVolume, sizeof(field.NoShortMarginRatioByVolume));
	return field;
}
KingstarAPI::CThostFtdcExchangeMarginRateAdjustField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeMarginRateAdjustField *input)
{
	KingstarAPI::CThostFtdcExchangeMarginRateAdjustField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	localmemcpy(field.ExchLongMarginRatioByMoney, input->ExchLongMarginRatioByMoney, sizeof(field.ExchLongMarginRatioByMoney));
	localmemcpy(field.ExchLongMarginRatioByVolume, input->ExchLongMarginRatioByVolume, sizeof(field.ExchLongMarginRatioByVolume));
	localmemcpy(field.ExchShortMarginRatioByMoney, input->ExchShortMarginRatioByMoney, sizeof(field.ExchShortMarginRatioByMoney));
	localmemcpy(field.ExchShortMarginRatioByVolume, input->ExchShortMarginRatioByVolume, sizeof(field.ExchShortMarginRatioByVolume));
	localmemcpy(field.NoLongMarginRatioByMoney, input->NoLongMarginRatioByMoney, sizeof(field.NoLongMarginRatioByMoney));
	localmemcpy(field.NoLongMarginRatioByVolume, input->NoLongMarginRatioByVolume, sizeof(field.NoLongMarginRatioByVolume));
	localmemcpy(field.NoShortMarginRatioByMoney, input->NoShortMarginRatioByMoney, sizeof(field.NoShortMarginRatioByMoney));
	localmemcpy(field.NoShortMarginRatioByVolume, input->NoShortMarginRatioByVolume, sizeof(field.NoShortMarginRatioByVolume));
	return field;
}
CTPTradeApi::CThostFtdcExchangeRateField KStoCTPChange(KingstarAPI::CThostFtdcExchangeRateField *input)
{
	CTPTradeApi::CThostFtdcExchangeRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.FromCurrencyID, input->FromCurrencyID, sizeof(field.FromCurrencyID));
	localmemcpy(field.FromCurrencyUnit, input->FromCurrencyUnit, sizeof(field.FromCurrencyUnit));
	localmemcpy(field.ToCurrencyID, input->ToCurrencyID, sizeof(field.ToCurrencyID));
	localmemcpy(field.ExchangeRate, input->ExchangeRate, sizeof(field.ExchangeRate));
	return field;
}
KingstarAPI::CThostFtdcExchangeRateField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeRateField *input)
{
	KingstarAPI::CThostFtdcExchangeRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.FromCurrencyID, input->FromCurrencyID, sizeof(field.FromCurrencyID));
	localmemcpy(field.FromCurrencyUnit, input->FromCurrencyUnit, sizeof(field.FromCurrencyUnit));
	localmemcpy(field.ToCurrencyID, input->ToCurrencyID, sizeof(field.ToCurrencyID));
	localmemcpy(field.ExchangeRate, input->ExchangeRate, sizeof(field.ExchangeRate));
	return field;
}
CTPTradeApi::CThostFtdcSettlementRefField KStoCTPChange(KingstarAPI::CThostFtdcSettlementRefField *input)
{
	CTPTradeApi::CThostFtdcSettlementRefField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	return field;
}
KingstarAPI::CThostFtdcSettlementRefField CTPtoKSChange(CTPTradeApi::CThostFtdcSettlementRefField *input)
{
	KingstarAPI::CThostFtdcSettlementRefField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	return field;
}
CTPTradeApi::CThostFtdcCurrentTimeField KStoCTPChange(KingstarAPI::CThostFtdcCurrentTimeField *input)
{
	CTPTradeApi::CThostFtdcCurrentTimeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CurrDate, input->CurrDate, sizeof(field.CurrDate));
	localmemcpy(field.CurrTime, input->CurrTime, sizeof(field.CurrTime));
	localmemcpy(field.CurrMillisec, input->CurrMillisec, sizeof(field.CurrMillisec));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	return field;
}
KingstarAPI::CThostFtdcCurrentTimeField CTPtoKSChange(CTPTradeApi::CThostFtdcCurrentTimeField *input)
{
	KingstarAPI::CThostFtdcCurrentTimeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CurrDate, input->CurrDate, sizeof(field.CurrDate));
	localmemcpy(field.CurrTime, input->CurrTime, sizeof(field.CurrTime));
	localmemcpy(field.CurrMillisec, input->CurrMillisec, sizeof(field.CurrMillisec));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	return field;
}
CTPTradeApi::CThostFtdcCommPhaseField KStoCTPChange(KingstarAPI::CThostFtdcCommPhaseField *input)
{
	CTPTradeApi::CThostFtdcCommPhaseField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.CommPhaseNo, input->CommPhaseNo, sizeof(field.CommPhaseNo));
	localmemcpy(field.SystemID, input->SystemID, sizeof(field.SystemID));
	return field;
}
KingstarAPI::CThostFtdcCommPhaseField CTPtoKSChange(CTPTradeApi::CThostFtdcCommPhaseField *input)
{
	KingstarAPI::CThostFtdcCommPhaseField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.CommPhaseNo, input->CommPhaseNo, sizeof(field.CommPhaseNo));
	localmemcpy(field.SystemID, input->SystemID, sizeof(field.SystemID));
	return field;
}
CTPTradeApi::CThostFtdcLoginInfoField KStoCTPChange(KingstarAPI::CThostFtdcLoginInfoField *input)
{
	CTPTradeApi::CThostFtdcLoginInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.LoginDate, input->LoginDate, sizeof(field.LoginDate));
	localmemcpy(field.LoginTime, input->LoginTime, sizeof(field.LoginTime));
	localmemcpy(field.IPAddress, input->IPAddress, sizeof(field.IPAddress));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.InterfaceProductInfo, input->InterfaceProductInfo, sizeof(field.InterfaceProductInfo));
	localmemcpy(field.ProtocolInfo, input->ProtocolInfo, sizeof(field.ProtocolInfo));
	localmemcpy(field.SystemName, input->SystemName, sizeof(field.SystemName));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.MaxOrderRef, input->MaxOrderRef, sizeof(field.MaxOrderRef));
	localmemcpy(field.SHFETime, input->SHFETime, sizeof(field.SHFETime));
	localmemcpy(field.DCETime, input->DCETime, sizeof(field.DCETime));
	localmemcpy(field.CZCETime, input->CZCETime, sizeof(field.CZCETime));
	localmemcpy(field.FFEXTime, input->FFEXTime, sizeof(field.FFEXTime));
	localmemcpy(field.MacAddress, input->MacAddress, sizeof(field.MacAddress));
	localmemcpy(field.OneTimePassword, input->OneTimePassword, sizeof(field.OneTimePassword));
	localmemcpy(field.INETime, input->INETime, sizeof(field.INETime));
	return field;
}
KingstarAPI::CThostFtdcLoginInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcLoginInfoField *input)
{
	KingstarAPI::CThostFtdcLoginInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.LoginDate, input->LoginDate, sizeof(field.LoginDate));
	localmemcpy(field.LoginTime, input->LoginTime, sizeof(field.LoginTime));
	localmemcpy(field.IPAddress, input->IPAddress, sizeof(field.IPAddress));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.InterfaceProductInfo, input->InterfaceProductInfo, sizeof(field.InterfaceProductInfo));
	localmemcpy(field.ProtocolInfo, input->ProtocolInfo, sizeof(field.ProtocolInfo));
	localmemcpy(field.SystemName, input->SystemName, sizeof(field.SystemName));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.MaxOrderRef, input->MaxOrderRef, sizeof(field.MaxOrderRef));
	localmemcpy(field.SHFETime, input->SHFETime, sizeof(field.SHFETime));
	localmemcpy(field.DCETime, input->DCETime, sizeof(field.DCETime));
	localmemcpy(field.CZCETime, input->CZCETime, sizeof(field.CZCETime));
	localmemcpy(field.FFEXTime, input->FFEXTime, sizeof(field.FFEXTime));
	localmemcpy(field.MacAddress, input->MacAddress, sizeof(field.MacAddress));
	localmemcpy(field.OneTimePassword, input->OneTimePassword, sizeof(field.OneTimePassword));
	localmemcpy(field.INETime, input->INETime, sizeof(field.INETime));
	return field;
}
CTPTradeApi::CThostFtdcLogoutAllField KStoCTPChange(KingstarAPI::CThostFtdcLogoutAllField *input)
{
	CTPTradeApi::CThostFtdcLogoutAllField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.SystemName, input->SystemName, sizeof(field.SystemName));
	return field;
}
KingstarAPI::CThostFtdcLogoutAllField CTPtoKSChange(CTPTradeApi::CThostFtdcLogoutAllField *input)
{
	KingstarAPI::CThostFtdcLogoutAllField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.SystemName, input->SystemName, sizeof(field.SystemName));
	return field;
}
CTPTradeApi::CThostFtdcFrontStatusField KStoCTPChange(KingstarAPI::CThostFtdcFrontStatusField *input)
{
	CTPTradeApi::CThostFtdcFrontStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.LastReportDate, input->LastReportDate, sizeof(field.LastReportDate));
	localmemcpy(field.LastReportTime, input->LastReportTime, sizeof(field.LastReportTime));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
KingstarAPI::CThostFtdcFrontStatusField CTPtoKSChange(CTPTradeApi::CThostFtdcFrontStatusField *input)
{
	KingstarAPI::CThostFtdcFrontStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.LastReportDate, input->LastReportDate, sizeof(field.LastReportDate));
	localmemcpy(field.LastReportTime, input->LastReportTime, sizeof(field.LastReportTime));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
CTPTradeApi::CThostFtdcUserPasswordUpdateField KStoCTPChange(KingstarAPI::CThostFtdcUserPasswordUpdateField *input)
{
	CTPTradeApi::CThostFtdcUserPasswordUpdateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OldPassword, input->OldPassword, sizeof(field.OldPassword));
	localmemcpy(field.NewPassword, input->NewPassword, sizeof(field.NewPassword));
	return field;
}
KingstarAPI::CThostFtdcUserPasswordUpdateField CTPtoKSChange(CTPTradeApi::CThostFtdcUserPasswordUpdateField *input)
{
	KingstarAPI::CThostFtdcUserPasswordUpdateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OldPassword, input->OldPassword, sizeof(field.OldPassword));
	localmemcpy(field.NewPassword, input->NewPassword, sizeof(field.NewPassword));
	return field;
}
CTPTradeApi::CThostFtdcInputOrderField KStoCTPChange(KingstarAPI::CThostFtdcInputOrderField *input)
{
	CTPTradeApi::CThostFtdcInputOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
KingstarAPI::CThostFtdcInputOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcInputOrderField *input)
{
	KingstarAPI::CThostFtdcInputOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
CTPTradeApi::CThostFtdcOrderField KStoCTPChange(KingstarAPI::CThostFtdcOrderField *input)
{
	CTPTradeApi::CThostFtdcOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.OrderSource, input->OrderSource, sizeof(field.OrderSource));
	localmemcpy(field.OrderStatus, input->OrderStatus, sizeof(field.OrderStatus));
	localmemcpy(field.OrderType, input->OrderType, sizeof(field.OrderType));
	localmemcpy(field.VolumeTraded, input->VolumeTraded, sizeof(field.VolumeTraded));
	localmemcpy(field.VolumeTotal, input->VolumeTotal, sizeof(field.VolumeTotal));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ActiveTime, input->ActiveTime, sizeof(field.ActiveTime));
	localmemcpy(field.SuspendTime, input->SuspendTime, sizeof(field.SuspendTime));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ActiveTraderID, input->ActiveTraderID, sizeof(field.ActiveTraderID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerOrderSeq, input->BrokerOrderSeq, sizeof(field.BrokerOrderSeq));
	localmemcpy(field.RelativeOrderSysID, input->RelativeOrderSysID, sizeof(field.RelativeOrderSysID));
	localmemcpy(field.ZCETotalTradedVolume, input->ZCETotalTradedVolume, sizeof(field.ZCETotalTradedVolume));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
KingstarAPI::CThostFtdcOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcOrderField *input)
{
	KingstarAPI::CThostFtdcOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.OrderSource, input->OrderSource, sizeof(field.OrderSource));
	localmemcpy(field.OrderStatus, input->OrderStatus, sizeof(field.OrderStatus));
	localmemcpy(field.OrderType, input->OrderType, sizeof(field.OrderType));
	localmemcpy(field.VolumeTraded, input->VolumeTraded, sizeof(field.VolumeTraded));
	localmemcpy(field.VolumeTotal, input->VolumeTotal, sizeof(field.VolumeTotal));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ActiveTime, input->ActiveTime, sizeof(field.ActiveTime));
	localmemcpy(field.SuspendTime, input->SuspendTime, sizeof(field.SuspendTime));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ActiveTraderID, input->ActiveTraderID, sizeof(field.ActiveTraderID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerOrderSeq, input->BrokerOrderSeq, sizeof(field.BrokerOrderSeq));
	localmemcpy(field.RelativeOrderSysID, input->RelativeOrderSysID, sizeof(field.RelativeOrderSysID));
	localmemcpy(field.ZCETotalTradedVolume, input->ZCETotalTradedVolume, sizeof(field.ZCETotalTradedVolume));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
CTPTradeApi::CThostFtdcExchangeOrderField KStoCTPChange(KingstarAPI::CThostFtdcExchangeOrderField *input)
{
	CTPTradeApi::CThostFtdcExchangeOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.OrderSource, input->OrderSource, sizeof(field.OrderSource));
	localmemcpy(field.OrderStatus, input->OrderStatus, sizeof(field.OrderStatus));
	localmemcpy(field.OrderType, input->OrderType, sizeof(field.OrderType));
	localmemcpy(field.VolumeTraded, input->VolumeTraded, sizeof(field.VolumeTraded));
	localmemcpy(field.VolumeTotal, input->VolumeTotal, sizeof(field.VolumeTotal));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ActiveTime, input->ActiveTime, sizeof(field.ActiveTime));
	localmemcpy(field.SuspendTime, input->SuspendTime, sizeof(field.SuspendTime));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ActiveTraderID, input->ActiveTraderID, sizeof(field.ActiveTraderID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	return field;
}
KingstarAPI::CThostFtdcExchangeOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeOrderField *input)
{
	KingstarAPI::CThostFtdcExchangeOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.OrderSource, input->OrderSource, sizeof(field.OrderSource));
	localmemcpy(field.OrderStatus, input->OrderStatus, sizeof(field.OrderStatus));
	localmemcpy(field.OrderType, input->OrderType, sizeof(field.OrderType));
	localmemcpy(field.VolumeTraded, input->VolumeTraded, sizeof(field.VolumeTraded));
	localmemcpy(field.VolumeTotal, input->VolumeTotal, sizeof(field.VolumeTotal));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ActiveTime, input->ActiveTime, sizeof(field.ActiveTime));
	localmemcpy(field.SuspendTime, input->SuspendTime, sizeof(field.SuspendTime));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ActiveTraderID, input->ActiveTraderID, sizeof(field.ActiveTraderID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	return field;
}
CTPTradeApi::CThostFtdcExchangeOrderInsertErrorField KStoCTPChange(KingstarAPI::CThostFtdcExchangeOrderInsertErrorField *input)
{
	CTPTradeApi::CThostFtdcExchangeOrderInsertErrorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcExchangeOrderInsertErrorField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeOrderInsertErrorField *input)
{
	KingstarAPI::CThostFtdcExchangeOrderInsertErrorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcInputOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcInputOrderActionField *input)
{
	CTPTradeApi::CThostFtdcInputOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OrderActionRef, input->OrderActionRef, sizeof(field.OrderActionRef));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcInputOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcInputOrderActionField *input)
{
	KingstarAPI::CThostFtdcInputOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OrderActionRef, input->OrderActionRef, sizeof(field.OrderActionRef));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcOrderActionField *input)
{
	CTPTradeApi::CThostFtdcOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OrderActionRef, input->OrderActionRef, sizeof(field.OrderActionRef));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcOrderActionField *input)
{
	KingstarAPI::CThostFtdcOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OrderActionRef, input->OrderActionRef, sizeof(field.OrderActionRef));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcExchangeOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcExchangeOrderActionField *input)
{
	CTPTradeApi::CThostFtdcExchangeOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcExchangeOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeOrderActionField *input)
{
	KingstarAPI::CThostFtdcExchangeOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcExchangeOrderActionErrorField KStoCTPChange(KingstarAPI::CThostFtdcExchangeOrderActionErrorField *input)
{
	CTPTradeApi::CThostFtdcExchangeOrderActionErrorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcExchangeOrderActionErrorField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeOrderActionErrorField *input)
{
	KingstarAPI::CThostFtdcExchangeOrderActionErrorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcExchangeTradeField KStoCTPChange(KingstarAPI::CThostFtdcExchangeTradeField *input)
{
	CTPTradeApi::CThostFtdcExchangeTradeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.TradingRole, input->TradingRole, sizeof(field.TradingRole));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Price, input->Price, sizeof(field.Price));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeType, input->TradeType, sizeof(field.TradeType));
	localmemcpy(field.PriceSource, input->PriceSource, sizeof(field.PriceSource));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.TradeSource, input->TradeSource, sizeof(field.TradeSource));
	return field;
}
KingstarAPI::CThostFtdcExchangeTradeField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeTradeField *input)
{
	KingstarAPI::CThostFtdcExchangeTradeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.TradingRole, input->TradingRole, sizeof(field.TradingRole));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Price, input->Price, sizeof(field.Price));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeType, input->TradeType, sizeof(field.TradeType));
	localmemcpy(field.PriceSource, input->PriceSource, sizeof(field.PriceSource));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.TradeSource, input->TradeSource, sizeof(field.TradeSource));
	return field;
}
CTPTradeApi::CThostFtdcTradeField KStoCTPChange(KingstarAPI::CThostFtdcTradeField *input)
{
	CTPTradeApi::CThostFtdcTradeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.TradingRole, input->TradingRole, sizeof(field.TradingRole));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Price, input->Price, sizeof(field.Price));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeType, input->TradeType, sizeof(field.TradeType));
	localmemcpy(field.PriceSource, input->PriceSource, sizeof(field.PriceSource));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.BrokerOrderSeq, input->BrokerOrderSeq, sizeof(field.BrokerOrderSeq));
	localmemcpy(field.TradeSource, input->TradeSource, sizeof(field.TradeSource));
	return field;
}
KingstarAPI::CThostFtdcTradeField CTPtoKSChange(CTPTradeApi::CThostFtdcTradeField *input)
{
	KingstarAPI::CThostFtdcTradeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.TradingRole, input->TradingRole, sizeof(field.TradingRole));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Price, input->Price, sizeof(field.Price));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeType, input->TradeType, sizeof(field.TradeType));
	localmemcpy(field.PriceSource, input->PriceSource, sizeof(field.PriceSource));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.BrokerOrderSeq, input->BrokerOrderSeq, sizeof(field.BrokerOrderSeq));
	localmemcpy(field.TradeSource, input->TradeSource, sizeof(field.TradeSource));
	return field;
}
CTPTradeApi::CThostFtdcUserSessionField KStoCTPChange(KingstarAPI::CThostFtdcUserSessionField *input)
{
	CTPTradeApi::CThostFtdcUserSessionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.LoginDate, input->LoginDate, sizeof(field.LoginDate));
	localmemcpy(field.LoginTime, input->LoginTime, sizeof(field.LoginTime));
	localmemcpy(field.IPAddress, input->IPAddress, sizeof(field.IPAddress));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.InterfaceProductInfo, input->InterfaceProductInfo, sizeof(field.InterfaceProductInfo));
	localmemcpy(field.ProtocolInfo, input->ProtocolInfo, sizeof(field.ProtocolInfo));
	localmemcpy(field.MacAddress, input->MacAddress, sizeof(field.MacAddress));
	return field;
}
KingstarAPI::CThostFtdcUserSessionField CTPtoKSChange(CTPTradeApi::CThostFtdcUserSessionField *input)
{
	KingstarAPI::CThostFtdcUserSessionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.LoginDate, input->LoginDate, sizeof(field.LoginDate));
	localmemcpy(field.LoginTime, input->LoginTime, sizeof(field.LoginTime));
	localmemcpy(field.IPAddress, input->IPAddress, sizeof(field.IPAddress));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.InterfaceProductInfo, input->InterfaceProductInfo, sizeof(field.InterfaceProductInfo));
	localmemcpy(field.ProtocolInfo, input->ProtocolInfo, sizeof(field.ProtocolInfo));
	localmemcpy(field.MacAddress, input->MacAddress, sizeof(field.MacAddress));
	return field;
}
CTPTradeApi::CThostFtdcQueryMaxOrderVolumeField KStoCTPChange(KingstarAPI::CThostFtdcQueryMaxOrderVolumeField *input)
{
	CTPTradeApi::CThostFtdcQueryMaxOrderVolumeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.MaxVolume, input->MaxVolume, sizeof(field.MaxVolume));
	return field;
}
KingstarAPI::CThostFtdcQueryMaxOrderVolumeField CTPtoKSChange(CTPTradeApi::CThostFtdcQueryMaxOrderVolumeField *input)
{
	KingstarAPI::CThostFtdcQueryMaxOrderVolumeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.MaxVolume, input->MaxVolume, sizeof(field.MaxVolume));
	return field;
}
CTPTradeApi::CThostFtdcSettlementInfoConfirmField KStoCTPChange(KingstarAPI::CThostFtdcSettlementInfoConfirmField *input)
{
	CTPTradeApi::CThostFtdcSettlementInfoConfirmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ConfirmDate, input->ConfirmDate, sizeof(field.ConfirmDate));
	localmemcpy(field.ConfirmTime, input->ConfirmTime, sizeof(field.ConfirmTime));
	return field;
}
KingstarAPI::CThostFtdcSettlementInfoConfirmField CTPtoKSChange(CTPTradeApi::CThostFtdcSettlementInfoConfirmField *input)
{
	KingstarAPI::CThostFtdcSettlementInfoConfirmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ConfirmDate, input->ConfirmDate, sizeof(field.ConfirmDate));
	localmemcpy(field.ConfirmTime, input->ConfirmTime, sizeof(field.ConfirmTime));
	return field;
}
CTPTradeApi::CThostFtdcSyncDepositField KStoCTPChange(KingstarAPI::CThostFtdcSyncDepositField *input)
{
	CTPTradeApi::CThostFtdcSyncDepositField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.DepositSeqNo, input->DepositSeqNo, sizeof(field.DepositSeqNo));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.IsForce, input->IsForce, sizeof(field.IsForce));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcSyncDepositField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncDepositField *input)
{
	KingstarAPI::CThostFtdcSyncDepositField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.DepositSeqNo, input->DepositSeqNo, sizeof(field.DepositSeqNo));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.IsForce, input->IsForce, sizeof(field.IsForce));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcSyncFundMortgageField KStoCTPChange(KingstarAPI::CThostFtdcSyncFundMortgageField *input)
{
	CTPTradeApi::CThostFtdcSyncFundMortgageField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.MortgageSeqNo, input->MortgageSeqNo, sizeof(field.MortgageSeqNo));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.FromCurrencyID, input->FromCurrencyID, sizeof(field.FromCurrencyID));
	localmemcpy(field.MortgageAmount, input->MortgageAmount, sizeof(field.MortgageAmount));
	localmemcpy(field.ToCurrencyID, input->ToCurrencyID, sizeof(field.ToCurrencyID));
	return field;
}
KingstarAPI::CThostFtdcSyncFundMortgageField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncFundMortgageField *input)
{
	KingstarAPI::CThostFtdcSyncFundMortgageField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.MortgageSeqNo, input->MortgageSeqNo, sizeof(field.MortgageSeqNo));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.FromCurrencyID, input->FromCurrencyID, sizeof(field.FromCurrencyID));
	localmemcpy(field.MortgageAmount, input->MortgageAmount, sizeof(field.MortgageAmount));
	localmemcpy(field.ToCurrencyID, input->ToCurrencyID, sizeof(field.ToCurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcBrokerSyncField KStoCTPChange(KingstarAPI::CThostFtdcBrokerSyncField *input)
{
	CTPTradeApi::CThostFtdcBrokerSyncField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
KingstarAPI::CThostFtdcBrokerSyncField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerSyncField *input)
{
	KingstarAPI::CThostFtdcBrokerSyncField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
CTPTradeApi::CThostFtdcSyncingInvestorField KStoCTPChange(KingstarAPI::CThostFtdcSyncingInvestorField *input)
{
	CTPTradeApi::CThostFtdcSyncingInvestorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorGroupID, input->InvestorGroupID, sizeof(field.InvestorGroupID));
	localmemcpy(field.InvestorName, input->InvestorName, sizeof(field.InvestorName));
	localmemcpy(field.IdentifiedCardType, input->IdentifiedCardType, sizeof(field.IdentifiedCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.Mobile, input->Mobile, sizeof(field.Mobile));
	localmemcpy(field.CommModelID, input->CommModelID, sizeof(field.CommModelID));
	localmemcpy(field.MarginModelID, input->MarginModelID, sizeof(field.MarginModelID));
	return field;
}
KingstarAPI::CThostFtdcSyncingInvestorField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncingInvestorField *input)
{
	KingstarAPI::CThostFtdcSyncingInvestorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorGroupID, input->InvestorGroupID, sizeof(field.InvestorGroupID));
	localmemcpy(field.InvestorName, input->InvestorName, sizeof(field.InvestorName));
	localmemcpy(field.IdentifiedCardType, input->IdentifiedCardType, sizeof(field.IdentifiedCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.Mobile, input->Mobile, sizeof(field.Mobile));
	localmemcpy(field.CommModelID, input->CommModelID, sizeof(field.CommModelID));
	localmemcpy(field.MarginModelID, input->MarginModelID, sizeof(field.MarginModelID));
	return field;
}
CTPTradeApi::CThostFtdcSyncingTradingCodeField KStoCTPChange(KingstarAPI::CThostFtdcSyncingTradingCodeField *input)
{
	CTPTradeApi::CThostFtdcSyncingTradingCodeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.ClientIDType, input->ClientIDType, sizeof(field.ClientIDType));
	return field;
}
KingstarAPI::CThostFtdcSyncingTradingCodeField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncingTradingCodeField *input)
{
	KingstarAPI::CThostFtdcSyncingTradingCodeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	localmemcpy(field.ClientIDType, input->ClientIDType, sizeof(field.ClientIDType));
	return field;
}
CTPTradeApi::CThostFtdcSyncingInvestorGroupField KStoCTPChange(KingstarAPI::CThostFtdcSyncingInvestorGroupField *input)
{
	CTPTradeApi::CThostFtdcSyncingInvestorGroupField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorGroupID, input->InvestorGroupID, sizeof(field.InvestorGroupID));
	localmemcpy(field.InvestorGroupName, input->InvestorGroupName, sizeof(field.InvestorGroupName));
	return field;
}
KingstarAPI::CThostFtdcSyncingInvestorGroupField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncingInvestorGroupField *input)
{
	KingstarAPI::CThostFtdcSyncingInvestorGroupField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorGroupID, input->InvestorGroupID, sizeof(field.InvestorGroupID));
	localmemcpy(field.InvestorGroupName, input->InvestorGroupName, sizeof(field.InvestorGroupName));
	return field;
}
CTPTradeApi::CThostFtdcSyncingTradingAccountField KStoCTPChange(KingstarAPI::CThostFtdcSyncingTradingAccountField *input)
{
	CTPTradeApi::CThostFtdcSyncingTradingAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.PreMortgage, input->PreMortgage, sizeof(field.PreMortgage));
	localmemcpy(field.PreCredit, input->PreCredit, sizeof(field.PreCredit));
	localmemcpy(field.PreDeposit, input->PreDeposit, sizeof(field.PreDeposit));
	localmemcpy(field.PreBalance, input->PreBalance, sizeof(field.PreBalance));
	localmemcpy(field.PreMargin, input->PreMargin, sizeof(field.PreMargin));
	localmemcpy(field.InterestBase, input->InterestBase, sizeof(field.InterestBase));
	localmemcpy(field.Interest, input->Interest, sizeof(field.Interest));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.Withdraw, input->Withdraw, sizeof(field.Withdraw));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.CurrMargin, input->CurrMargin, sizeof(field.CurrMargin));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.Balance, input->Balance, sizeof(field.Balance));
	localmemcpy(field.Available, input->Available, sizeof(field.Available));
	localmemcpy(field.WithdrawQuota, input->WithdrawQuota, sizeof(field.WithdrawQuota));
	localmemcpy(field.Reserve, input->Reserve, sizeof(field.Reserve));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.Credit, input->Credit, sizeof(field.Credit));
	localmemcpy(field.Mortgage, input->Mortgage, sizeof(field.Mortgage));
	localmemcpy(field.ExchangeMargin, input->ExchangeMargin, sizeof(field.ExchangeMargin));
	localmemcpy(field.DeliveryMargin, input->DeliveryMargin, sizeof(field.DeliveryMargin));
	localmemcpy(field.ExchangeDeliveryMargin, input->ExchangeDeliveryMargin, sizeof(field.ExchangeDeliveryMargin));
	localmemcpy(field.ReserveBalance, input->ReserveBalance, sizeof(field.ReserveBalance));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.PreFundMortgageIn, input->PreFundMortgageIn, sizeof(field.PreFundMortgageIn));
	localmemcpy(field.PreFundMortgageOut, input->PreFundMortgageOut, sizeof(field.PreFundMortgageOut));
	localmemcpy(field.FundMortgageIn, input->FundMortgageIn, sizeof(field.FundMortgageIn));
	localmemcpy(field.FundMortgageOut, input->FundMortgageOut, sizeof(field.FundMortgageOut));
	localmemcpy(field.FundMortgageAvailable, input->FundMortgageAvailable, sizeof(field.FundMortgageAvailable));
	localmemcpy(field.MortgageableFund, input->MortgageableFund, sizeof(field.MortgageableFund));
	localmemcpy(field.SpecProductMargin, input->SpecProductMargin, sizeof(field.SpecProductMargin));
	localmemcpy(field.SpecProductFrozenMargin, input->SpecProductFrozenMargin, sizeof(field.SpecProductFrozenMargin));
	localmemcpy(field.SpecProductCommission, input->SpecProductCommission, sizeof(field.SpecProductCommission));
	localmemcpy(field.SpecProductFrozenCommission, input->SpecProductFrozenCommission, sizeof(field.SpecProductFrozenCommission));
	localmemcpy(field.SpecProductPositionProfit, input->SpecProductPositionProfit, sizeof(field.SpecProductPositionProfit));
	localmemcpy(field.SpecProductCloseProfit, input->SpecProductCloseProfit, sizeof(field.SpecProductCloseProfit));
	localmemcpy(field.SpecProductPositionProfitByAlg, input->SpecProductPositionProfitByAlg, sizeof(field.SpecProductPositionProfitByAlg));
	localmemcpy(field.SpecProductExchangeMargin, input->SpecProductExchangeMargin, sizeof(field.SpecProductExchangeMargin));
	return field;
}
KingstarAPI::CThostFtdcSyncingTradingAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncingTradingAccountField *input)
{
	KingstarAPI::CThostFtdcSyncingTradingAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.PreMortgage, input->PreMortgage, sizeof(field.PreMortgage));
	localmemcpy(field.PreCredit, input->PreCredit, sizeof(field.PreCredit));
	localmemcpy(field.PreDeposit, input->PreDeposit, sizeof(field.PreDeposit));
	localmemcpy(field.PreBalance, input->PreBalance, sizeof(field.PreBalance));
	localmemcpy(field.PreMargin, input->PreMargin, sizeof(field.PreMargin));
	localmemcpy(field.InterestBase, input->InterestBase, sizeof(field.InterestBase));
	localmemcpy(field.Interest, input->Interest, sizeof(field.Interest));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.Withdraw, input->Withdraw, sizeof(field.Withdraw));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.CurrMargin, input->CurrMargin, sizeof(field.CurrMargin));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.Balance, input->Balance, sizeof(field.Balance));
	localmemcpy(field.Available, input->Available, sizeof(field.Available));
	localmemcpy(field.WithdrawQuota, input->WithdrawQuota, sizeof(field.WithdrawQuota));
	localmemcpy(field.Reserve, input->Reserve, sizeof(field.Reserve));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.Credit, input->Credit, sizeof(field.Credit));
	localmemcpy(field.Mortgage, input->Mortgage, sizeof(field.Mortgage));
	localmemcpy(field.ExchangeMargin, input->ExchangeMargin, sizeof(field.ExchangeMargin));
	localmemcpy(field.DeliveryMargin, input->DeliveryMargin, sizeof(field.DeliveryMargin));
	localmemcpy(field.ExchangeDeliveryMargin, input->ExchangeDeliveryMargin, sizeof(field.ExchangeDeliveryMargin));
	localmemcpy(field.ReserveBalance, input->ReserveBalance, sizeof(field.ReserveBalance));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.PreFundMortgageIn, input->PreFundMortgageIn, sizeof(field.PreFundMortgageIn));
	localmemcpy(field.PreFundMortgageOut, input->PreFundMortgageOut, sizeof(field.PreFundMortgageOut));
	localmemcpy(field.FundMortgageIn, input->FundMortgageIn, sizeof(field.FundMortgageIn));
	localmemcpy(field.FundMortgageOut, input->FundMortgageOut, sizeof(field.FundMortgageOut));
	localmemcpy(field.FundMortgageAvailable, input->FundMortgageAvailable, sizeof(field.FundMortgageAvailable));
	localmemcpy(field.MortgageableFund, input->MortgageableFund, sizeof(field.MortgageableFund));
	localmemcpy(field.SpecProductMargin, input->SpecProductMargin, sizeof(field.SpecProductMargin));
	localmemcpy(field.SpecProductFrozenMargin, input->SpecProductFrozenMargin, sizeof(field.SpecProductFrozenMargin));
	localmemcpy(field.SpecProductCommission, input->SpecProductCommission, sizeof(field.SpecProductCommission));
	localmemcpy(field.SpecProductFrozenCommission, input->SpecProductFrozenCommission, sizeof(field.SpecProductFrozenCommission));
	localmemcpy(field.SpecProductPositionProfit, input->SpecProductPositionProfit, sizeof(field.SpecProductPositionProfit));
	localmemcpy(field.SpecProductCloseProfit, input->SpecProductCloseProfit, sizeof(field.SpecProductCloseProfit));
	localmemcpy(field.SpecProductPositionProfitByAlg, input->SpecProductPositionProfitByAlg, sizeof(field.SpecProductPositionProfitByAlg));
	localmemcpy(field.SpecProductExchangeMargin, input->SpecProductExchangeMargin, sizeof(field.SpecProductExchangeMargin));
	return field;
}
CTPTradeApi::CThostFtdcSyncingInvestorPositionField KStoCTPChange(KingstarAPI::CThostFtdcSyncingInvestorPositionField *input)
{
	CTPTradeApi::CThostFtdcSyncingInvestorPositionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.PositionDate, input->PositionDate, sizeof(field.PositionDate));
	localmemcpy(field.YdPosition, input->YdPosition, sizeof(field.YdPosition));
	localmemcpy(field.Position, input->Position, sizeof(field.Position));
	localmemcpy(field.LongFrozen, input->LongFrozen, sizeof(field.LongFrozen));
	localmemcpy(field.ShortFrozen, input->ShortFrozen, sizeof(field.ShortFrozen));
	localmemcpy(field.LongFrozenAmount, input->LongFrozenAmount, sizeof(field.LongFrozenAmount));
	localmemcpy(field.ShortFrozenAmount, input->ShortFrozenAmount, sizeof(field.ShortFrozenAmount));
	localmemcpy(field.OpenVolume, input->OpenVolume, sizeof(field.OpenVolume));
	localmemcpy(field.CloseVolume, input->CloseVolume, sizeof(field.CloseVolume));
	localmemcpy(field.OpenAmount, input->OpenAmount, sizeof(field.OpenAmount));
	localmemcpy(field.CloseAmount, input->CloseAmount, sizeof(field.CloseAmount));
	localmemcpy(field.PositionCost, input->PositionCost, sizeof(field.PositionCost));
	localmemcpy(field.PreMargin, input->PreMargin, sizeof(field.PreMargin));
	localmemcpy(field.UseMargin, input->UseMargin, sizeof(field.UseMargin));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OpenCost, input->OpenCost, sizeof(field.OpenCost));
	localmemcpy(field.ExchangeMargin, input->ExchangeMargin, sizeof(field.ExchangeMargin));
	localmemcpy(field.CombPosition, input->CombPosition, sizeof(field.CombPosition));
	localmemcpy(field.CombLongFrozen, input->CombLongFrozen, sizeof(field.CombLongFrozen));
	localmemcpy(field.CombShortFrozen, input->CombShortFrozen, sizeof(field.CombShortFrozen));
	localmemcpy(field.CloseProfitByDate, input->CloseProfitByDate, sizeof(field.CloseProfitByDate));
	localmemcpy(field.CloseProfitByTrade, input->CloseProfitByTrade, sizeof(field.CloseProfitByTrade));
	localmemcpy(field.TodayPosition, input->TodayPosition, sizeof(field.TodayPosition));
	localmemcpy(field.MarginRateByMoney, input->MarginRateByMoney, sizeof(field.MarginRateByMoney));
	localmemcpy(field.MarginRateByVolume, input->MarginRateByVolume, sizeof(field.MarginRateByVolume));
	localmemcpy(field.StrikeFrozen, input->StrikeFrozen, sizeof(field.StrikeFrozen));
	localmemcpy(field.StrikeFrozenAmount, input->StrikeFrozenAmount, sizeof(field.StrikeFrozenAmount));
	localmemcpy(field.AbandonFrozen, input->AbandonFrozen, sizeof(field.AbandonFrozen));
	return field;
}
KingstarAPI::CThostFtdcSyncingInvestorPositionField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncingInvestorPositionField *input)
{
	KingstarAPI::CThostFtdcSyncingInvestorPositionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.PositionDate, input->PositionDate, sizeof(field.PositionDate));
	localmemcpy(field.YdPosition, input->YdPosition, sizeof(field.YdPosition));
	localmemcpy(field.Position, input->Position, sizeof(field.Position));
	localmemcpy(field.LongFrozen, input->LongFrozen, sizeof(field.LongFrozen));
	localmemcpy(field.ShortFrozen, input->ShortFrozen, sizeof(field.ShortFrozen));
	localmemcpy(field.LongFrozenAmount, input->LongFrozenAmount, sizeof(field.LongFrozenAmount));
	localmemcpy(field.ShortFrozenAmount, input->ShortFrozenAmount, sizeof(field.ShortFrozenAmount));
	localmemcpy(field.OpenVolume, input->OpenVolume, sizeof(field.OpenVolume));
	localmemcpy(field.CloseVolume, input->CloseVolume, sizeof(field.CloseVolume));
	localmemcpy(field.OpenAmount, input->OpenAmount, sizeof(field.OpenAmount));
	localmemcpy(field.CloseAmount, input->CloseAmount, sizeof(field.CloseAmount));
	localmemcpy(field.PositionCost, input->PositionCost, sizeof(field.PositionCost));
	localmemcpy(field.PreMargin, input->PreMargin, sizeof(field.PreMargin));
	localmemcpy(field.UseMargin, input->UseMargin, sizeof(field.UseMargin));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OpenCost, input->OpenCost, sizeof(field.OpenCost));
	localmemcpy(field.ExchangeMargin, input->ExchangeMargin, sizeof(field.ExchangeMargin));
	localmemcpy(field.CombPosition, input->CombPosition, sizeof(field.CombPosition));
	localmemcpy(field.CombLongFrozen, input->CombLongFrozen, sizeof(field.CombLongFrozen));
	localmemcpy(field.CombShortFrozen, input->CombShortFrozen, sizeof(field.CombShortFrozen));
	localmemcpy(field.CloseProfitByDate, input->CloseProfitByDate, sizeof(field.CloseProfitByDate));
	localmemcpy(field.CloseProfitByTrade, input->CloseProfitByTrade, sizeof(field.CloseProfitByTrade));
	localmemcpy(field.TodayPosition, input->TodayPosition, sizeof(field.TodayPosition));
	localmemcpy(field.MarginRateByMoney, input->MarginRateByMoney, sizeof(field.MarginRateByMoney));
	localmemcpy(field.MarginRateByVolume, input->MarginRateByVolume, sizeof(field.MarginRateByVolume));
	localmemcpy(field.StrikeFrozen, input->StrikeFrozen, sizeof(field.StrikeFrozen));
	localmemcpy(field.StrikeFrozenAmount, input->StrikeFrozenAmount, sizeof(field.StrikeFrozenAmount));
	localmemcpy(field.AbandonFrozen, input->AbandonFrozen, sizeof(field.AbandonFrozen));
	return field;
}
CTPTradeApi::CThostFtdcSyncingInstrumentMarginRateField KStoCTPChange(KingstarAPI::CThostFtdcSyncingInstrumentMarginRateField *input)
{
	CTPTradeApi::CThostFtdcSyncingInstrumentMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
KingstarAPI::CThostFtdcSyncingInstrumentMarginRateField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncingInstrumentMarginRateField *input)
{
	KingstarAPI::CThostFtdcSyncingInstrumentMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.LongMarginRatioByMoney, input->LongMarginRatioByMoney, sizeof(field.LongMarginRatioByMoney));
	localmemcpy(field.LongMarginRatioByVolume, input->LongMarginRatioByVolume, sizeof(field.LongMarginRatioByVolume));
	localmemcpy(field.ShortMarginRatioByMoney, input->ShortMarginRatioByMoney, sizeof(field.ShortMarginRatioByMoney));
	localmemcpy(field.ShortMarginRatioByVolume, input->ShortMarginRatioByVolume, sizeof(field.ShortMarginRatioByVolume));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
CTPTradeApi::CThostFtdcSyncingInstrumentCommissionRateField KStoCTPChange(KingstarAPI::CThostFtdcSyncingInstrumentCommissionRateField *input)
{
	CTPTradeApi::CThostFtdcSyncingInstrumentCommissionRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OpenRatioByMoney, input->OpenRatioByMoney, sizeof(field.OpenRatioByMoney));
	localmemcpy(field.OpenRatioByVolume, input->OpenRatioByVolume, sizeof(field.OpenRatioByVolume));
	localmemcpy(field.CloseRatioByMoney, input->CloseRatioByMoney, sizeof(field.CloseRatioByMoney));
	localmemcpy(field.CloseRatioByVolume, input->CloseRatioByVolume, sizeof(field.CloseRatioByVolume));
	localmemcpy(field.CloseTodayRatioByMoney, input->CloseTodayRatioByMoney, sizeof(field.CloseTodayRatioByMoney));
	localmemcpy(field.CloseTodayRatioByVolume, input->CloseTodayRatioByVolume, sizeof(field.CloseTodayRatioByVolume));
	return field;
}
KingstarAPI::CThostFtdcSyncingInstrumentCommissionRateField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncingInstrumentCommissionRateField *input)
{
	KingstarAPI::CThostFtdcSyncingInstrumentCommissionRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OpenRatioByMoney, input->OpenRatioByMoney, sizeof(field.OpenRatioByMoney));
	localmemcpy(field.OpenRatioByVolume, input->OpenRatioByVolume, sizeof(field.OpenRatioByVolume));
	localmemcpy(field.CloseRatioByMoney, input->CloseRatioByMoney, sizeof(field.CloseRatioByMoney));
	localmemcpy(field.CloseRatioByVolume, input->CloseRatioByVolume, sizeof(field.CloseRatioByVolume));
	localmemcpy(field.CloseTodayRatioByMoney, input->CloseTodayRatioByMoney, sizeof(field.CloseTodayRatioByMoney));
	localmemcpy(field.CloseTodayRatioByVolume, input->CloseTodayRatioByVolume, sizeof(field.CloseTodayRatioByVolume));
	return field;
}
CTPTradeApi::CThostFtdcSyncingInstrumentTradingRightField KStoCTPChange(KingstarAPI::CThostFtdcSyncingInstrumentTradingRightField *input)
{
	CTPTradeApi::CThostFtdcSyncingInstrumentTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.TradingRight, input->TradingRight, sizeof(field.TradingRight));
	return field;
}
KingstarAPI::CThostFtdcSyncingInstrumentTradingRightField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncingInstrumentTradingRightField *input)
{
	KingstarAPI::CThostFtdcSyncingInstrumentTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.TradingRight, input->TradingRight, sizeof(field.TradingRight));
	return field;
}
CTPTradeApi::CThostFtdcQryOrderField KStoCTPChange(KingstarAPI::CThostFtdcQryOrderField *input)
{
	CTPTradeApi::CThostFtdcQryOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	return field;
}
KingstarAPI::CThostFtdcQryOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryOrderField *input)
{
	KingstarAPI::CThostFtdcQryOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	return field;
}
CTPTradeApi::CThostFtdcQryTradeField KStoCTPChange(KingstarAPI::CThostFtdcQryTradeField *input)
{
	CTPTradeApi::CThostFtdcQryTradeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.TradeTimeStart, input->TradeTimeStart, sizeof(field.TradeTimeStart));
	localmemcpy(field.TradeTimeEnd, input->TradeTimeEnd, sizeof(field.TradeTimeEnd));
	return field;
}
KingstarAPI::CThostFtdcQryTradeField CTPtoKSChange(CTPTradeApi::CThostFtdcQryTradeField *input)
{
	KingstarAPI::CThostFtdcQryTradeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.TradeTimeStart, input->TradeTimeStart, sizeof(field.TradeTimeStart));
	localmemcpy(field.TradeTimeEnd, input->TradeTimeEnd, sizeof(field.TradeTimeEnd));
	return field;
}
CTPTradeApi::CThostFtdcQryInvestorPositionField KStoCTPChange(KingstarAPI::CThostFtdcQryInvestorPositionField *input)
{
	CTPTradeApi::CThostFtdcQryInvestorPositionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryInvestorPositionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInvestorPositionField *input)
{
	KingstarAPI::CThostFtdcQryInvestorPositionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQryTradingAccountField KStoCTPChange(KingstarAPI::CThostFtdcQryTradingAccountField *input)
{
	CTPTradeApi::CThostFtdcQryTradingAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcQryTradingAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcQryTradingAccountField *input)
{
	KingstarAPI::CThostFtdcQryTradingAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcQryInvestorField KStoCTPChange(KingstarAPI::CThostFtdcQryInvestorField *input)
{
	CTPTradeApi::CThostFtdcQryInvestorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQryInvestorField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInvestorField *input)
{
	KingstarAPI::CThostFtdcQryInvestorField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcQryTradingCodeField KStoCTPChange(KingstarAPI::CThostFtdcQryTradingCodeField *input)
{
	CTPTradeApi::CThostFtdcQryTradingCodeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ClientIDType, input->ClientIDType, sizeof(field.ClientIDType));
	return field;
}
KingstarAPI::CThostFtdcQryTradingCodeField CTPtoKSChange(CTPTradeApi::CThostFtdcQryTradingCodeField *input)
{
	KingstarAPI::CThostFtdcQryTradingCodeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ClientIDType, input->ClientIDType, sizeof(field.ClientIDType));
	return field;
}
CTPTradeApi::CThostFtdcQryInvestorGroupField KStoCTPChange(KingstarAPI::CThostFtdcQryInvestorGroupField *input)
{
	CTPTradeApi::CThostFtdcQryInvestorGroupField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
KingstarAPI::CThostFtdcQryInvestorGroupField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInvestorGroupField *input)
{
	KingstarAPI::CThostFtdcQryInvestorGroupField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
CTPTradeApi::CThostFtdcQryInstrumentMarginRateField KStoCTPChange(KingstarAPI::CThostFtdcQryInstrumentMarginRateField *input)
{
	CTPTradeApi::CThostFtdcQryInstrumentMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
KingstarAPI::CThostFtdcQryInstrumentMarginRateField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInstrumentMarginRateField *input)
{
	KingstarAPI::CThostFtdcQryInstrumentMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
CTPTradeApi::CThostFtdcQryInstrumentCommissionRateField KStoCTPChange(KingstarAPI::CThostFtdcQryInstrumentCommissionRateField *input)
{
	CTPTradeApi::CThostFtdcQryInstrumentCommissionRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryInstrumentCommissionRateField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInstrumentCommissionRateField *input)
{
	KingstarAPI::CThostFtdcQryInstrumentCommissionRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQryInstrumentTradingRightField KStoCTPChange(KingstarAPI::CThostFtdcQryInstrumentTradingRightField *input)
{
	CTPTradeApi::CThostFtdcQryInstrumentTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryInstrumentTradingRightField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInstrumentTradingRightField *input)
{
	KingstarAPI::CThostFtdcQryInstrumentTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQryBrokerField KStoCTPChange(KingstarAPI::CThostFtdcQryBrokerField *input)
{
	CTPTradeApi::CThostFtdcQryBrokerField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
KingstarAPI::CThostFtdcQryBrokerField CTPtoKSChange(CTPTradeApi::CThostFtdcQryBrokerField *input)
{
	KingstarAPI::CThostFtdcQryBrokerField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
CTPTradeApi::CThostFtdcQryTraderField KStoCTPChange(KingstarAPI::CThostFtdcQryTraderField *input)
{
	CTPTradeApi::CThostFtdcQryTraderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryTraderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryTraderField *input)
{
	KingstarAPI::CThostFtdcQryTraderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcQrySuperUserFunctionField KStoCTPChange(KingstarAPI::CThostFtdcQrySuperUserFunctionField *input)
{
	CTPTradeApi::CThostFtdcQrySuperUserFunctionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcQrySuperUserFunctionField CTPtoKSChange(CTPTradeApi::CThostFtdcQrySuperUserFunctionField *input)
{
	KingstarAPI::CThostFtdcQrySuperUserFunctionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcQryUserSessionField KStoCTPChange(KingstarAPI::CThostFtdcQryUserSessionField *input)
{
	CTPTradeApi::CThostFtdcQryUserSessionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcQryUserSessionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryUserSessionField *input)
{
	KingstarAPI::CThostFtdcQryUserSessionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcQryPartBrokerField KStoCTPChange(KingstarAPI::CThostFtdcQryPartBrokerField *input)
{
	CTPTradeApi::CThostFtdcQryPartBrokerField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	return field;
}
KingstarAPI::CThostFtdcQryPartBrokerField CTPtoKSChange(CTPTradeApi::CThostFtdcQryPartBrokerField *input)
{
	KingstarAPI::CThostFtdcQryPartBrokerField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	return field;
}
CTPTradeApi::CThostFtdcQryFrontStatusField KStoCTPChange(KingstarAPI::CThostFtdcQryFrontStatusField *input)
{
	CTPTradeApi::CThostFtdcQryFrontStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	return field;
}
KingstarAPI::CThostFtdcQryFrontStatusField CTPtoKSChange(CTPTradeApi::CThostFtdcQryFrontStatusField *input)
{
	KingstarAPI::CThostFtdcQryFrontStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeOrderField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeOrderField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeOrderField *input)
{
	KingstarAPI::CThostFtdcQryExchangeOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcQryOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcQryOrderActionField *input)
{
	CTPTradeApi::CThostFtdcQryOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcQryOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryOrderActionField *input)
{
	KingstarAPI::CThostFtdcQryOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeOrderActionField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeOrderActionField *input)
{
	KingstarAPI::CThostFtdcQryExchangeOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcQrySuperUserField KStoCTPChange(KingstarAPI::CThostFtdcQrySuperUserField *input)
{
	CTPTradeApi::CThostFtdcQrySuperUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcQrySuperUserField CTPtoKSChange(CTPTradeApi::CThostFtdcQrySuperUserField *input)
{
	KingstarAPI::CThostFtdcQrySuperUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeField *input)
{
	KingstarAPI::CThostFtdcQryExchangeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcQryProductField KStoCTPChange(KingstarAPI::CThostFtdcQryProductField *input)
{
	CTPTradeApi::CThostFtdcQryProductField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ProductID, input->ProductID, sizeof(field.ProductID));
	localmemcpy(field.ProductClass, input->ProductClass, sizeof(field.ProductClass));
	return field;
}
KingstarAPI::CThostFtdcQryProductField CTPtoKSChange(CTPTradeApi::CThostFtdcQryProductField *input)
{
	KingstarAPI::CThostFtdcQryProductField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ProductID, input->ProductID, sizeof(field.ProductID));
	localmemcpy(field.ProductClass, input->ProductClass, sizeof(field.ProductClass));
	return field;
}
CTPTradeApi::CThostFtdcQryInstrumentField KStoCTPChange(KingstarAPI::CThostFtdcQryInstrumentField *input)
{
	CTPTradeApi::CThostFtdcQryInstrumentField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ProductID, input->ProductID, sizeof(field.ProductID));
	return field;
}
KingstarAPI::CThostFtdcQryInstrumentField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInstrumentField *input)
{
	KingstarAPI::CThostFtdcQryInstrumentField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ProductID, input->ProductID, sizeof(field.ProductID));
	return field;
}
CTPTradeApi::CThostFtdcQryDepthMarketDataField KStoCTPChange(KingstarAPI::CThostFtdcQryDepthMarketDataField *input)
{
	CTPTradeApi::CThostFtdcQryDepthMarketDataField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryDepthMarketDataField CTPtoKSChange(CTPTradeApi::CThostFtdcQryDepthMarketDataField *input)
{
	KingstarAPI::CThostFtdcQryDepthMarketDataField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQryBrokerUserField KStoCTPChange(KingstarAPI::CThostFtdcQryBrokerUserField *input)
{
	CTPTradeApi::CThostFtdcQryBrokerUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcQryBrokerUserField CTPtoKSChange(CTPTradeApi::CThostFtdcQryBrokerUserField *input)
{
	KingstarAPI::CThostFtdcQryBrokerUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcQryBrokerUserFunctionField KStoCTPChange(KingstarAPI::CThostFtdcQryBrokerUserFunctionField *input)
{
	CTPTradeApi::CThostFtdcQryBrokerUserFunctionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcQryBrokerUserFunctionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryBrokerUserFunctionField *input)
{
	KingstarAPI::CThostFtdcQryBrokerUserFunctionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcQryTraderOfferField KStoCTPChange(KingstarAPI::CThostFtdcQryTraderOfferField *input)
{
	CTPTradeApi::CThostFtdcQryTraderOfferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryTraderOfferField CTPtoKSChange(CTPTradeApi::CThostFtdcQryTraderOfferField *input)
{
	KingstarAPI::CThostFtdcQryTraderOfferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcQrySyncDepositField KStoCTPChange(KingstarAPI::CThostFtdcQrySyncDepositField *input)
{
	CTPTradeApi::CThostFtdcQrySyncDepositField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.DepositSeqNo, input->DepositSeqNo, sizeof(field.DepositSeqNo));
	return field;
}
KingstarAPI::CThostFtdcQrySyncDepositField CTPtoKSChange(CTPTradeApi::CThostFtdcQrySyncDepositField *input)
{
	KingstarAPI::CThostFtdcQrySyncDepositField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.DepositSeqNo, input->DepositSeqNo, sizeof(field.DepositSeqNo));
	return field;
}
CTPTradeApi::CThostFtdcQrySettlementInfoField KStoCTPChange(KingstarAPI::CThostFtdcQrySettlementInfoField *input)
{
	CTPTradeApi::CThostFtdcQrySettlementInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	return field;
}
KingstarAPI::CThostFtdcQrySettlementInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcQrySettlementInfoField *input)
{
	KingstarAPI::CThostFtdcQrySettlementInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeMarginRateField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeMarginRateField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeMarginRateField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeMarginRateField *input)
{
	KingstarAPI::CThostFtdcQryExchangeMarginRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeMarginRateAdjustField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeMarginRateAdjustField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeMarginRateAdjustField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeMarginRateAdjustField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeMarginRateAdjustField *input)
{
	KingstarAPI::CThostFtdcQryExchangeMarginRateAdjustField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeRateField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeRateField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.FromCurrencyID, input->FromCurrencyID, sizeof(field.FromCurrencyID));
	localmemcpy(field.ToCurrencyID, input->ToCurrencyID, sizeof(field.ToCurrencyID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeRateField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeRateField *input)
{
	KingstarAPI::CThostFtdcQryExchangeRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.FromCurrencyID, input->FromCurrencyID, sizeof(field.FromCurrencyID));
	localmemcpy(field.ToCurrencyID, input->ToCurrencyID, sizeof(field.ToCurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcQrySyncFundMortgageField KStoCTPChange(KingstarAPI::CThostFtdcQrySyncFundMortgageField *input)
{
	CTPTradeApi::CThostFtdcQrySyncFundMortgageField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MortgageSeqNo, input->MortgageSeqNo, sizeof(field.MortgageSeqNo));
	return field;
}
KingstarAPI::CThostFtdcQrySyncFundMortgageField CTPtoKSChange(CTPTradeApi::CThostFtdcQrySyncFundMortgageField *input)
{
	KingstarAPI::CThostFtdcQrySyncFundMortgageField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MortgageSeqNo, input->MortgageSeqNo, sizeof(field.MortgageSeqNo));
	return field;
}
CTPTradeApi::CThostFtdcQryHisOrderField KStoCTPChange(KingstarAPI::CThostFtdcQryHisOrderField *input)
{
	CTPTradeApi::CThostFtdcQryHisOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	return field;
}
KingstarAPI::CThostFtdcQryHisOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryHisOrderField *input)
{
	KingstarAPI::CThostFtdcQryHisOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	return field;
}
CTPTradeApi::CThostFtdcOptionInstrMiniMarginField KStoCTPChange(KingstarAPI::CThostFtdcOptionInstrMiniMarginField *input)
{
	CTPTradeApi::CThostFtdcOptionInstrMiniMarginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.MinMargin, input->MinMargin, sizeof(field.MinMargin));
	localmemcpy(field.ValueMethod, input->ValueMethod, sizeof(field.ValueMethod));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
KingstarAPI::CThostFtdcOptionInstrMiniMarginField CTPtoKSChange(CTPTradeApi::CThostFtdcOptionInstrMiniMarginField *input)
{
	KingstarAPI::CThostFtdcOptionInstrMiniMarginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.MinMargin, input->MinMargin, sizeof(field.MinMargin));
	localmemcpy(field.ValueMethod, input->ValueMethod, sizeof(field.ValueMethod));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
CTPTradeApi::CThostFtdcOptionInstrMarginAdjustField KStoCTPChange(KingstarAPI::CThostFtdcOptionInstrMarginAdjustField *input)
{
	CTPTradeApi::CThostFtdcOptionInstrMarginAdjustField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.SShortMarginRatioByMoney, input->SShortMarginRatioByMoney, sizeof(field.SShortMarginRatioByMoney));
	localmemcpy(field.SShortMarginRatioByVolume, input->SShortMarginRatioByVolume, sizeof(field.SShortMarginRatioByVolume));
	localmemcpy(field.HShortMarginRatioByMoney, input->HShortMarginRatioByMoney, sizeof(field.HShortMarginRatioByMoney));
	localmemcpy(field.HShortMarginRatioByVolume, input->HShortMarginRatioByVolume, sizeof(field.HShortMarginRatioByVolume));
	localmemcpy(field.AShortMarginRatioByMoney, input->AShortMarginRatioByMoney, sizeof(field.AShortMarginRatioByMoney));
	localmemcpy(field.AShortMarginRatioByVolume, input->AShortMarginRatioByVolume, sizeof(field.AShortMarginRatioByVolume));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
KingstarAPI::CThostFtdcOptionInstrMarginAdjustField CTPtoKSChange(CTPTradeApi::CThostFtdcOptionInstrMarginAdjustField *input)
{
	KingstarAPI::CThostFtdcOptionInstrMarginAdjustField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.SShortMarginRatioByMoney, input->SShortMarginRatioByMoney, sizeof(field.SShortMarginRatioByMoney));
	localmemcpy(field.SShortMarginRatioByVolume, input->SShortMarginRatioByVolume, sizeof(field.SShortMarginRatioByVolume));
	localmemcpy(field.HShortMarginRatioByMoney, input->HShortMarginRatioByMoney, sizeof(field.HShortMarginRatioByMoney));
	localmemcpy(field.HShortMarginRatioByVolume, input->HShortMarginRatioByVolume, sizeof(field.HShortMarginRatioByVolume));
	localmemcpy(field.AShortMarginRatioByMoney, input->AShortMarginRatioByMoney, sizeof(field.AShortMarginRatioByMoney));
	localmemcpy(field.AShortMarginRatioByVolume, input->AShortMarginRatioByVolume, sizeof(field.AShortMarginRatioByVolume));
	localmemcpy(field.IsRelative, input->IsRelative, sizeof(field.IsRelative));
	return field;
}
CTPTradeApi::CThostFtdcOptionInstrCommRateField KStoCTPChange(KingstarAPI::CThostFtdcOptionInstrCommRateField *input)
{
	CTPTradeApi::CThostFtdcOptionInstrCommRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OpenRatioByMoney, input->OpenRatioByMoney, sizeof(field.OpenRatioByMoney));
	localmemcpy(field.OpenRatioByVolume, input->OpenRatioByVolume, sizeof(field.OpenRatioByVolume));
	localmemcpy(field.CloseRatioByMoney, input->CloseRatioByMoney, sizeof(field.CloseRatioByMoney));
	localmemcpy(field.CloseRatioByVolume, input->CloseRatioByVolume, sizeof(field.CloseRatioByVolume));
	localmemcpy(field.CloseTodayRatioByMoney, input->CloseTodayRatioByMoney, sizeof(field.CloseTodayRatioByMoney));
	localmemcpy(field.CloseTodayRatioByVolume, input->CloseTodayRatioByVolume, sizeof(field.CloseTodayRatioByVolume));
	localmemcpy(field.StrikeRatioByMoney, input->StrikeRatioByMoney, sizeof(field.StrikeRatioByMoney));
	localmemcpy(field.StrikeRatioByVolume, input->StrikeRatioByVolume, sizeof(field.StrikeRatioByVolume));
	return field;
}
KingstarAPI::CThostFtdcOptionInstrCommRateField CTPtoKSChange(CTPTradeApi::CThostFtdcOptionInstrCommRateField *input)
{
	KingstarAPI::CThostFtdcOptionInstrCommRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OpenRatioByMoney, input->OpenRatioByMoney, sizeof(field.OpenRatioByMoney));
	localmemcpy(field.OpenRatioByVolume, input->OpenRatioByVolume, sizeof(field.OpenRatioByVolume));
	localmemcpy(field.CloseRatioByMoney, input->CloseRatioByMoney, sizeof(field.CloseRatioByMoney));
	localmemcpy(field.CloseRatioByVolume, input->CloseRatioByVolume, sizeof(field.CloseRatioByVolume));
	localmemcpy(field.CloseTodayRatioByMoney, input->CloseTodayRatioByMoney, sizeof(field.CloseTodayRatioByMoney));
	localmemcpy(field.CloseTodayRatioByVolume, input->CloseTodayRatioByVolume, sizeof(field.CloseTodayRatioByVolume));
	localmemcpy(field.StrikeRatioByMoney, input->StrikeRatioByMoney, sizeof(field.StrikeRatioByMoney));
	localmemcpy(field.StrikeRatioByVolume, input->StrikeRatioByVolume, sizeof(field.StrikeRatioByVolume));
	return field;
}
CTPTradeApi::CThostFtdcOptionInstrTradeCostField KStoCTPChange(KingstarAPI::CThostFtdcOptionInstrTradeCostField *input)
{
	CTPTradeApi::CThostFtdcOptionInstrTradeCostField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.FixedMargin, input->FixedMargin, sizeof(field.FixedMargin));
	localmemcpy(field.MiniMargin, input->MiniMargin, sizeof(field.MiniMargin));
	localmemcpy(field.Royalty, input->Royalty, sizeof(field.Royalty));
	localmemcpy(field.ExchFixedMargin, input->ExchFixedMargin, sizeof(field.ExchFixedMargin));
	localmemcpy(field.ExchMiniMargin, input->ExchMiniMargin, sizeof(field.ExchMiniMargin));
	return field;
}
KingstarAPI::CThostFtdcOptionInstrTradeCostField CTPtoKSChange(CTPTradeApi::CThostFtdcOptionInstrTradeCostField *input)
{
	KingstarAPI::CThostFtdcOptionInstrTradeCostField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.FixedMargin, input->FixedMargin, sizeof(field.FixedMargin));
	localmemcpy(field.MiniMargin, input->MiniMargin, sizeof(field.MiniMargin));
	localmemcpy(field.Royalty, input->Royalty, sizeof(field.Royalty));
	localmemcpy(field.ExchFixedMargin, input->ExchFixedMargin, sizeof(field.ExchFixedMargin));
	localmemcpy(field.ExchMiniMargin, input->ExchMiniMargin, sizeof(field.ExchMiniMargin));
	return field;
}
CTPTradeApi::CThostFtdcQryOptionInstrTradeCostField KStoCTPChange(KingstarAPI::CThostFtdcQryOptionInstrTradeCostField *input)
{
	CTPTradeApi::CThostFtdcQryOptionInstrTradeCostField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.InputPrice, input->InputPrice, sizeof(field.InputPrice));
	localmemcpy(field.UnderlyingPrice, input->UnderlyingPrice, sizeof(field.UnderlyingPrice));
	return field;
}
KingstarAPI::CThostFtdcQryOptionInstrTradeCostField CTPtoKSChange(CTPTradeApi::CThostFtdcQryOptionInstrTradeCostField *input)
{
	KingstarAPI::CThostFtdcQryOptionInstrTradeCostField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.InputPrice, input->InputPrice, sizeof(field.InputPrice));
	localmemcpy(field.UnderlyingPrice, input->UnderlyingPrice, sizeof(field.UnderlyingPrice));
	return field;
}
CTPTradeApi::CThostFtdcQryOptionInstrCommRateField KStoCTPChange(KingstarAPI::CThostFtdcQryOptionInstrCommRateField *input)
{
	CTPTradeApi::CThostFtdcQryOptionInstrCommRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryOptionInstrCommRateField CTPtoKSChange(CTPTradeApi::CThostFtdcQryOptionInstrCommRateField *input)
{
	KingstarAPI::CThostFtdcQryOptionInstrCommRateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcIndexPriceField KStoCTPChange(KingstarAPI::CThostFtdcIndexPriceField *input)
{
	CTPTradeApi::CThostFtdcIndexPriceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ClosePrice, input->ClosePrice, sizeof(field.ClosePrice));
	return field;
}
KingstarAPI::CThostFtdcIndexPriceField CTPtoKSChange(CTPTradeApi::CThostFtdcIndexPriceField *input)
{
	KingstarAPI::CThostFtdcIndexPriceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ClosePrice, input->ClosePrice, sizeof(field.ClosePrice));
	return field;
}
CTPTradeApi::CThostFtdcInputExecOrderField KStoCTPChange(KingstarAPI::CThostFtdcInputExecOrderField *input)
{
	CTPTradeApi::CThostFtdcInputExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.ReservePositionFlag, input->ReservePositionFlag, sizeof(field.ReservePositionFlag));
	localmemcpy(field.CloseFlag, input->CloseFlag, sizeof(field.CloseFlag));
	return field;
}
KingstarAPI::CThostFtdcInputExecOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcInputExecOrderField *input)
{
	KingstarAPI::CThostFtdcInputExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.ReservePositionFlag, input->ReservePositionFlag, sizeof(field.ReservePositionFlag));
	localmemcpy(field.CloseFlag, input->CloseFlag, sizeof(field.CloseFlag));
	return field;
}
CTPTradeApi::CThostFtdcInputExecOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcInputExecOrderActionField *input)
{
	CTPTradeApi::CThostFtdcInputExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExecOrderActionRef, input->ExecOrderActionRef, sizeof(field.ExecOrderActionRef));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcInputExecOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcInputExecOrderActionField *input)
{
	KingstarAPI::CThostFtdcInputExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExecOrderActionRef, input->ExecOrderActionRef, sizeof(field.ExecOrderActionRef));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcExecOrderField KStoCTPChange(KingstarAPI::CThostFtdcExecOrderField *input)
{
	CTPTradeApi::CThostFtdcExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.ReservePositionFlag, input->ReservePositionFlag, sizeof(field.ReservePositionFlag));
	localmemcpy(field.CloseFlag, input->CloseFlag, sizeof(field.CloseFlag));
	localmemcpy(field.ExecOrderLocalID, input->ExecOrderLocalID, sizeof(field.ExecOrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ExecResult, input->ExecResult, sizeof(field.ExecResult));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerExecOrderSeq, input->BrokerExecOrderSeq, sizeof(field.BrokerExecOrderSeq));
	return field;
}
KingstarAPI::CThostFtdcExecOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcExecOrderField *input)
{
	KingstarAPI::CThostFtdcExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.ReservePositionFlag, input->ReservePositionFlag, sizeof(field.ReservePositionFlag));
	localmemcpy(field.CloseFlag, input->CloseFlag, sizeof(field.CloseFlag));
	localmemcpy(field.ExecOrderLocalID, input->ExecOrderLocalID, sizeof(field.ExecOrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ExecResult, input->ExecResult, sizeof(field.ExecResult));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerExecOrderSeq, input->BrokerExecOrderSeq, sizeof(field.BrokerExecOrderSeq));
	return field;
}
CTPTradeApi::CThostFtdcExecOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcExecOrderActionField *input)
{
	CTPTradeApi::CThostFtdcExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExecOrderActionRef, input->ExecOrderActionRef, sizeof(field.ExecOrderActionRef));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.ExecOrderLocalID, input->ExecOrderLocalID, sizeof(field.ExecOrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcExecOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcExecOrderActionField *input)
{
	KingstarAPI::CThostFtdcExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExecOrderActionRef, input->ExecOrderActionRef, sizeof(field.ExecOrderActionRef));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.ExecOrderLocalID, input->ExecOrderLocalID, sizeof(field.ExecOrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQryExecOrderField KStoCTPChange(KingstarAPI::CThostFtdcQryExecOrderField *input)
{
	CTPTradeApi::CThostFtdcQryExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	return field;
}
KingstarAPI::CThostFtdcQryExecOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExecOrderField *input)
{
	KingstarAPI::CThostFtdcQryExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	return field;
}
CTPTradeApi::CThostFtdcExchangeExecOrderField KStoCTPChange(KingstarAPI::CThostFtdcExchangeExecOrderField *input)
{
	CTPTradeApi::CThostFtdcExchangeExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.ReservePositionFlag, input->ReservePositionFlag, sizeof(field.ReservePositionFlag));
	localmemcpy(field.CloseFlag, input->CloseFlag, sizeof(field.CloseFlag));
	localmemcpy(field.ExecOrderLocalID, input->ExecOrderLocalID, sizeof(field.ExecOrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ExecResult, input->ExecResult, sizeof(field.ExecResult));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	return field;
}
KingstarAPI::CThostFtdcExchangeExecOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeExecOrderField *input)
{
	KingstarAPI::CThostFtdcExchangeExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.ReservePositionFlag, input->ReservePositionFlag, sizeof(field.ReservePositionFlag));
	localmemcpy(field.CloseFlag, input->CloseFlag, sizeof(field.CloseFlag));
	localmemcpy(field.ExecOrderLocalID, input->ExecOrderLocalID, sizeof(field.ExecOrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ExecResult, input->ExecResult, sizeof(field.ExecResult));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeExecOrderField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeExecOrderField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeExecOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeExecOrderField *input)
{
	KingstarAPI::CThostFtdcQryExchangeExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcQryExecOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcQryExecOrderActionField *input)
{
	CTPTradeApi::CThostFtdcQryExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcQryExecOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExecOrderActionField *input)
{
	KingstarAPI::CThostFtdcQryExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcExchangeExecOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcExchangeExecOrderActionField *input)
{
	CTPTradeApi::CThostFtdcExchangeExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.ExecOrderLocalID, input->ExecOrderLocalID, sizeof(field.ExecOrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	return field;
}
KingstarAPI::CThostFtdcExchangeExecOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeExecOrderActionField *input)
{
	KingstarAPI::CThostFtdcExchangeExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.ExecOrderLocalID, input->ExecOrderLocalID, sizeof(field.ExecOrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeExecOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeExecOrderActionField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeExecOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeExecOrderActionField *input)
{
	KingstarAPI::CThostFtdcQryExchangeExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcErrExecOrderField KStoCTPChange(KingstarAPI::CThostFtdcErrExecOrderField *input)
{
	CTPTradeApi::CThostFtdcErrExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.ReservePositionFlag, input->ReservePositionFlag, sizeof(field.ReservePositionFlag));
	localmemcpy(field.CloseFlag, input->CloseFlag, sizeof(field.CloseFlag));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcErrExecOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcErrExecOrderField *input)
{
	KingstarAPI::CThostFtdcErrExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.ActionType, input->ActionType, sizeof(field.ActionType));
	localmemcpy(field.PosiDirection, input->PosiDirection, sizeof(field.PosiDirection));
	localmemcpy(field.ReservePositionFlag, input->ReservePositionFlag, sizeof(field.ReservePositionFlag));
	localmemcpy(field.CloseFlag, input->CloseFlag, sizeof(field.CloseFlag));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcQryErrExecOrderField KStoCTPChange(KingstarAPI::CThostFtdcQryErrExecOrderField *input)
{
	CTPTradeApi::CThostFtdcQryErrExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQryErrExecOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryErrExecOrderField *input)
{
	KingstarAPI::CThostFtdcQryErrExecOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcErrExecOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcErrExecOrderActionField *input)
{
	CTPTradeApi::CThostFtdcErrExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExecOrderActionRef, input->ExecOrderActionRef, sizeof(field.ExecOrderActionRef));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcErrExecOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcErrExecOrderActionField *input)
{
	KingstarAPI::CThostFtdcErrExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExecOrderActionRef, input->ExecOrderActionRef, sizeof(field.ExecOrderActionRef));
	localmemcpy(field.ExecOrderRef, input->ExecOrderRef, sizeof(field.ExecOrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExecOrderSysID, input->ExecOrderSysID, sizeof(field.ExecOrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcQryErrExecOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcQryErrExecOrderActionField *input)
{
	CTPTradeApi::CThostFtdcQryErrExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQryErrExecOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryErrExecOrderActionField *input)
{
	KingstarAPI::CThostFtdcQryErrExecOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcOptionInstrTradingRightField KStoCTPChange(KingstarAPI::CThostFtdcOptionInstrTradingRightField *input)
{
	CTPTradeApi::CThostFtdcOptionInstrTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.TradingRight, input->TradingRight, sizeof(field.TradingRight));
	return field;
}
KingstarAPI::CThostFtdcOptionInstrTradingRightField CTPtoKSChange(CTPTradeApi::CThostFtdcOptionInstrTradingRightField *input)
{
	KingstarAPI::CThostFtdcOptionInstrTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.TradingRight, input->TradingRight, sizeof(field.TradingRight));
	return field;
}
CTPTradeApi::CThostFtdcQryOptionInstrTradingRightField KStoCTPChange(KingstarAPI::CThostFtdcQryOptionInstrTradingRightField *input)
{
	CTPTradeApi::CThostFtdcQryOptionInstrTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	return field;
}
KingstarAPI::CThostFtdcQryOptionInstrTradingRightField CTPtoKSChange(CTPTradeApi::CThostFtdcQryOptionInstrTradingRightField *input)
{
	KingstarAPI::CThostFtdcQryOptionInstrTradingRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	return field;
}
CTPTradeApi::CThostFtdcInputForQuoteField KStoCTPChange(KingstarAPI::CThostFtdcInputForQuoteField *input)
{
	CTPTradeApi::CThostFtdcInputForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ForQuoteRef, input->ForQuoteRef, sizeof(field.ForQuoteRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcInputForQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcInputForQuoteField *input)
{
	KingstarAPI::CThostFtdcInputForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ForQuoteRef, input->ForQuoteRef, sizeof(field.ForQuoteRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcForQuoteField KStoCTPChange(KingstarAPI::CThostFtdcForQuoteField *input)
{
	CTPTradeApi::CThostFtdcForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ForQuoteRef, input->ForQuoteRef, sizeof(field.ForQuoteRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ForQuoteLocalID, input->ForQuoteLocalID, sizeof(field.ForQuoteLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ForQuoteStatus, input->ForQuoteStatus, sizeof(field.ForQuoteStatus));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerForQutoSeq, input->BrokerForQutoSeq, sizeof(field.BrokerForQutoSeq));
	return field;
}
KingstarAPI::CThostFtdcForQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcForQuoteField *input)
{
	KingstarAPI::CThostFtdcForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ForQuoteRef, input->ForQuoteRef, sizeof(field.ForQuoteRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ForQuoteLocalID, input->ForQuoteLocalID, sizeof(field.ForQuoteLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ForQuoteStatus, input->ForQuoteStatus, sizeof(field.ForQuoteStatus));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerForQutoSeq, input->BrokerForQutoSeq, sizeof(field.BrokerForQutoSeq));
	return field;
}
CTPTradeApi::CThostFtdcQryForQuoteField KStoCTPChange(KingstarAPI::CThostFtdcQryForQuoteField *input)
{
	CTPTradeApi::CThostFtdcQryForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	return field;
}
KingstarAPI::CThostFtdcQryForQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcQryForQuoteField *input)
{
	KingstarAPI::CThostFtdcQryForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	return field;
}
CTPTradeApi::CThostFtdcExchangeForQuoteField KStoCTPChange(KingstarAPI::CThostFtdcExchangeForQuoteField *input)
{
	CTPTradeApi::CThostFtdcExchangeForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ForQuoteLocalID, input->ForQuoteLocalID, sizeof(field.ForQuoteLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ForQuoteStatus, input->ForQuoteStatus, sizeof(field.ForQuoteStatus));
	return field;
}
KingstarAPI::CThostFtdcExchangeForQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeForQuoteField *input)
{
	KingstarAPI::CThostFtdcExchangeForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ForQuoteLocalID, input->ForQuoteLocalID, sizeof(field.ForQuoteLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ForQuoteStatus, input->ForQuoteStatus, sizeof(field.ForQuoteStatus));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeForQuoteField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeForQuoteField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeForQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeForQuoteField *input)
{
	KingstarAPI::CThostFtdcQryExchangeForQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcInputQuoteField KStoCTPChange(KingstarAPI::CThostFtdcInputQuoteField *input)
{
	CTPTradeApi::CThostFtdcInputQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.QuoteRef, input->QuoteRef, sizeof(field.QuoteRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.AskPrice, input->AskPrice, sizeof(field.AskPrice));
	localmemcpy(field.BidPrice, input->BidPrice, sizeof(field.BidPrice));
	localmemcpy(field.AskVolume, input->AskVolume, sizeof(field.AskVolume));
	localmemcpy(field.BidVolume, input->BidVolume, sizeof(field.BidVolume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.AskOffsetFlag, input->AskOffsetFlag, sizeof(field.AskOffsetFlag));
	localmemcpy(field.BidOffsetFlag, input->BidOffsetFlag, sizeof(field.BidOffsetFlag));
	localmemcpy(field.AskHedgeFlag, input->AskHedgeFlag, sizeof(field.AskHedgeFlag));
	localmemcpy(field.BidHedgeFlag, input->BidHedgeFlag, sizeof(field.BidHedgeFlag));
	localmemcpy(field.AskOrderRef, input->AskOrderRef, sizeof(field.AskOrderRef));
	localmemcpy(field.BidOrderRef, input->BidOrderRef, sizeof(field.BidOrderRef));
	return field;
}
KingstarAPI::CThostFtdcInputQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcInputQuoteField *input)
{
	KingstarAPI::CThostFtdcInputQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.QuoteRef, input->QuoteRef, sizeof(field.QuoteRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.AskPrice, input->AskPrice, sizeof(field.AskPrice));
	localmemcpy(field.BidPrice, input->BidPrice, sizeof(field.BidPrice));
	localmemcpy(field.AskVolume, input->AskVolume, sizeof(field.AskVolume));
	localmemcpy(field.BidVolume, input->BidVolume, sizeof(field.BidVolume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.AskOffsetFlag, input->AskOffsetFlag, sizeof(field.AskOffsetFlag));
	localmemcpy(field.BidOffsetFlag, input->BidOffsetFlag, sizeof(field.BidOffsetFlag));
	localmemcpy(field.AskHedgeFlag, input->AskHedgeFlag, sizeof(field.AskHedgeFlag));
	localmemcpy(field.BidHedgeFlag, input->BidHedgeFlag, sizeof(field.BidHedgeFlag));
	localmemcpy(field.AskOrderRef, input->AskOrderRef, sizeof(field.AskOrderRef));
	localmemcpy(field.BidOrderRef, input->BidOrderRef, sizeof(field.BidOrderRef));
	return field;
}
CTPTradeApi::CThostFtdcInputQuoteActionField KStoCTPChange(KingstarAPI::CThostFtdcInputQuoteActionField *input)
{
	CTPTradeApi::CThostFtdcInputQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.QuoteActionRef, input->QuoteActionRef, sizeof(field.QuoteActionRef));
	localmemcpy(field.QuoteRef, input->QuoteRef, sizeof(field.QuoteRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcInputQuoteActionField CTPtoKSChange(CTPTradeApi::CThostFtdcInputQuoteActionField *input)
{
	KingstarAPI::CThostFtdcInputQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.QuoteActionRef, input->QuoteActionRef, sizeof(field.QuoteActionRef));
	localmemcpy(field.QuoteRef, input->QuoteRef, sizeof(field.QuoteRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQuoteField KStoCTPChange(KingstarAPI::CThostFtdcQuoteField *input)
{
	CTPTradeApi::CThostFtdcQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.QuoteRef, input->QuoteRef, sizeof(field.QuoteRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.AskPrice, input->AskPrice, sizeof(field.AskPrice));
	localmemcpy(field.BidPrice, input->BidPrice, sizeof(field.BidPrice));
	localmemcpy(field.AskVolume, input->AskVolume, sizeof(field.AskVolume));
	localmemcpy(field.BidVolume, input->BidVolume, sizeof(field.BidVolume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.AskOffsetFlag, input->AskOffsetFlag, sizeof(field.AskOffsetFlag));
	localmemcpy(field.BidOffsetFlag, input->BidOffsetFlag, sizeof(field.BidOffsetFlag));
	localmemcpy(field.AskHedgeFlag, input->AskHedgeFlag, sizeof(field.AskHedgeFlag));
	localmemcpy(field.BidHedgeFlag, input->BidHedgeFlag, sizeof(field.BidHedgeFlag));
	localmemcpy(field.QuoteLocalID, input->QuoteLocalID, sizeof(field.QuoteLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.QuoteStatus, input->QuoteStatus, sizeof(field.QuoteStatus));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.AskOrderSysID, input->AskOrderSysID, sizeof(field.AskOrderSysID));
	localmemcpy(field.BidOrderSysID, input->BidOrderSysID, sizeof(field.BidOrderSysID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerQuoteSeq, input->BrokerQuoteSeq, sizeof(field.BrokerQuoteSeq));
	localmemcpy(field.AskOrderRef, input->AskOrderRef, sizeof(field.AskOrderRef));
	localmemcpy(field.BidOrderRef, input->BidOrderRef, sizeof(field.BidOrderRef));
	return field;
}
KingstarAPI::CThostFtdcQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcQuoteField *input)
{
	KingstarAPI::CThostFtdcQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.QuoteRef, input->QuoteRef, sizeof(field.QuoteRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.AskPrice, input->AskPrice, sizeof(field.AskPrice));
	localmemcpy(field.BidPrice, input->BidPrice, sizeof(field.BidPrice));
	localmemcpy(field.AskVolume, input->AskVolume, sizeof(field.AskVolume));
	localmemcpy(field.BidVolume, input->BidVolume, sizeof(field.BidVolume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.AskOffsetFlag, input->AskOffsetFlag, sizeof(field.AskOffsetFlag));
	localmemcpy(field.BidOffsetFlag, input->BidOffsetFlag, sizeof(field.BidOffsetFlag));
	localmemcpy(field.AskHedgeFlag, input->AskHedgeFlag, sizeof(field.AskHedgeFlag));
	localmemcpy(field.BidHedgeFlag, input->BidHedgeFlag, sizeof(field.BidHedgeFlag));
	localmemcpy(field.QuoteLocalID, input->QuoteLocalID, sizeof(field.QuoteLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.QuoteStatus, input->QuoteStatus, sizeof(field.QuoteStatus));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.AskOrderSysID, input->AskOrderSysID, sizeof(field.AskOrderSysID));
	localmemcpy(field.BidOrderSysID, input->BidOrderSysID, sizeof(field.BidOrderSysID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerQuoteSeq, input->BrokerQuoteSeq, sizeof(field.BrokerQuoteSeq));
	localmemcpy(field.AskOrderRef, input->AskOrderRef, sizeof(field.AskOrderRef));
	localmemcpy(field.BidOrderRef, input->BidOrderRef, sizeof(field.BidOrderRef));
	return field;
}
CTPTradeApi::CThostFtdcQuoteActionField KStoCTPChange(KingstarAPI::CThostFtdcQuoteActionField *input)
{
	CTPTradeApi::CThostFtdcQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.QuoteActionRef, input->QuoteActionRef, sizeof(field.QuoteActionRef));
	localmemcpy(field.QuoteRef, input->QuoteRef, sizeof(field.QuoteRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.QuoteLocalID, input->QuoteLocalID, sizeof(field.QuoteLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQuoteActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQuoteActionField *input)
{
	KingstarAPI::CThostFtdcQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.QuoteActionRef, input->QuoteActionRef, sizeof(field.QuoteActionRef));
	localmemcpy(field.QuoteRef, input->QuoteRef, sizeof(field.QuoteRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.QuoteLocalID, input->QuoteLocalID, sizeof(field.QuoteLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQryQuoteField KStoCTPChange(KingstarAPI::CThostFtdcQryQuoteField *input)
{
	CTPTradeApi::CThostFtdcQryQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	return field;
}
KingstarAPI::CThostFtdcQryQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcQryQuoteField *input)
{
	KingstarAPI::CThostFtdcQryQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.InsertTimeStart, input->InsertTimeStart, sizeof(field.InsertTimeStart));
	localmemcpy(field.InsertTimeEnd, input->InsertTimeEnd, sizeof(field.InsertTimeEnd));
	return field;
}
CTPTradeApi::CThostFtdcExchangeQuoteField KStoCTPChange(KingstarAPI::CThostFtdcExchangeQuoteField *input)
{
	CTPTradeApi::CThostFtdcExchangeQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.AskPrice, input->AskPrice, sizeof(field.AskPrice));
	localmemcpy(field.BidPrice, input->BidPrice, sizeof(field.BidPrice));
	localmemcpy(field.AskVolume, input->AskVolume, sizeof(field.AskVolume));
	localmemcpy(field.BidVolume, input->BidVolume, sizeof(field.BidVolume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.AskOffsetFlag, input->AskOffsetFlag, sizeof(field.AskOffsetFlag));
	localmemcpy(field.BidOffsetFlag, input->BidOffsetFlag, sizeof(field.BidOffsetFlag));
	localmemcpy(field.AskHedgeFlag, input->AskHedgeFlag, sizeof(field.AskHedgeFlag));
	localmemcpy(field.BidHedgeFlag, input->BidHedgeFlag, sizeof(field.BidHedgeFlag));
	localmemcpy(field.QuoteLocalID, input->QuoteLocalID, sizeof(field.QuoteLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.QuoteStatus, input->QuoteStatus, sizeof(field.QuoteStatus));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.AskOrderSysID, input->AskOrderSysID, sizeof(field.AskOrderSysID));
	localmemcpy(field.BidOrderSysID, input->BidOrderSysID, sizeof(field.BidOrderSysID));
	return field;
}
KingstarAPI::CThostFtdcExchangeQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeQuoteField *input)
{
	KingstarAPI::CThostFtdcExchangeQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.AskPrice, input->AskPrice, sizeof(field.AskPrice));
	localmemcpy(field.BidPrice, input->BidPrice, sizeof(field.BidPrice));
	localmemcpy(field.AskVolume, input->AskVolume, sizeof(field.AskVolume));
	localmemcpy(field.BidVolume, input->BidVolume, sizeof(field.BidVolume));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.AskOffsetFlag, input->AskOffsetFlag, sizeof(field.AskOffsetFlag));
	localmemcpy(field.BidOffsetFlag, input->BidOffsetFlag, sizeof(field.BidOffsetFlag));
	localmemcpy(field.AskHedgeFlag, input->AskHedgeFlag, sizeof(field.AskHedgeFlag));
	localmemcpy(field.BidHedgeFlag, input->BidHedgeFlag, sizeof(field.BidHedgeFlag));
	localmemcpy(field.QuoteLocalID, input->QuoteLocalID, sizeof(field.QuoteLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.QuoteStatus, input->QuoteStatus, sizeof(field.QuoteStatus));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.AskOrderSysID, input->AskOrderSysID, sizeof(field.AskOrderSysID));
	localmemcpy(field.BidOrderSysID, input->BidOrderSysID, sizeof(field.BidOrderSysID));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeQuoteField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeQuoteField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeQuoteField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeQuoteField *input)
{
	KingstarAPI::CThostFtdcQryExchangeQuoteField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcQryQuoteActionField KStoCTPChange(KingstarAPI::CThostFtdcQryQuoteActionField *input)
{
	CTPTradeApi::CThostFtdcQryQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcQryQuoteActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryQuoteActionField *input)
{
	KingstarAPI::CThostFtdcQryQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcExchangeQuoteActionField KStoCTPChange(KingstarAPI::CThostFtdcExchangeQuoteActionField *input)
{
	CTPTradeApi::CThostFtdcExchangeQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.QuoteLocalID, input->QuoteLocalID, sizeof(field.QuoteLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcExchangeQuoteActionField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeQuoteActionField *input)
{
	KingstarAPI::CThostFtdcExchangeQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.QuoteSysID, input->QuoteSysID, sizeof(field.QuoteSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.QuoteLocalID, input->QuoteLocalID, sizeof(field.QuoteLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeQuoteActionField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeQuoteActionField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeQuoteActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeQuoteActionField *input)
{
	KingstarAPI::CThostFtdcQryExchangeQuoteActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcOptionInstrDeltaField KStoCTPChange(KingstarAPI::CThostFtdcOptionInstrDeltaField *input)
{
	CTPTradeApi::CThostFtdcOptionInstrDeltaField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Delta, input->Delta, sizeof(field.Delta));
	return field;
}
KingstarAPI::CThostFtdcOptionInstrDeltaField CTPtoKSChange(CTPTradeApi::CThostFtdcOptionInstrDeltaField *input)
{
	KingstarAPI::CThostFtdcOptionInstrDeltaField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Delta, input->Delta, sizeof(field.Delta));
	return field;
}
CTPTradeApi::CThostFtdcForQuoteRspField KStoCTPChange(KingstarAPI::CThostFtdcForQuoteRspField *input)
{
	CTPTradeApi::CThostFtdcForQuoteRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ForQuoteSysID, input->ForQuoteSysID, sizeof(field.ForQuoteSysID));
	localmemcpy(field.ForQuoteTime, input->ForQuoteTime, sizeof(field.ForQuoteTime));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcForQuoteRspField CTPtoKSChange(CTPTradeApi::CThostFtdcForQuoteRspField *input)
{
	KingstarAPI::CThostFtdcForQuoteRspField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ForQuoteSysID, input->ForQuoteSysID, sizeof(field.ForQuoteSysID));
	localmemcpy(field.ForQuoteTime, input->ForQuoteTime, sizeof(field.ForQuoteTime));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcStrikeOffsetField KStoCTPChange(KingstarAPI::CThostFtdcStrikeOffsetField *input)
{
	CTPTradeApi::CThostFtdcStrikeOffsetField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Offset, input->Offset, sizeof(field.Offset));
	return field;
}
KingstarAPI::CThostFtdcStrikeOffsetField CTPtoKSChange(CTPTradeApi::CThostFtdcStrikeOffsetField *input)
{
	KingstarAPI::CThostFtdcStrikeOffsetField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Offset, input->Offset, sizeof(field.Offset));
	return field;
}
CTPTradeApi::CThostFtdcQryStrikeOffsetField KStoCTPChange(KingstarAPI::CThostFtdcQryStrikeOffsetField *input)
{
	CTPTradeApi::CThostFtdcQryStrikeOffsetField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryStrikeOffsetField CTPtoKSChange(CTPTradeApi::CThostFtdcQryStrikeOffsetField *input)
{
	KingstarAPI::CThostFtdcQryStrikeOffsetField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataField KStoCTPChange(KingstarAPI::CThostFtdcMarketDataField *input)
{
	CTPTradeApi::CThostFtdcMarketDataField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.LastPrice, input->LastPrice, sizeof(field.LastPrice));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.PreClosePrice, input->PreClosePrice, sizeof(field.PreClosePrice));
	localmemcpy(field.PreOpenInterest, input->PreOpenInterest, sizeof(field.PreOpenInterest));
	localmemcpy(field.OpenPrice, input->OpenPrice, sizeof(field.OpenPrice));
	localmemcpy(field.HighestPrice, input->HighestPrice, sizeof(field.HighestPrice));
	localmemcpy(field.LowestPrice, input->LowestPrice, sizeof(field.LowestPrice));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.Turnover, input->Turnover, sizeof(field.Turnover));
	localmemcpy(field.OpenInterest, input->OpenInterest, sizeof(field.OpenInterest));
	localmemcpy(field.ClosePrice, input->ClosePrice, sizeof(field.ClosePrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.UpperLimitPrice, input->UpperLimitPrice, sizeof(field.UpperLimitPrice));
	localmemcpy(field.LowerLimitPrice, input->LowerLimitPrice, sizeof(field.LowerLimitPrice));
	localmemcpy(field.PreDelta, input->PreDelta, sizeof(field.PreDelta));
	localmemcpy(field.CurrDelta, input->CurrDelta, sizeof(field.CurrDelta));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.UpdateMillisec, input->UpdateMillisec, sizeof(field.UpdateMillisec));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	return field;
}
KingstarAPI::CThostFtdcMarketDataField CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataField *input)
{
	KingstarAPI::CThostFtdcMarketDataField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.LastPrice, input->LastPrice, sizeof(field.LastPrice));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.PreClosePrice, input->PreClosePrice, sizeof(field.PreClosePrice));
	localmemcpy(field.PreOpenInterest, input->PreOpenInterest, sizeof(field.PreOpenInterest));
	localmemcpy(field.OpenPrice, input->OpenPrice, sizeof(field.OpenPrice));
	localmemcpy(field.HighestPrice, input->HighestPrice, sizeof(field.HighestPrice));
	localmemcpy(field.LowestPrice, input->LowestPrice, sizeof(field.LowestPrice));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.Turnover, input->Turnover, sizeof(field.Turnover));
	localmemcpy(field.OpenInterest, input->OpenInterest, sizeof(field.OpenInterest));
	localmemcpy(field.ClosePrice, input->ClosePrice, sizeof(field.ClosePrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.UpperLimitPrice, input->UpperLimitPrice, sizeof(field.UpperLimitPrice));
	localmemcpy(field.LowerLimitPrice, input->LowerLimitPrice, sizeof(field.LowerLimitPrice));
	localmemcpy(field.PreDelta, input->PreDelta, sizeof(field.PreDelta));
	localmemcpy(field.CurrDelta, input->CurrDelta, sizeof(field.CurrDelta));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.UpdateMillisec, input->UpdateMillisec, sizeof(field.UpdateMillisec));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataBaseField KStoCTPChange(KingstarAPI::CThostFtdcMarketDataBaseField *input)
{
	CTPTradeApi::CThostFtdcMarketDataBaseField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.PreClosePrice, input->PreClosePrice, sizeof(field.PreClosePrice));
	localmemcpy(field.PreOpenInterest, input->PreOpenInterest, sizeof(field.PreOpenInterest));
	localmemcpy(field.PreDelta, input->PreDelta, sizeof(field.PreDelta));
	return field;
}
KingstarAPI::CThostFtdcMarketDataBaseField CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataBaseField *input)
{
	KingstarAPI::CThostFtdcMarketDataBaseField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PreSettlementPrice, input->PreSettlementPrice, sizeof(field.PreSettlementPrice));
	localmemcpy(field.PreClosePrice, input->PreClosePrice, sizeof(field.PreClosePrice));
	localmemcpy(field.PreOpenInterest, input->PreOpenInterest, sizeof(field.PreOpenInterest));
	localmemcpy(field.PreDelta, input->PreDelta, sizeof(field.PreDelta));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataStaticField KStoCTPChange(KingstarAPI::CThostFtdcMarketDataStaticField *input)
{
	CTPTradeApi::CThostFtdcMarketDataStaticField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.OpenPrice, input->OpenPrice, sizeof(field.OpenPrice));
	localmemcpy(field.HighestPrice, input->HighestPrice, sizeof(field.HighestPrice));
	localmemcpy(field.LowestPrice, input->LowestPrice, sizeof(field.LowestPrice));
	localmemcpy(field.ClosePrice, input->ClosePrice, sizeof(field.ClosePrice));
	localmemcpy(field.UpperLimitPrice, input->UpperLimitPrice, sizeof(field.UpperLimitPrice));
	localmemcpy(field.LowerLimitPrice, input->LowerLimitPrice, sizeof(field.LowerLimitPrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.CurrDelta, input->CurrDelta, sizeof(field.CurrDelta));
	return field;
}
KingstarAPI::CThostFtdcMarketDataStaticField CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataStaticField *input)
{
	KingstarAPI::CThostFtdcMarketDataStaticField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.OpenPrice, input->OpenPrice, sizeof(field.OpenPrice));
	localmemcpy(field.HighestPrice, input->HighestPrice, sizeof(field.HighestPrice));
	localmemcpy(field.LowestPrice, input->LowestPrice, sizeof(field.LowestPrice));
	localmemcpy(field.ClosePrice, input->ClosePrice, sizeof(field.ClosePrice));
	localmemcpy(field.UpperLimitPrice, input->UpperLimitPrice, sizeof(field.UpperLimitPrice));
	localmemcpy(field.LowerLimitPrice, input->LowerLimitPrice, sizeof(field.LowerLimitPrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.CurrDelta, input->CurrDelta, sizeof(field.CurrDelta));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataLastMatchField KStoCTPChange(KingstarAPI::CThostFtdcMarketDataLastMatchField *input)
{
	CTPTradeApi::CThostFtdcMarketDataLastMatchField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.LastPrice, input->LastPrice, sizeof(field.LastPrice));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.Turnover, input->Turnover, sizeof(field.Turnover));
	localmemcpy(field.OpenInterest, input->OpenInterest, sizeof(field.OpenInterest));
	return field;
}
KingstarAPI::CThostFtdcMarketDataLastMatchField CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataLastMatchField *input)
{
	KingstarAPI::CThostFtdcMarketDataLastMatchField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.LastPrice, input->LastPrice, sizeof(field.LastPrice));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.Turnover, input->Turnover, sizeof(field.Turnover));
	localmemcpy(field.OpenInterest, input->OpenInterest, sizeof(field.OpenInterest));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataBestPriceField KStoCTPChange(KingstarAPI::CThostFtdcMarketDataBestPriceField *input)
{
	CTPTradeApi::CThostFtdcMarketDataBestPriceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BidPrice1, input->BidPrice1, sizeof(field.BidPrice1));
	localmemcpy(field.BidVolume1, input->BidVolume1, sizeof(field.BidVolume1));
	localmemcpy(field.AskPrice1, input->AskPrice1, sizeof(field.AskPrice1));
	localmemcpy(field.AskVolume1, input->AskVolume1, sizeof(field.AskVolume1));
	return field;
}
KingstarAPI::CThostFtdcMarketDataBestPriceField CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataBestPriceField *input)
{
	KingstarAPI::CThostFtdcMarketDataBestPriceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BidPrice1, input->BidPrice1, sizeof(field.BidPrice1));
	localmemcpy(field.BidVolume1, input->BidVolume1, sizeof(field.BidVolume1));
	localmemcpy(field.AskPrice1, input->AskPrice1, sizeof(field.AskPrice1));
	localmemcpy(field.AskVolume1, input->AskVolume1, sizeof(field.AskVolume1));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataBid23Field KStoCTPChange(KingstarAPI::CThostFtdcMarketDataBid23Field *input)
{
	CTPTradeApi::CThostFtdcMarketDataBid23Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BidPrice2, input->BidPrice2, sizeof(field.BidPrice2));
	localmemcpy(field.BidVolume2, input->BidVolume2, sizeof(field.BidVolume2));
	localmemcpy(field.BidPrice3, input->BidPrice3, sizeof(field.BidPrice3));
	localmemcpy(field.BidVolume3, input->BidVolume3, sizeof(field.BidVolume3));
	return field;
}
KingstarAPI::CThostFtdcMarketDataBid23Field CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataBid23Field *input)
{
	KingstarAPI::CThostFtdcMarketDataBid23Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BidPrice2, input->BidPrice2, sizeof(field.BidPrice2));
	localmemcpy(field.BidVolume2, input->BidVolume2, sizeof(field.BidVolume2));
	localmemcpy(field.BidPrice3, input->BidPrice3, sizeof(field.BidPrice3));
	localmemcpy(field.BidVolume3, input->BidVolume3, sizeof(field.BidVolume3));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataAsk23Field KStoCTPChange(KingstarAPI::CThostFtdcMarketDataAsk23Field *input)
{
	CTPTradeApi::CThostFtdcMarketDataAsk23Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.AskPrice2, input->AskPrice2, sizeof(field.AskPrice2));
	localmemcpy(field.AskVolume2, input->AskVolume2, sizeof(field.AskVolume2));
	localmemcpy(field.AskPrice3, input->AskPrice3, sizeof(field.AskPrice3));
	localmemcpy(field.AskVolume3, input->AskVolume3, sizeof(field.AskVolume3));
	return field;
}
KingstarAPI::CThostFtdcMarketDataAsk23Field CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataAsk23Field *input)
{
	KingstarAPI::CThostFtdcMarketDataAsk23Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.AskPrice2, input->AskPrice2, sizeof(field.AskPrice2));
	localmemcpy(field.AskVolume2, input->AskVolume2, sizeof(field.AskVolume2));
	localmemcpy(field.AskPrice3, input->AskPrice3, sizeof(field.AskPrice3));
	localmemcpy(field.AskVolume3, input->AskVolume3, sizeof(field.AskVolume3));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataBid45Field KStoCTPChange(KingstarAPI::CThostFtdcMarketDataBid45Field *input)
{
	CTPTradeApi::CThostFtdcMarketDataBid45Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BidPrice4, input->BidPrice4, sizeof(field.BidPrice4));
	localmemcpy(field.BidVolume4, input->BidVolume4, sizeof(field.BidVolume4));
	localmemcpy(field.BidPrice5, input->BidPrice5, sizeof(field.BidPrice5));
	localmemcpy(field.BidVolume5, input->BidVolume5, sizeof(field.BidVolume5));
	return field;
}
KingstarAPI::CThostFtdcMarketDataBid45Field CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataBid45Field *input)
{
	KingstarAPI::CThostFtdcMarketDataBid45Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BidPrice4, input->BidPrice4, sizeof(field.BidPrice4));
	localmemcpy(field.BidVolume4, input->BidVolume4, sizeof(field.BidVolume4));
	localmemcpy(field.BidPrice5, input->BidPrice5, sizeof(field.BidPrice5));
	localmemcpy(field.BidVolume5, input->BidVolume5, sizeof(field.BidVolume5));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataAsk45Field KStoCTPChange(KingstarAPI::CThostFtdcMarketDataAsk45Field *input)
{
	CTPTradeApi::CThostFtdcMarketDataAsk45Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.AskPrice4, input->AskPrice4, sizeof(field.AskPrice4));
	localmemcpy(field.AskVolume4, input->AskVolume4, sizeof(field.AskVolume4));
	localmemcpy(field.AskPrice5, input->AskPrice5, sizeof(field.AskPrice5));
	localmemcpy(field.AskVolume5, input->AskVolume5, sizeof(field.AskVolume5));
	return field;
}
KingstarAPI::CThostFtdcMarketDataAsk45Field CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataAsk45Field *input)
{
	KingstarAPI::CThostFtdcMarketDataAsk45Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.AskPrice4, input->AskPrice4, sizeof(field.AskPrice4));
	localmemcpy(field.AskVolume4, input->AskVolume4, sizeof(field.AskVolume4));
	localmemcpy(field.AskPrice5, input->AskPrice5, sizeof(field.AskPrice5));
	localmemcpy(field.AskVolume5, input->AskVolume5, sizeof(field.AskVolume5));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataUpdateTimeField KStoCTPChange(KingstarAPI::CThostFtdcMarketDataUpdateTimeField *input)
{
	CTPTradeApi::CThostFtdcMarketDataUpdateTimeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.UpdateMillisec, input->UpdateMillisec, sizeof(field.UpdateMillisec));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	return field;
}
KingstarAPI::CThostFtdcMarketDataUpdateTimeField CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataUpdateTimeField *input)
{
	KingstarAPI::CThostFtdcMarketDataUpdateTimeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.UpdateMillisec, input->UpdateMillisec, sizeof(field.UpdateMillisec));
	localmemcpy(field.ActionDay, input->ActionDay, sizeof(field.ActionDay));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataExchangeField KStoCTPChange(KingstarAPI::CThostFtdcMarketDataExchangeField *input)
{
	CTPTradeApi::CThostFtdcMarketDataExchangeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcMarketDataExchangeField CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataExchangeField *input)
{
	KingstarAPI::CThostFtdcMarketDataExchangeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcSpecificInstrumentField KStoCTPChange(KingstarAPI::CThostFtdcSpecificInstrumentField *input)
{
	CTPTradeApi::CThostFtdcSpecificInstrumentField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcSpecificInstrumentField CTPtoKSChange(CTPTradeApi::CThostFtdcSpecificInstrumentField *input)
{
	KingstarAPI::CThostFtdcSpecificInstrumentField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcInstrumentStatusField KStoCTPChange(KingstarAPI::CThostFtdcInstrumentStatusField *input)
{
	CTPTradeApi::CThostFtdcInstrumentStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.SettlementGroupID, input->SettlementGroupID, sizeof(field.SettlementGroupID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InstrumentStatus, input->InstrumentStatus, sizeof(field.InstrumentStatus));
	localmemcpy(field.TradingSegmentSN, input->TradingSegmentSN, sizeof(field.TradingSegmentSN));
	localmemcpy(field.EnterTime, input->EnterTime, sizeof(field.EnterTime));
	localmemcpy(field.EnterReason, input->EnterReason, sizeof(field.EnterReason));
	return field;
}
KingstarAPI::CThostFtdcInstrumentStatusField CTPtoKSChange(CTPTradeApi::CThostFtdcInstrumentStatusField *input)
{
	KingstarAPI::CThostFtdcInstrumentStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.SettlementGroupID, input->SettlementGroupID, sizeof(field.SettlementGroupID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.InstrumentStatus, input->InstrumentStatus, sizeof(field.InstrumentStatus));
	localmemcpy(field.TradingSegmentSN, input->TradingSegmentSN, sizeof(field.TradingSegmentSN));
	localmemcpy(field.EnterTime, input->EnterTime, sizeof(field.EnterTime));
	localmemcpy(field.EnterReason, input->EnterReason, sizeof(field.EnterReason));
	return field;
}
CTPTradeApi::CThostFtdcQryInstrumentStatusField KStoCTPChange(KingstarAPI::CThostFtdcQryInstrumentStatusField *input)
{
	CTPTradeApi::CThostFtdcQryInstrumentStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	return field;
}
KingstarAPI::CThostFtdcQryInstrumentStatusField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInstrumentStatusField *input)
{
	KingstarAPI::CThostFtdcQryInstrumentStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	return field;
}
CTPTradeApi::CThostFtdcInvestorAccountField KStoCTPChange(KingstarAPI::CThostFtdcInvestorAccountField *input)
{
	CTPTradeApi::CThostFtdcInvestorAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcInvestorAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcInvestorAccountField *input)
{
	KingstarAPI::CThostFtdcInvestorAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcPositionProfitAlgorithmField KStoCTPChange(KingstarAPI::CThostFtdcPositionProfitAlgorithmField *input)
{
	CTPTradeApi::CThostFtdcPositionProfitAlgorithmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Algorithm, input->Algorithm, sizeof(field.Algorithm));
	localmemcpy(field.Memo, input->Memo, sizeof(field.Memo));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcPositionProfitAlgorithmField CTPtoKSChange(CTPTradeApi::CThostFtdcPositionProfitAlgorithmField *input)
{
	KingstarAPI::CThostFtdcPositionProfitAlgorithmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Algorithm, input->Algorithm, sizeof(field.Algorithm));
	localmemcpy(field.Memo, input->Memo, sizeof(field.Memo));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcDiscountField KStoCTPChange(KingstarAPI::CThostFtdcDiscountField *input)
{
	CTPTradeApi::CThostFtdcDiscountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Discount, input->Discount, sizeof(field.Discount));
	return field;
}
KingstarAPI::CThostFtdcDiscountField CTPtoKSChange(CTPTradeApi::CThostFtdcDiscountField *input)
{
	KingstarAPI::CThostFtdcDiscountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Discount, input->Discount, sizeof(field.Discount));
	return field;
}
CTPTradeApi::CThostFtdcQryTransferBankField KStoCTPChange(KingstarAPI::CThostFtdcQryTransferBankField *input)
{
	CTPTradeApi::CThostFtdcQryTransferBankField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	return field;
}
KingstarAPI::CThostFtdcQryTransferBankField CTPtoKSChange(CTPTradeApi::CThostFtdcQryTransferBankField *input)
{
	KingstarAPI::CThostFtdcQryTransferBankField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	return field;
}
CTPTradeApi::CThostFtdcTransferBankField KStoCTPChange(KingstarAPI::CThostFtdcTransferBankField *input)
{
	CTPTradeApi::CThostFtdcTransferBankField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	localmemcpy(field.BankName, input->BankName, sizeof(field.BankName));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
KingstarAPI::CThostFtdcTransferBankField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferBankField *input)
{
	KingstarAPI::CThostFtdcTransferBankField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	localmemcpy(field.BankName, input->BankName, sizeof(field.BankName));
	localmemcpy(field.IsActive, input->IsActive, sizeof(field.IsActive));
	return field;
}
CTPTradeApi::CThostFtdcQryInvestorPositionDetailField KStoCTPChange(KingstarAPI::CThostFtdcQryInvestorPositionDetailField *input)
{
	CTPTradeApi::CThostFtdcQryInvestorPositionDetailField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryInvestorPositionDetailField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInvestorPositionDetailField *input)
{
	KingstarAPI::CThostFtdcQryInvestorPositionDetailField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcInvestorPositionDetailField KStoCTPChange(KingstarAPI::CThostFtdcInvestorPositionDetailField *input)
{
	CTPTradeApi::CThostFtdcInvestorPositionDetailField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.OpenPrice, input->OpenPrice, sizeof(field.OpenPrice));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.TradeType, input->TradeType, sizeof(field.TradeType));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.CloseProfitByDate, input->CloseProfitByDate, sizeof(field.CloseProfitByDate));
	localmemcpy(field.CloseProfitByTrade, input->CloseProfitByTrade, sizeof(field.CloseProfitByTrade));
	localmemcpy(field.PositionProfitByDate, input->PositionProfitByDate, sizeof(field.PositionProfitByDate));
	localmemcpy(field.PositionProfitByTrade, input->PositionProfitByTrade, sizeof(field.PositionProfitByTrade));
	localmemcpy(field.Margin, input->Margin, sizeof(field.Margin));
	localmemcpy(field.ExchMargin, input->ExchMargin, sizeof(field.ExchMargin));
	localmemcpy(field.MarginRateByMoney, input->MarginRateByMoney, sizeof(field.MarginRateByMoney));
	localmemcpy(field.MarginRateByVolume, input->MarginRateByVolume, sizeof(field.MarginRateByVolume));
	localmemcpy(field.LastSettlementPrice, input->LastSettlementPrice, sizeof(field.LastSettlementPrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.CloseVolume, input->CloseVolume, sizeof(field.CloseVolume));
	localmemcpy(field.CloseAmount, input->CloseAmount, sizeof(field.CloseAmount));
	return field;
}
KingstarAPI::CThostFtdcInvestorPositionDetailField CTPtoKSChange(CTPTradeApi::CThostFtdcInvestorPositionDetailField *input)
{
	KingstarAPI::CThostFtdcInvestorPositionDetailField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	localmemcpy(field.OpenPrice, input->OpenPrice, sizeof(field.OpenPrice));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.TradeType, input->TradeType, sizeof(field.TradeType));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.CloseProfitByDate, input->CloseProfitByDate, sizeof(field.CloseProfitByDate));
	localmemcpy(field.CloseProfitByTrade, input->CloseProfitByTrade, sizeof(field.CloseProfitByTrade));
	localmemcpy(field.PositionProfitByDate, input->PositionProfitByDate, sizeof(field.PositionProfitByDate));
	localmemcpy(field.PositionProfitByTrade, input->PositionProfitByTrade, sizeof(field.PositionProfitByTrade));
	localmemcpy(field.Margin, input->Margin, sizeof(field.Margin));
	localmemcpy(field.ExchMargin, input->ExchMargin, sizeof(field.ExchMargin));
	localmemcpy(field.MarginRateByMoney, input->MarginRateByMoney, sizeof(field.MarginRateByMoney));
	localmemcpy(field.MarginRateByVolume, input->MarginRateByVolume, sizeof(field.MarginRateByVolume));
	localmemcpy(field.LastSettlementPrice, input->LastSettlementPrice, sizeof(field.LastSettlementPrice));
	localmemcpy(field.SettlementPrice, input->SettlementPrice, sizeof(field.SettlementPrice));
	localmemcpy(field.CloseVolume, input->CloseVolume, sizeof(field.CloseVolume));
	localmemcpy(field.CloseAmount, input->CloseAmount, sizeof(field.CloseAmount));
	return field;
}
CTPTradeApi::CThostFtdcTradingAccountPasswordField KStoCTPChange(KingstarAPI::CThostFtdcTradingAccountPasswordField *input)
{
	CTPTradeApi::CThostFtdcTradingAccountPasswordField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcTradingAccountPasswordField CTPtoKSChange(CTPTradeApi::CThostFtdcTradingAccountPasswordField *input)
{
	KingstarAPI::CThostFtdcTradingAccountPasswordField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcMDTraderOfferField KStoCTPChange(KingstarAPI::CThostFtdcMDTraderOfferField *input)
{
	CTPTradeApi::CThostFtdcMDTraderOfferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.TraderConnectStatus, input->TraderConnectStatus, sizeof(field.TraderConnectStatus));
	localmemcpy(field.ConnectRequestDate, input->ConnectRequestDate, sizeof(field.ConnectRequestDate));
	localmemcpy(field.ConnectRequestTime, input->ConnectRequestTime, sizeof(field.ConnectRequestTime));
	localmemcpy(field.LastReportDate, input->LastReportDate, sizeof(field.LastReportDate));
	localmemcpy(field.LastReportTime, input->LastReportTime, sizeof(field.LastReportTime));
	localmemcpy(field.ConnectDate, input->ConnectDate, sizeof(field.ConnectDate));
	localmemcpy(field.ConnectTime, input->ConnectTime, sizeof(field.ConnectTime));
	localmemcpy(field.StartDate, input->StartDate, sizeof(field.StartDate));
	localmemcpy(field.StartTime, input->StartTime, sizeof(field.StartTime));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MaxTradeID, input->MaxTradeID, sizeof(field.MaxTradeID));
	localmemcpy(field.MaxOrderMessageReference, input->MaxOrderMessageReference, sizeof(field.MaxOrderMessageReference));
	return field;
}
KingstarAPI::CThostFtdcMDTraderOfferField CTPtoKSChange(CTPTradeApi::CThostFtdcMDTraderOfferField *input)
{
	KingstarAPI::CThostFtdcMDTraderOfferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.TraderConnectStatus, input->TraderConnectStatus, sizeof(field.TraderConnectStatus));
	localmemcpy(field.ConnectRequestDate, input->ConnectRequestDate, sizeof(field.ConnectRequestDate));
	localmemcpy(field.ConnectRequestTime, input->ConnectRequestTime, sizeof(field.ConnectRequestTime));
	localmemcpy(field.LastReportDate, input->LastReportDate, sizeof(field.LastReportDate));
	localmemcpy(field.LastReportTime, input->LastReportTime, sizeof(field.LastReportTime));
	localmemcpy(field.ConnectDate, input->ConnectDate, sizeof(field.ConnectDate));
	localmemcpy(field.ConnectTime, input->ConnectTime, sizeof(field.ConnectTime));
	localmemcpy(field.StartDate, input->StartDate, sizeof(field.StartDate));
	localmemcpy(field.StartTime, input->StartTime, sizeof(field.StartTime));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MaxTradeID, input->MaxTradeID, sizeof(field.MaxTradeID));
	localmemcpy(field.MaxOrderMessageReference, input->MaxOrderMessageReference, sizeof(field.MaxOrderMessageReference));
	return field;
}
CTPTradeApi::CThostFtdcQryMDTraderOfferField KStoCTPChange(KingstarAPI::CThostFtdcQryMDTraderOfferField *input)
{
	CTPTradeApi::CThostFtdcQryMDTraderOfferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
KingstarAPI::CThostFtdcQryMDTraderOfferField CTPtoKSChange(CTPTradeApi::CThostFtdcQryMDTraderOfferField *input)
{
	KingstarAPI::CThostFtdcQryMDTraderOfferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	return field;
}
CTPTradeApi::CThostFtdcQryNoticeField KStoCTPChange(KingstarAPI::CThostFtdcQryNoticeField *input)
{
	CTPTradeApi::CThostFtdcQryNoticeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
KingstarAPI::CThostFtdcQryNoticeField CTPtoKSChange(CTPTradeApi::CThostFtdcQryNoticeField *input)
{
	KingstarAPI::CThostFtdcQryNoticeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
CTPTradeApi::CThostFtdcNoticeField KStoCTPChange(KingstarAPI::CThostFtdcNoticeField *input)
{
	CTPTradeApi::CThostFtdcNoticeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.Content, input->Content, sizeof(field.Content));
	localmemcpy(field.SequenceLabel, input->SequenceLabel, sizeof(field.SequenceLabel));
	return field;
}
KingstarAPI::CThostFtdcNoticeField CTPtoKSChange(CTPTradeApi::CThostFtdcNoticeField *input)
{
	KingstarAPI::CThostFtdcNoticeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.Content, input->Content, sizeof(field.Content));
	localmemcpy(field.SequenceLabel, input->SequenceLabel, sizeof(field.SequenceLabel));
	return field;
}
CTPTradeApi::CThostFtdcUserRightField KStoCTPChange(KingstarAPI::CThostFtdcUserRightField *input)
{
	CTPTradeApi::CThostFtdcUserRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserRightType, input->UserRightType, sizeof(field.UserRightType));
	localmemcpy(field.IsForbidden, input->IsForbidden, sizeof(field.IsForbidden));
	return field;
}
KingstarAPI::CThostFtdcUserRightField CTPtoKSChange(CTPTradeApi::CThostFtdcUserRightField *input)
{
	KingstarAPI::CThostFtdcUserRightField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserRightType, input->UserRightType, sizeof(field.UserRightType));
	localmemcpy(field.IsForbidden, input->IsForbidden, sizeof(field.IsForbidden));
	return field;
}
CTPTradeApi::CThostFtdcQrySettlementInfoConfirmField KStoCTPChange(KingstarAPI::CThostFtdcQrySettlementInfoConfirmField *input)
{
	CTPTradeApi::CThostFtdcQrySettlementInfoConfirmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQrySettlementInfoConfirmField CTPtoKSChange(CTPTradeApi::CThostFtdcQrySettlementInfoConfirmField *input)
{
	KingstarAPI::CThostFtdcQrySettlementInfoConfirmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcLoadSettlementInfoField KStoCTPChange(KingstarAPI::CThostFtdcLoadSettlementInfoField *input)
{
	CTPTradeApi::CThostFtdcLoadSettlementInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
KingstarAPI::CThostFtdcLoadSettlementInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcLoadSettlementInfoField *input)
{
	KingstarAPI::CThostFtdcLoadSettlementInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
CTPTradeApi::CThostFtdcBrokerWithdrawAlgorithmField KStoCTPChange(KingstarAPI::CThostFtdcBrokerWithdrawAlgorithmField *input)
{
	CTPTradeApi::CThostFtdcBrokerWithdrawAlgorithmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.WithdrawAlgorithm, input->WithdrawAlgorithm, sizeof(field.WithdrawAlgorithm));
	localmemcpy(field.UsingRatio, input->UsingRatio, sizeof(field.UsingRatio));
	localmemcpy(field.IncludeCloseProfit, input->IncludeCloseProfit, sizeof(field.IncludeCloseProfit));
	localmemcpy(field.AllWithoutTrade, input->AllWithoutTrade, sizeof(field.AllWithoutTrade));
	localmemcpy(field.AvailIncludeCloseProfit, input->AvailIncludeCloseProfit, sizeof(field.AvailIncludeCloseProfit));
	localmemcpy(field.IsBrokerUserEvent, input->IsBrokerUserEvent, sizeof(field.IsBrokerUserEvent));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.FundMortgageRatio, input->FundMortgageRatio, sizeof(field.FundMortgageRatio));
	localmemcpy(field.BalanceAlgorithm, input->BalanceAlgorithm, sizeof(field.BalanceAlgorithm));
	return field;
}
KingstarAPI::CThostFtdcBrokerWithdrawAlgorithmField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerWithdrawAlgorithmField *input)
{
	KingstarAPI::CThostFtdcBrokerWithdrawAlgorithmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.WithdrawAlgorithm, input->WithdrawAlgorithm, sizeof(field.WithdrawAlgorithm));
	localmemcpy(field.UsingRatio, input->UsingRatio, sizeof(field.UsingRatio));
	localmemcpy(field.IncludeCloseProfit, input->IncludeCloseProfit, sizeof(field.IncludeCloseProfit));
	localmemcpy(field.AllWithoutTrade, input->AllWithoutTrade, sizeof(field.AllWithoutTrade));
	localmemcpy(field.AvailIncludeCloseProfit, input->AvailIncludeCloseProfit, sizeof(field.AvailIncludeCloseProfit));
	localmemcpy(field.IsBrokerUserEvent, input->IsBrokerUserEvent, sizeof(field.IsBrokerUserEvent));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.FundMortgageRatio, input->FundMortgageRatio, sizeof(field.FundMortgageRatio));
	localmemcpy(field.BalanceAlgorithm, input->BalanceAlgorithm, sizeof(field.BalanceAlgorithm));
	return field;
}
CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateV1Field KStoCTPChange(KingstarAPI::CThostFtdcTradingAccountPasswordUpdateV1Field *input)
{
	CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateV1Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OldPassword, input->OldPassword, sizeof(field.OldPassword));
	localmemcpy(field.NewPassword, input->NewPassword, sizeof(field.NewPassword));
	return field;
}
KingstarAPI::CThostFtdcTradingAccountPasswordUpdateV1Field CTPtoKSChange(CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateV1Field *input)
{
	KingstarAPI::CThostFtdcTradingAccountPasswordUpdateV1Field field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OldPassword, input->OldPassword, sizeof(field.OldPassword));
	localmemcpy(field.NewPassword, input->NewPassword, sizeof(field.NewPassword));
	return field;
}
CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateField KStoCTPChange(KingstarAPI::CThostFtdcTradingAccountPasswordUpdateField *input)
{
	CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.OldPassword, input->OldPassword, sizeof(field.OldPassword));
	localmemcpy(field.NewPassword, input->NewPassword, sizeof(field.NewPassword));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcTradingAccountPasswordUpdateField CTPtoKSChange(CTPTradeApi::CThostFtdcTradingAccountPasswordUpdateField *input)
{
	KingstarAPI::CThostFtdcTradingAccountPasswordUpdateField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.OldPassword, input->OldPassword, sizeof(field.OldPassword));
	localmemcpy(field.NewPassword, input->NewPassword, sizeof(field.NewPassword));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcQryCombinationLegField KStoCTPChange(KingstarAPI::CThostFtdcQryCombinationLegField *input)
{
	CTPTradeApi::CThostFtdcQryCombinationLegField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	localmemcpy(field.LegID, input->LegID, sizeof(field.LegID));
	localmemcpy(field.LegInstrumentID, input->LegInstrumentID, sizeof(field.LegInstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryCombinationLegField CTPtoKSChange(CTPTradeApi::CThostFtdcQryCombinationLegField *input)
{
	KingstarAPI::CThostFtdcQryCombinationLegField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	localmemcpy(field.LegID, input->LegID, sizeof(field.LegID));
	localmemcpy(field.LegInstrumentID, input->LegInstrumentID, sizeof(field.LegInstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQrySyncStatusField KStoCTPChange(KingstarAPI::CThostFtdcQrySyncStatusField *input)
{
	CTPTradeApi::CThostFtdcQrySyncStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	return field;
}
KingstarAPI::CThostFtdcQrySyncStatusField CTPtoKSChange(CTPTradeApi::CThostFtdcQrySyncStatusField *input)
{
	KingstarAPI::CThostFtdcQrySyncStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	return field;
}
CTPTradeApi::CThostFtdcCombinationLegField KStoCTPChange(KingstarAPI::CThostFtdcCombinationLegField *input)
{
	CTPTradeApi::CThostFtdcCombinationLegField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	localmemcpy(field.LegID, input->LegID, sizeof(field.LegID));
	localmemcpy(field.LegInstrumentID, input->LegInstrumentID, sizeof(field.LegInstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.LegMultiple, input->LegMultiple, sizeof(field.LegMultiple));
	localmemcpy(field.ImplyLevel, input->ImplyLevel, sizeof(field.ImplyLevel));
	return field;
}
KingstarAPI::CThostFtdcCombinationLegField CTPtoKSChange(CTPTradeApi::CThostFtdcCombinationLegField *input)
{
	KingstarAPI::CThostFtdcCombinationLegField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	localmemcpy(field.LegID, input->LegID, sizeof(field.LegID));
	localmemcpy(field.LegInstrumentID, input->LegInstrumentID, sizeof(field.LegInstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.LegMultiple, input->LegMultiple, sizeof(field.LegMultiple));
	localmemcpy(field.ImplyLevel, input->ImplyLevel, sizeof(field.ImplyLevel));
	return field;
}
CTPTradeApi::CThostFtdcSyncStatusField KStoCTPChange(KingstarAPI::CThostFtdcSyncStatusField *input)
{
	CTPTradeApi::CThostFtdcSyncStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.DataSyncStatus, input->DataSyncStatus, sizeof(field.DataSyncStatus));
	return field;
}
KingstarAPI::CThostFtdcSyncStatusField CTPtoKSChange(CTPTradeApi::CThostFtdcSyncStatusField *input)
{
	KingstarAPI::CThostFtdcSyncStatusField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.DataSyncStatus, input->DataSyncStatus, sizeof(field.DataSyncStatus));
	return field;
}
CTPTradeApi::CThostFtdcQryLinkManField KStoCTPChange(KingstarAPI::CThostFtdcQryLinkManField *input)
{
	CTPTradeApi::CThostFtdcQryLinkManField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQryLinkManField CTPtoKSChange(CTPTradeApi::CThostFtdcQryLinkManField *input)
{
	KingstarAPI::CThostFtdcQryLinkManField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcLinkManField KStoCTPChange(KingstarAPI::CThostFtdcLinkManField *input)
{
	CTPTradeApi::CThostFtdcLinkManField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.PersonType, input->PersonType, sizeof(field.PersonType));
	localmemcpy(field.IdentifiedCardType, input->IdentifiedCardType, sizeof(field.IdentifiedCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.PersonName, input->PersonName, sizeof(field.PersonName));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Priority, input->Priority, sizeof(field.Priority));
	localmemcpy(field.UOAZipCode, input->UOAZipCode, sizeof(field.UOAZipCode));
	localmemcpy(field.PersonFullName, input->PersonFullName, sizeof(field.PersonFullName));
	return field;
}
KingstarAPI::CThostFtdcLinkManField CTPtoKSChange(CTPTradeApi::CThostFtdcLinkManField *input)
{
	KingstarAPI::CThostFtdcLinkManField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.PersonType, input->PersonType, sizeof(field.PersonType));
	localmemcpy(field.IdentifiedCardType, input->IdentifiedCardType, sizeof(field.IdentifiedCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.PersonName, input->PersonName, sizeof(field.PersonName));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Priority, input->Priority, sizeof(field.Priority));
	localmemcpy(field.UOAZipCode, input->UOAZipCode, sizeof(field.UOAZipCode));
	localmemcpy(field.PersonFullName, input->PersonFullName, sizeof(field.PersonFullName));
	return field;
}
CTPTradeApi::CThostFtdcQryBrokerUserEventField KStoCTPChange(KingstarAPI::CThostFtdcQryBrokerUserEventField *input)
{
	CTPTradeApi::CThostFtdcQryBrokerUserEventField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserEventType, input->UserEventType, sizeof(field.UserEventType));
	return field;
}
KingstarAPI::CThostFtdcQryBrokerUserEventField CTPtoKSChange(CTPTradeApi::CThostFtdcQryBrokerUserEventField *input)
{
	KingstarAPI::CThostFtdcQryBrokerUserEventField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserEventType, input->UserEventType, sizeof(field.UserEventType));
	return field;
}
CTPTradeApi::CThostFtdcBrokerUserEventField KStoCTPChange(KingstarAPI::CThostFtdcBrokerUserEventField *input)
{
	CTPTradeApi::CThostFtdcBrokerUserEventField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserEventType, input->UserEventType, sizeof(field.UserEventType));
	localmemcpy(field.EventSequenceNo, input->EventSequenceNo, sizeof(field.EventSequenceNo));
	localmemcpy(field.EventDate, input->EventDate, sizeof(field.EventDate));
	localmemcpy(field.EventTime, input->EventTime, sizeof(field.EventTime));
	localmemcpy(field.UserEventInfo, input->UserEventInfo, sizeof(field.UserEventInfo));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcBrokerUserEventField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerUserEventField *input)
{
	KingstarAPI::CThostFtdcBrokerUserEventField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.UserEventType, input->UserEventType, sizeof(field.UserEventType));
	localmemcpy(field.EventSequenceNo, input->EventSequenceNo, sizeof(field.EventSequenceNo));
	localmemcpy(field.EventDate, input->EventDate, sizeof(field.EventDate));
	localmemcpy(field.EventTime, input->EventTime, sizeof(field.EventTime));
	localmemcpy(field.UserEventInfo, input->UserEventInfo, sizeof(field.UserEventInfo));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQryContractBankField KStoCTPChange(KingstarAPI::CThostFtdcQryContractBankField *input)
{
	CTPTradeApi::CThostFtdcQryContractBankField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	return field;
}
KingstarAPI::CThostFtdcQryContractBankField CTPtoKSChange(CTPTradeApi::CThostFtdcQryContractBankField *input)
{
	KingstarAPI::CThostFtdcQryContractBankField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	return field;
}
CTPTradeApi::CThostFtdcContractBankField KStoCTPChange(KingstarAPI::CThostFtdcContractBankField *input)
{
	CTPTradeApi::CThostFtdcContractBankField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	localmemcpy(field.BankName, input->BankName, sizeof(field.BankName));
	return field;
}
KingstarAPI::CThostFtdcContractBankField CTPtoKSChange(CTPTradeApi::CThostFtdcContractBankField *input)
{
	KingstarAPI::CThostFtdcContractBankField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBrchID, input->BankBrchID, sizeof(field.BankBrchID));
	localmemcpy(field.BankName, input->BankName, sizeof(field.BankName));
	return field;
}
CTPTradeApi::CThostFtdcInvestorPositionCombineDetailField KStoCTPChange(KingstarAPI::CThostFtdcInvestorPositionCombineDetailField *input)
{
	CTPTradeApi::CThostFtdcInvestorPositionCombineDetailField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ComTradeID, input->ComTradeID, sizeof(field.ComTradeID));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.TotalAmt, input->TotalAmt, sizeof(field.TotalAmt));
	localmemcpy(field.Margin, input->Margin, sizeof(field.Margin));
	localmemcpy(field.ExchMargin, input->ExchMargin, sizeof(field.ExchMargin));
	localmemcpy(field.MarginRateByMoney, input->MarginRateByMoney, sizeof(field.MarginRateByMoney));
	localmemcpy(field.MarginRateByVolume, input->MarginRateByVolume, sizeof(field.MarginRateByVolume));
	localmemcpy(field.LegID, input->LegID, sizeof(field.LegID));
	localmemcpy(field.LegMultiple, input->LegMultiple, sizeof(field.LegMultiple));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	localmemcpy(field.TradeGroupID, input->TradeGroupID, sizeof(field.TradeGroupID));
	return field;
}
KingstarAPI::CThostFtdcInvestorPositionCombineDetailField CTPtoKSChange(CTPTradeApi::CThostFtdcInvestorPositionCombineDetailField *input)
{
	KingstarAPI::CThostFtdcInvestorPositionCombineDetailField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.OpenDate, input->OpenDate, sizeof(field.OpenDate));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ComTradeID, input->ComTradeID, sizeof(field.ComTradeID));
	localmemcpy(field.TradeID, input->TradeID, sizeof(field.TradeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.TotalAmt, input->TotalAmt, sizeof(field.TotalAmt));
	localmemcpy(field.Margin, input->Margin, sizeof(field.Margin));
	localmemcpy(field.ExchMargin, input->ExchMargin, sizeof(field.ExchMargin));
	localmemcpy(field.MarginRateByMoney, input->MarginRateByMoney, sizeof(field.MarginRateByMoney));
	localmemcpy(field.MarginRateByVolume, input->MarginRateByVolume, sizeof(field.MarginRateByVolume));
	localmemcpy(field.LegID, input->LegID, sizeof(field.LegID));
	localmemcpy(field.LegMultiple, input->LegMultiple, sizeof(field.LegMultiple));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	localmemcpy(field.TradeGroupID, input->TradeGroupID, sizeof(field.TradeGroupID));
	return field;
}
CTPTradeApi::CThostFtdcParkedOrderField KStoCTPChange(KingstarAPI::CThostFtdcParkedOrderField *input)
{
	CTPTradeApi::CThostFtdcParkedOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParkedOrderID, input->ParkedOrderID, sizeof(field.ParkedOrderID));
	localmemcpy(field.UserType, input->UserType, sizeof(field.UserType));
	localmemcpy(field.Status, input->Status, sizeof(field.Status));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
KingstarAPI::CThostFtdcParkedOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcParkedOrderField *input)
{
	KingstarAPI::CThostFtdcParkedOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParkedOrderID, input->ParkedOrderID, sizeof(field.ParkedOrderID));
	localmemcpy(field.UserType, input->UserType, sizeof(field.UserType));
	localmemcpy(field.Status, input->Status, sizeof(field.Status));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
CTPTradeApi::CThostFtdcParkedOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcParkedOrderActionField *input)
{
	CTPTradeApi::CThostFtdcParkedOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OrderActionRef, input->OrderActionRef, sizeof(field.OrderActionRef));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ParkedOrderActionID, input->ParkedOrderActionID, sizeof(field.ParkedOrderActionID));
	localmemcpy(field.UserType, input->UserType, sizeof(field.UserType));
	localmemcpy(field.Status, input->Status, sizeof(field.Status));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcParkedOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcParkedOrderActionField *input)
{
	KingstarAPI::CThostFtdcParkedOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OrderActionRef, input->OrderActionRef, sizeof(field.OrderActionRef));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ParkedOrderActionID, input->ParkedOrderActionID, sizeof(field.ParkedOrderActionID));
	localmemcpy(field.UserType, input->UserType, sizeof(field.UserType));
	localmemcpy(field.Status, input->Status, sizeof(field.Status));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcQryParkedOrderField KStoCTPChange(KingstarAPI::CThostFtdcQryParkedOrderField *input)
{
	CTPTradeApi::CThostFtdcQryParkedOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcQryParkedOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryParkedOrderField *input)
{
	KingstarAPI::CThostFtdcQryParkedOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcQryParkedOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcQryParkedOrderActionField *input)
{
	CTPTradeApi::CThostFtdcQryParkedOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcQryParkedOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryParkedOrderActionField *input)
{
	KingstarAPI::CThostFtdcQryParkedOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcRemoveParkedOrderField KStoCTPChange(KingstarAPI::CThostFtdcRemoveParkedOrderField *input)
{
	CTPTradeApi::CThostFtdcRemoveParkedOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ParkedOrderID, input->ParkedOrderID, sizeof(field.ParkedOrderID));
	return field;
}
KingstarAPI::CThostFtdcRemoveParkedOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcRemoveParkedOrderField *input)
{
	KingstarAPI::CThostFtdcRemoveParkedOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ParkedOrderID, input->ParkedOrderID, sizeof(field.ParkedOrderID));
	return field;
}
CTPTradeApi::CThostFtdcRemoveParkedOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcRemoveParkedOrderActionField *input)
{
	CTPTradeApi::CThostFtdcRemoveParkedOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ParkedOrderActionID, input->ParkedOrderActionID, sizeof(field.ParkedOrderActionID));
	return field;
}
KingstarAPI::CThostFtdcRemoveParkedOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcRemoveParkedOrderActionField *input)
{
	KingstarAPI::CThostFtdcRemoveParkedOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ParkedOrderActionID, input->ParkedOrderActionID, sizeof(field.ParkedOrderActionID));
	return field;
}
CTPTradeApi::CThostFtdcInvestorWithdrawAlgorithmField KStoCTPChange(KingstarAPI::CThostFtdcInvestorWithdrawAlgorithmField *input)
{
	CTPTradeApi::CThostFtdcInvestorWithdrawAlgorithmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.UsingRatio, input->UsingRatio, sizeof(field.UsingRatio));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.FundMortgageRatio, input->FundMortgageRatio, sizeof(field.FundMortgageRatio));
	return field;
}
KingstarAPI::CThostFtdcInvestorWithdrawAlgorithmField CTPtoKSChange(CTPTradeApi::CThostFtdcInvestorWithdrawAlgorithmField *input)
{
	KingstarAPI::CThostFtdcInvestorWithdrawAlgorithmField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.UsingRatio, input->UsingRatio, sizeof(field.UsingRatio));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.FundMortgageRatio, input->FundMortgageRatio, sizeof(field.FundMortgageRatio));
	return field;
}
CTPTradeApi::CThostFtdcQryInvestorPositionCombineDetailField KStoCTPChange(KingstarAPI::CThostFtdcQryInvestorPositionCombineDetailField *input)
{
	CTPTradeApi::CThostFtdcQryInvestorPositionCombineDetailField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryInvestorPositionCombineDetailField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInvestorPositionCombineDetailField *input)
{
	KingstarAPI::CThostFtdcQryInvestorPositionCombineDetailField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.CombInstrumentID, input->CombInstrumentID, sizeof(field.CombInstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcMarketDataAveragePriceField KStoCTPChange(KingstarAPI::CThostFtdcMarketDataAveragePriceField *input)
{
	CTPTradeApi::CThostFtdcMarketDataAveragePriceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.AveragePrice, input->AveragePrice, sizeof(field.AveragePrice));
	return field;
}
KingstarAPI::CThostFtdcMarketDataAveragePriceField CTPtoKSChange(CTPTradeApi::CThostFtdcMarketDataAveragePriceField *input)
{
	KingstarAPI::CThostFtdcMarketDataAveragePriceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.AveragePrice, input->AveragePrice, sizeof(field.AveragePrice));
	return field;
}
CTPTradeApi::CThostFtdcVerifyInvestorPasswordField KStoCTPChange(KingstarAPI::CThostFtdcVerifyInvestorPasswordField *input)
{
	CTPTradeApi::CThostFtdcVerifyInvestorPasswordField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	return field;
}
KingstarAPI::CThostFtdcVerifyInvestorPasswordField CTPtoKSChange(CTPTradeApi::CThostFtdcVerifyInvestorPasswordField *input)
{
	KingstarAPI::CThostFtdcVerifyInvestorPasswordField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	return field;
}
CTPTradeApi::CThostFtdcUserIPField KStoCTPChange(KingstarAPI::CThostFtdcUserIPField *input)
{
	CTPTradeApi::CThostFtdcUserIPField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.IPAddress, input->IPAddress, sizeof(field.IPAddress));
	localmemcpy(field.IPMask, input->IPMask, sizeof(field.IPMask));
	localmemcpy(field.MacAddress, input->MacAddress, sizeof(field.MacAddress));
	return field;
}
KingstarAPI::CThostFtdcUserIPField CTPtoKSChange(CTPTradeApi::CThostFtdcUserIPField *input)
{
	KingstarAPI::CThostFtdcUserIPField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.IPAddress, input->IPAddress, sizeof(field.IPAddress));
	localmemcpy(field.IPMask, input->IPMask, sizeof(field.IPMask));
	localmemcpy(field.MacAddress, input->MacAddress, sizeof(field.MacAddress));
	return field;
}
CTPTradeApi::CThostFtdcTradingNoticeInfoField KStoCTPChange(KingstarAPI::CThostFtdcTradingNoticeInfoField *input)
{
	CTPTradeApi::CThostFtdcTradingNoticeInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.SendTime, input->SendTime, sizeof(field.SendTime));
	localmemcpy(field.FieldContent, input->FieldContent, sizeof(field.FieldContent));
	localmemcpy(field.SequenceSeries, input->SequenceSeries, sizeof(field.SequenceSeries));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	return field;
}
KingstarAPI::CThostFtdcTradingNoticeInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcTradingNoticeInfoField *input)
{
	KingstarAPI::CThostFtdcTradingNoticeInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.SendTime, input->SendTime, sizeof(field.SendTime));
	localmemcpy(field.FieldContent, input->FieldContent, sizeof(field.FieldContent));
	localmemcpy(field.SequenceSeries, input->SequenceSeries, sizeof(field.SequenceSeries));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	return field;
}
CTPTradeApi::CThostFtdcTradingNoticeField KStoCTPChange(KingstarAPI::CThostFtdcTradingNoticeField *input)
{
	CTPTradeApi::CThostFtdcTradingNoticeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.SequenceSeries, input->SequenceSeries, sizeof(field.SequenceSeries));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.SendTime, input->SendTime, sizeof(field.SendTime));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.FieldContent, input->FieldContent, sizeof(field.FieldContent));
	return field;
}
KingstarAPI::CThostFtdcTradingNoticeField CTPtoKSChange(CTPTradeApi::CThostFtdcTradingNoticeField *input)
{
	KingstarAPI::CThostFtdcTradingNoticeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorRange, input->InvestorRange, sizeof(field.InvestorRange));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.SequenceSeries, input->SequenceSeries, sizeof(field.SequenceSeries));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.SendTime, input->SendTime, sizeof(field.SendTime));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.FieldContent, input->FieldContent, sizeof(field.FieldContent));
	return field;
}
CTPTradeApi::CThostFtdcQryTradingNoticeField KStoCTPChange(KingstarAPI::CThostFtdcQryTradingNoticeField *input)
{
	CTPTradeApi::CThostFtdcQryTradingNoticeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQryTradingNoticeField CTPtoKSChange(CTPTradeApi::CThostFtdcQryTradingNoticeField *input)
{
	KingstarAPI::CThostFtdcQryTradingNoticeField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcQryErrOrderField KStoCTPChange(KingstarAPI::CThostFtdcQryErrOrderField *input)
{
	CTPTradeApi::CThostFtdcQryErrOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQryErrOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcQryErrOrderField *input)
{
	KingstarAPI::CThostFtdcQryErrOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcErrOrderField KStoCTPChange(KingstarAPI::CThostFtdcErrOrderField *input)
{
	CTPTradeApi::CThostFtdcErrOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
KingstarAPI::CThostFtdcErrOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcErrOrderField *input)
{
	KingstarAPI::CThostFtdcErrOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
CTPTradeApi::CThostFtdcErrorConditionalOrderField KStoCTPChange(KingstarAPI::CThostFtdcErrorConditionalOrderField *input)
{
	CTPTradeApi::CThostFtdcErrorConditionalOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.OrderSource, input->OrderSource, sizeof(field.OrderSource));
	localmemcpy(field.OrderStatus, input->OrderStatus, sizeof(field.OrderStatus));
	localmemcpy(field.OrderType, input->OrderType, sizeof(field.OrderType));
	localmemcpy(field.VolumeTraded, input->VolumeTraded, sizeof(field.VolumeTraded));
	localmemcpy(field.VolumeTotal, input->VolumeTotal, sizeof(field.VolumeTotal));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ActiveTime, input->ActiveTime, sizeof(field.ActiveTime));
	localmemcpy(field.SuspendTime, input->SuspendTime, sizeof(field.SuspendTime));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ActiveTraderID, input->ActiveTraderID, sizeof(field.ActiveTraderID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerOrderSeq, input->BrokerOrderSeq, sizeof(field.BrokerOrderSeq));
	localmemcpy(field.RelativeOrderSysID, input->RelativeOrderSysID, sizeof(field.RelativeOrderSysID));
	localmemcpy(field.ZCETotalTradedVolume, input->ZCETotalTradedVolume, sizeof(field.ZCETotalTradedVolume));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
KingstarAPI::CThostFtdcErrorConditionalOrderField CTPtoKSChange(CTPTradeApi::CThostFtdcErrorConditionalOrderField *input)
{
	KingstarAPI::CThostFtdcErrorConditionalOrderField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OrderPriceType, input->OrderPriceType, sizeof(field.OrderPriceType));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.CombOffsetFlag, input->CombOffsetFlag, sizeof(field.CombOffsetFlag));
	localmemcpy(field.CombHedgeFlag, input->CombHedgeFlag, sizeof(field.CombHedgeFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeTotalOriginal, input->VolumeTotalOriginal, sizeof(field.VolumeTotalOriginal));
	localmemcpy(field.TimeCondition, input->TimeCondition, sizeof(field.TimeCondition));
	localmemcpy(field.GTDDate, input->GTDDate, sizeof(field.GTDDate));
	localmemcpy(field.VolumeCondition, input->VolumeCondition, sizeof(field.VolumeCondition));
	localmemcpy(field.MinVolume, input->MinVolume, sizeof(field.MinVolume));
	localmemcpy(field.ContingentCondition, input->ContingentCondition, sizeof(field.ContingentCondition));
	localmemcpy(field.StopPrice, input->StopPrice, sizeof(field.StopPrice));
	localmemcpy(field.ForceCloseReason, input->ForceCloseReason, sizeof(field.ForceCloseReason));
	localmemcpy(field.IsAutoSuspend, input->IsAutoSuspend, sizeof(field.IsAutoSuspend));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.ExchangeInstID, input->ExchangeInstID, sizeof(field.ExchangeInstID));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderSubmitStatus, input->OrderSubmitStatus, sizeof(field.OrderSubmitStatus));
	localmemcpy(field.NotifySequence, input->NotifySequence, sizeof(field.NotifySequence));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.OrderSource, input->OrderSource, sizeof(field.OrderSource));
	localmemcpy(field.OrderStatus, input->OrderStatus, sizeof(field.OrderStatus));
	localmemcpy(field.OrderType, input->OrderType, sizeof(field.OrderType));
	localmemcpy(field.VolumeTraded, input->VolumeTraded, sizeof(field.VolumeTraded));
	localmemcpy(field.VolumeTotal, input->VolumeTotal, sizeof(field.VolumeTotal));
	localmemcpy(field.InsertDate, input->InsertDate, sizeof(field.InsertDate));
	localmemcpy(field.InsertTime, input->InsertTime, sizeof(field.InsertTime));
	localmemcpy(field.ActiveTime, input->ActiveTime, sizeof(field.ActiveTime));
	localmemcpy(field.SuspendTime, input->SuspendTime, sizeof(field.SuspendTime));
	localmemcpy(field.UpdateTime, input->UpdateTime, sizeof(field.UpdateTime));
	localmemcpy(field.CancelTime, input->CancelTime, sizeof(field.CancelTime));
	localmemcpy(field.ActiveTraderID, input->ActiveTraderID, sizeof(field.ActiveTraderID));
	localmemcpy(field.ClearingPartID, input->ClearingPartID, sizeof(field.ClearingPartID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.UserProductInfo, input->UserProductInfo, sizeof(field.UserProductInfo));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.UserForceClose, input->UserForceClose, sizeof(field.UserForceClose));
	localmemcpy(field.ActiveUserID, input->ActiveUserID, sizeof(field.ActiveUserID));
	localmemcpy(field.BrokerOrderSeq, input->BrokerOrderSeq, sizeof(field.BrokerOrderSeq));
	localmemcpy(field.RelativeOrderSysID, input->RelativeOrderSysID, sizeof(field.RelativeOrderSysID));
	localmemcpy(field.ZCETotalTradedVolume, input->ZCETotalTradedVolume, sizeof(field.ZCETotalTradedVolume));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.IsSwapOrder, input->IsSwapOrder, sizeof(field.IsSwapOrder));
	return field;
}
CTPTradeApi::CThostFtdcQryErrOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcQryErrOrderActionField *input)
{
	CTPTradeApi::CThostFtdcQryErrOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQryErrOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcQryErrOrderActionField *input)
{
	KingstarAPI::CThostFtdcQryErrOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcErrOrderActionField KStoCTPChange(KingstarAPI::CThostFtdcErrOrderActionField *input)
{
	CTPTradeApi::CThostFtdcErrOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OrderActionRef, input->OrderActionRef, sizeof(field.OrderActionRef));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcErrOrderActionField CTPtoKSChange(CTPTradeApi::CThostFtdcErrOrderActionField *input)
{
	KingstarAPI::CThostFtdcErrOrderActionField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.OrderActionRef, input->OrderActionRef, sizeof(field.OrderActionRef));
	localmemcpy(field.OrderRef, input->OrderRef, sizeof(field.OrderRef));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.FrontID, input->FrontID, sizeof(field.FrontID));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.OrderSysID, input->OrderSysID, sizeof(field.OrderSysID));
	localmemcpy(field.ActionFlag, input->ActionFlag, sizeof(field.ActionFlag));
	localmemcpy(field.LimitPrice, input->LimitPrice, sizeof(field.LimitPrice));
	localmemcpy(field.VolumeChange, input->VolumeChange, sizeof(field.VolumeChange));
	localmemcpy(field.ActionDate, input->ActionDate, sizeof(field.ActionDate));
	localmemcpy(field.ActionTime, input->ActionTime, sizeof(field.ActionTime));
	localmemcpy(field.TraderID, input->TraderID, sizeof(field.TraderID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.OrderLocalID, input->OrderLocalID, sizeof(field.OrderLocalID));
	localmemcpy(field.ActionLocalID, input->ActionLocalID, sizeof(field.ActionLocalID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ClientID, input->ClientID, sizeof(field.ClientID));
	localmemcpy(field.BusinessUnit, input->BusinessUnit, sizeof(field.BusinessUnit));
	localmemcpy(field.OrderActionStatus, input->OrderActionStatus, sizeof(field.OrderActionStatus));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.StatusMsg, input->StatusMsg, sizeof(field.StatusMsg));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcQryExchangeSequenceField KStoCTPChange(KingstarAPI::CThostFtdcQryExchangeSequenceField *input)
{
	CTPTradeApi::CThostFtdcQryExchangeSequenceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcQryExchangeSequenceField CTPtoKSChange(CTPTradeApi::CThostFtdcQryExchangeSequenceField *input)
{
	KingstarAPI::CThostFtdcQryExchangeSequenceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcExchangeSequenceField KStoCTPChange(KingstarAPI::CThostFtdcExchangeSequenceField *input)
{
	CTPTradeApi::CThostFtdcExchangeSequenceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.MarketStatus, input->MarketStatus, sizeof(field.MarketStatus));
	return field;
}
KingstarAPI::CThostFtdcExchangeSequenceField CTPtoKSChange(CTPTradeApi::CThostFtdcExchangeSequenceField *input)
{
	KingstarAPI::CThostFtdcExchangeSequenceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.SequenceNo, input->SequenceNo, sizeof(field.SequenceNo));
	localmemcpy(field.MarketStatus, input->MarketStatus, sizeof(field.MarketStatus));
	return field;
}
CTPTradeApi::CThostFtdcQueryMaxOrderVolumeWithPriceField KStoCTPChange(KingstarAPI::CThostFtdcQueryMaxOrderVolumeWithPriceField *input)
{
	CTPTradeApi::CThostFtdcQueryMaxOrderVolumeWithPriceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.MaxVolume, input->MaxVolume, sizeof(field.MaxVolume));
	localmemcpy(field.Price, input->Price, sizeof(field.Price));
	return field;
}
KingstarAPI::CThostFtdcQueryMaxOrderVolumeWithPriceField CTPtoKSChange(CTPTradeApi::CThostFtdcQueryMaxOrderVolumeWithPriceField *input)
{
	KingstarAPI::CThostFtdcQueryMaxOrderVolumeWithPriceField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.OffsetFlag, input->OffsetFlag, sizeof(field.OffsetFlag));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.MaxVolume, input->MaxVolume, sizeof(field.MaxVolume));
	localmemcpy(field.Price, input->Price, sizeof(field.Price));
	return field;
}
CTPTradeApi::CThostFtdcQryBrokerTradingParamsField KStoCTPChange(KingstarAPI::CThostFtdcQryBrokerTradingParamsField *input)
{
	CTPTradeApi::CThostFtdcQryBrokerTradingParamsField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcQryBrokerTradingParamsField CTPtoKSChange(CTPTradeApi::CThostFtdcQryBrokerTradingParamsField *input)
{
	KingstarAPI::CThostFtdcQryBrokerTradingParamsField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcBrokerTradingParamsField KStoCTPChange(KingstarAPI::CThostFtdcBrokerTradingParamsField *input)
{
	CTPTradeApi::CThostFtdcBrokerTradingParamsField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.MarginPriceType, input->MarginPriceType, sizeof(field.MarginPriceType));
	localmemcpy(field.Algorithm, input->Algorithm, sizeof(field.Algorithm));
	localmemcpy(field.AvailIncludeCloseProfit, input->AvailIncludeCloseProfit, sizeof(field.AvailIncludeCloseProfit));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.OptionRoyaltyPriceType, input->OptionRoyaltyPriceType, sizeof(field.OptionRoyaltyPriceType));
	return field;
}
KingstarAPI::CThostFtdcBrokerTradingParamsField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerTradingParamsField *input)
{
	KingstarAPI::CThostFtdcBrokerTradingParamsField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.MarginPriceType, input->MarginPriceType, sizeof(field.MarginPriceType));
	localmemcpy(field.Algorithm, input->Algorithm, sizeof(field.Algorithm));
	localmemcpy(field.AvailIncludeCloseProfit, input->AvailIncludeCloseProfit, sizeof(field.AvailIncludeCloseProfit));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.OptionRoyaltyPriceType, input->OptionRoyaltyPriceType, sizeof(field.OptionRoyaltyPriceType));
	return field;
}
CTPTradeApi::CThostFtdcQryBrokerTradingAlgosField KStoCTPChange(KingstarAPI::CThostFtdcQryBrokerTradingAlgosField *input)
{
	CTPTradeApi::CThostFtdcQryBrokerTradingAlgosField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryBrokerTradingAlgosField CTPtoKSChange(CTPTradeApi::CThostFtdcQryBrokerTradingAlgosField *input)
{
	KingstarAPI::CThostFtdcQryBrokerTradingAlgosField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcBrokerTradingAlgosField KStoCTPChange(KingstarAPI::CThostFtdcBrokerTradingAlgosField *input)
{
	CTPTradeApi::CThostFtdcBrokerTradingAlgosField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HandlePositionAlgoID, input->HandlePositionAlgoID, sizeof(field.HandlePositionAlgoID));
	localmemcpy(field.FindMarginRateAlgoID, input->FindMarginRateAlgoID, sizeof(field.FindMarginRateAlgoID));
	localmemcpy(field.HandleTradingAccountAlgoID, input->HandleTradingAccountAlgoID, sizeof(field.HandleTradingAccountAlgoID));
	return field;
}
KingstarAPI::CThostFtdcBrokerTradingAlgosField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerTradingAlgosField *input)
{
	KingstarAPI::CThostFtdcBrokerTradingAlgosField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.HandlePositionAlgoID, input->HandlePositionAlgoID, sizeof(field.HandlePositionAlgoID));
	localmemcpy(field.FindMarginRateAlgoID, input->FindMarginRateAlgoID, sizeof(field.FindMarginRateAlgoID));
	localmemcpy(field.HandleTradingAccountAlgoID, input->HandleTradingAccountAlgoID, sizeof(field.HandleTradingAccountAlgoID));
	return field;
}
CTPTradeApi::CThostFtdcQueryBrokerDepositField KStoCTPChange(KingstarAPI::CThostFtdcQueryBrokerDepositField *input)
{
	CTPTradeApi::CThostFtdcQueryBrokerDepositField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
KingstarAPI::CThostFtdcQueryBrokerDepositField CTPtoKSChange(CTPTradeApi::CThostFtdcQueryBrokerDepositField *input)
{
	KingstarAPI::CThostFtdcQueryBrokerDepositField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	return field;
}
CTPTradeApi::CThostFtdcBrokerDepositField KStoCTPChange(KingstarAPI::CThostFtdcBrokerDepositField *input)
{
	CTPTradeApi::CThostFtdcBrokerDepositField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.PreBalance, input->PreBalance, sizeof(field.PreBalance));
	localmemcpy(field.CurrMargin, input->CurrMargin, sizeof(field.CurrMargin));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.Balance, input->Balance, sizeof(field.Balance));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.Withdraw, input->Withdraw, sizeof(field.Withdraw));
	localmemcpy(field.Available, input->Available, sizeof(field.Available));
	localmemcpy(field.Reserve, input->Reserve, sizeof(field.Reserve));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	return field;
}
KingstarAPI::CThostFtdcBrokerDepositField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerDepositField *input)
{
	KingstarAPI::CThostFtdcBrokerDepositField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.PreBalance, input->PreBalance, sizeof(field.PreBalance));
	localmemcpy(field.CurrMargin, input->CurrMargin, sizeof(field.CurrMargin));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.Balance, input->Balance, sizeof(field.Balance));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.Withdraw, input->Withdraw, sizeof(field.Withdraw));
	localmemcpy(field.Available, input->Available, sizeof(field.Available));
	localmemcpy(field.Reserve, input->Reserve, sizeof(field.Reserve));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	return field;
}
CTPTradeApi::CThostFtdcQryCFMMCBrokerKeyField KStoCTPChange(KingstarAPI::CThostFtdcQryCFMMCBrokerKeyField *input)
{
	CTPTradeApi::CThostFtdcQryCFMMCBrokerKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
KingstarAPI::CThostFtdcQryCFMMCBrokerKeyField CTPtoKSChange(CTPTradeApi::CThostFtdcQryCFMMCBrokerKeyField *input)
{
	KingstarAPI::CThostFtdcQryCFMMCBrokerKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	return field;
}
CTPTradeApi::CThostFtdcCFMMCBrokerKeyField KStoCTPChange(KingstarAPI::CThostFtdcCFMMCBrokerKeyField *input)
{
	CTPTradeApi::CThostFtdcCFMMCBrokerKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.CreateDate, input->CreateDate, sizeof(field.CreateDate));
	localmemcpy(field.CreateTime, input->CreateTime, sizeof(field.CreateTime));
	localmemcpy(field.KeyID, input->KeyID, sizeof(field.KeyID));
	localmemcpy(field.CurrentKey, input->CurrentKey, sizeof(field.CurrentKey));
	localmemcpy(field.KeyKind, input->KeyKind, sizeof(field.KeyKind));
	return field;
}
KingstarAPI::CThostFtdcCFMMCBrokerKeyField CTPtoKSChange(CTPTradeApi::CThostFtdcCFMMCBrokerKeyField *input)
{
	KingstarAPI::CThostFtdcCFMMCBrokerKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.CreateDate, input->CreateDate, sizeof(field.CreateDate));
	localmemcpy(field.CreateTime, input->CreateTime, sizeof(field.CreateTime));
	localmemcpy(field.KeyID, input->KeyID, sizeof(field.KeyID));
	localmemcpy(field.CurrentKey, input->CurrentKey, sizeof(field.CurrentKey));
	localmemcpy(field.KeyKind, input->KeyKind, sizeof(field.KeyKind));
	return field;
}
CTPTradeApi::CThostFtdcCFMMCTradingAccountKeyField KStoCTPChange(KingstarAPI::CThostFtdcCFMMCTradingAccountKeyField *input)
{
	CTPTradeApi::CThostFtdcCFMMCTradingAccountKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.KeyID, input->KeyID, sizeof(field.KeyID));
	localmemcpy(field.CurrentKey, input->CurrentKey, sizeof(field.CurrentKey));
	return field;
}
KingstarAPI::CThostFtdcCFMMCTradingAccountKeyField CTPtoKSChange(CTPTradeApi::CThostFtdcCFMMCTradingAccountKeyField *input)
{
	KingstarAPI::CThostFtdcCFMMCTradingAccountKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.KeyID, input->KeyID, sizeof(field.KeyID));
	localmemcpy(field.CurrentKey, input->CurrentKey, sizeof(field.CurrentKey));
	return field;
}
CTPTradeApi::CThostFtdcQryCFMMCTradingAccountKeyField KStoCTPChange(KingstarAPI::CThostFtdcQryCFMMCTradingAccountKeyField *input)
{
	CTPTradeApi::CThostFtdcQryCFMMCTradingAccountKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQryCFMMCTradingAccountKeyField CTPtoKSChange(CTPTradeApi::CThostFtdcQryCFMMCTradingAccountKeyField *input)
{
	KingstarAPI::CThostFtdcQryCFMMCTradingAccountKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcBrokerUserOTPParamField KStoCTPChange(KingstarAPI::CThostFtdcBrokerUserOTPParamField *input)
{
	CTPTradeApi::CThostFtdcBrokerUserOTPParamField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OTPVendorsID, input->OTPVendorsID, sizeof(field.OTPVendorsID));
	localmemcpy(field.SerialNumber, input->SerialNumber, sizeof(field.SerialNumber));
	localmemcpy(field.AuthKey, input->AuthKey, sizeof(field.AuthKey));
	localmemcpy(field.LastDrift, input->LastDrift, sizeof(field.LastDrift));
	localmemcpy(field.LastSuccess, input->LastSuccess, sizeof(field.LastSuccess));
	localmemcpy(field.OTPType, input->OTPType, sizeof(field.OTPType));
	return field;
}
KingstarAPI::CThostFtdcBrokerUserOTPParamField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerUserOTPParamField *input)
{
	KingstarAPI::CThostFtdcBrokerUserOTPParamField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OTPVendorsID, input->OTPVendorsID, sizeof(field.OTPVendorsID));
	localmemcpy(field.SerialNumber, input->SerialNumber, sizeof(field.SerialNumber));
	localmemcpy(field.AuthKey, input->AuthKey, sizeof(field.AuthKey));
	localmemcpy(field.LastDrift, input->LastDrift, sizeof(field.LastDrift));
	localmemcpy(field.LastSuccess, input->LastSuccess, sizeof(field.LastSuccess));
	localmemcpy(field.OTPType, input->OTPType, sizeof(field.OTPType));
	return field;
}
CTPTradeApi::CThostFtdcManualSyncBrokerUserOTPField KStoCTPChange(KingstarAPI::CThostFtdcManualSyncBrokerUserOTPField *input)
{
	CTPTradeApi::CThostFtdcManualSyncBrokerUserOTPField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OTPType, input->OTPType, sizeof(field.OTPType));
	localmemcpy(field.FirstOTP, input->FirstOTP, sizeof(field.FirstOTP));
	localmemcpy(field.SecondOTP, input->SecondOTP, sizeof(field.SecondOTP));
	return field;
}
KingstarAPI::CThostFtdcManualSyncBrokerUserOTPField CTPtoKSChange(CTPTradeApi::CThostFtdcManualSyncBrokerUserOTPField *input)
{
	KingstarAPI::CThostFtdcManualSyncBrokerUserOTPField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.OTPType, input->OTPType, sizeof(field.OTPType));
	localmemcpy(field.FirstOTP, input->FirstOTP, sizeof(field.FirstOTP));
	localmemcpy(field.SecondOTP, input->SecondOTP, sizeof(field.SecondOTP));
	return field;
}
CTPTradeApi::CThostFtdcCommRateModelField KStoCTPChange(KingstarAPI::CThostFtdcCommRateModelField *input)
{
	CTPTradeApi::CThostFtdcCommRateModelField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.CommModelID, input->CommModelID, sizeof(field.CommModelID));
	localmemcpy(field.CommModelName, input->CommModelName, sizeof(field.CommModelName));
	return field;
}
KingstarAPI::CThostFtdcCommRateModelField CTPtoKSChange(CTPTradeApi::CThostFtdcCommRateModelField *input)
{
	KingstarAPI::CThostFtdcCommRateModelField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.CommModelID, input->CommModelID, sizeof(field.CommModelID));
	localmemcpy(field.CommModelName, input->CommModelName, sizeof(field.CommModelName));
	return field;
}
CTPTradeApi::CThostFtdcQryCommRateModelField KStoCTPChange(KingstarAPI::CThostFtdcQryCommRateModelField *input)
{
	CTPTradeApi::CThostFtdcQryCommRateModelField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.CommModelID, input->CommModelID, sizeof(field.CommModelID));
	return field;
}
KingstarAPI::CThostFtdcQryCommRateModelField CTPtoKSChange(CTPTradeApi::CThostFtdcQryCommRateModelField *input)
{
	KingstarAPI::CThostFtdcQryCommRateModelField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.CommModelID, input->CommModelID, sizeof(field.CommModelID));
	return field;
}
CTPTradeApi::CThostFtdcMarginModelField KStoCTPChange(KingstarAPI::CThostFtdcMarginModelField *input)
{
	CTPTradeApi::CThostFtdcMarginModelField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MarginModelID, input->MarginModelID, sizeof(field.MarginModelID));
	localmemcpy(field.MarginModelName, input->MarginModelName, sizeof(field.MarginModelName));
	return field;
}
KingstarAPI::CThostFtdcMarginModelField CTPtoKSChange(CTPTradeApi::CThostFtdcMarginModelField *input)
{
	KingstarAPI::CThostFtdcMarginModelField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MarginModelID, input->MarginModelID, sizeof(field.MarginModelID));
	localmemcpy(field.MarginModelName, input->MarginModelName, sizeof(field.MarginModelName));
	return field;
}
CTPTradeApi::CThostFtdcQryMarginModelField KStoCTPChange(KingstarAPI::CThostFtdcQryMarginModelField *input)
{
	CTPTradeApi::CThostFtdcQryMarginModelField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MarginModelID, input->MarginModelID, sizeof(field.MarginModelID));
	return field;
}
KingstarAPI::CThostFtdcQryMarginModelField CTPtoKSChange(CTPTradeApi::CThostFtdcQryMarginModelField *input)
{
	KingstarAPI::CThostFtdcQryMarginModelField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.MarginModelID, input->MarginModelID, sizeof(field.MarginModelID));
	return field;
}
CTPTradeApi::CThostFtdcEWarrantOffsetField KStoCTPChange(KingstarAPI::CThostFtdcEWarrantOffsetField *input)
{
	CTPTradeApi::CThostFtdcEWarrantOffsetField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	return field;
}
KingstarAPI::CThostFtdcEWarrantOffsetField CTPtoKSChange(CTPTradeApi::CThostFtdcEWarrantOffsetField *input)
{
	KingstarAPI::CThostFtdcEWarrantOffsetField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	localmemcpy(field.Direction, input->Direction, sizeof(field.Direction));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	localmemcpy(field.Volume, input->Volume, sizeof(field.Volume));
	return field;
}
CTPTradeApi::CThostFtdcQryEWarrantOffsetField KStoCTPChange(KingstarAPI::CThostFtdcQryEWarrantOffsetField *input)
{
	CTPTradeApi::CThostFtdcQryEWarrantOffsetField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
KingstarAPI::CThostFtdcQryEWarrantOffsetField CTPtoKSChange(CTPTradeApi::CThostFtdcQryEWarrantOffsetField *input)
{
	KingstarAPI::CThostFtdcQryEWarrantOffsetField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ExchangeID, input->ExchangeID, sizeof(field.ExchangeID));
	localmemcpy(field.InstrumentID, input->InstrumentID, sizeof(field.InstrumentID));
	return field;
}
CTPTradeApi::CThostFtdcQryInvestorProductGroupMarginField KStoCTPChange(KingstarAPI::CThostFtdcQryInvestorProductGroupMarginField *input)
{
	CTPTradeApi::CThostFtdcQryInvestorProductGroupMarginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ProductGroupID, input->ProductGroupID, sizeof(field.ProductGroupID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
KingstarAPI::CThostFtdcQryInvestorProductGroupMarginField CTPtoKSChange(CTPTradeApi::CThostFtdcQryInvestorProductGroupMarginField *input)
{
	KingstarAPI::CThostFtdcQryInvestorProductGroupMarginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.ProductGroupID, input->ProductGroupID, sizeof(field.ProductGroupID));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
CTPTradeApi::CThostFtdcInvestorProductGroupMarginField KStoCTPChange(KingstarAPI::CThostFtdcInvestorProductGroupMarginField *input)
{
	CTPTradeApi::CThostFtdcInvestorProductGroupMarginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ProductGroupID, input->ProductGroupID, sizeof(field.ProductGroupID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.LongFrozenMargin, input->LongFrozenMargin, sizeof(field.LongFrozenMargin));
	localmemcpy(field.ShortFrozenMargin, input->ShortFrozenMargin, sizeof(field.ShortFrozenMargin));
	localmemcpy(field.UseMargin, input->UseMargin, sizeof(field.UseMargin));
	localmemcpy(field.LongUseMargin, input->LongUseMargin, sizeof(field.LongUseMargin));
	localmemcpy(field.ShortUseMargin, input->ShortUseMargin, sizeof(field.ShortUseMargin));
	localmemcpy(field.ExchMargin, input->ExchMargin, sizeof(field.ExchMargin));
	localmemcpy(field.LongExchMargin, input->LongExchMargin, sizeof(field.LongExchMargin));
	localmemcpy(field.ShortExchMargin, input->ShortExchMargin, sizeof(field.ShortExchMargin));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.OffsetAmount, input->OffsetAmount, sizeof(field.OffsetAmount));
	localmemcpy(field.LongOffsetAmount, input->LongOffsetAmount, sizeof(field.LongOffsetAmount));
	localmemcpy(field.ShortOffsetAmount, input->ShortOffsetAmount, sizeof(field.ShortOffsetAmount));
	localmemcpy(field.ExchOffsetAmount, input->ExchOffsetAmount, sizeof(field.ExchOffsetAmount));
	localmemcpy(field.LongExchOffsetAmount, input->LongExchOffsetAmount, sizeof(field.LongExchOffsetAmount));
	localmemcpy(field.ShortExchOffsetAmount, input->ShortExchOffsetAmount, sizeof(field.ShortExchOffsetAmount));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
KingstarAPI::CThostFtdcInvestorProductGroupMarginField CTPtoKSChange(CTPTradeApi::CThostFtdcInvestorProductGroupMarginField *input)
{
	KingstarAPI::CThostFtdcInvestorProductGroupMarginField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ProductGroupID, input->ProductGroupID, sizeof(field.ProductGroupID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.SettlementID, input->SettlementID, sizeof(field.SettlementID));
	localmemcpy(field.FrozenMargin, input->FrozenMargin, sizeof(field.FrozenMargin));
	localmemcpy(field.LongFrozenMargin, input->LongFrozenMargin, sizeof(field.LongFrozenMargin));
	localmemcpy(field.ShortFrozenMargin, input->ShortFrozenMargin, sizeof(field.ShortFrozenMargin));
	localmemcpy(field.UseMargin, input->UseMargin, sizeof(field.UseMargin));
	localmemcpy(field.LongUseMargin, input->LongUseMargin, sizeof(field.LongUseMargin));
	localmemcpy(field.ShortUseMargin, input->ShortUseMargin, sizeof(field.ShortUseMargin));
	localmemcpy(field.ExchMargin, input->ExchMargin, sizeof(field.ExchMargin));
	localmemcpy(field.LongExchMargin, input->LongExchMargin, sizeof(field.LongExchMargin));
	localmemcpy(field.ShortExchMargin, input->ShortExchMargin, sizeof(field.ShortExchMargin));
	localmemcpy(field.CloseProfit, input->CloseProfit, sizeof(field.CloseProfit));
	localmemcpy(field.FrozenCommission, input->FrozenCommission, sizeof(field.FrozenCommission));
	localmemcpy(field.Commission, input->Commission, sizeof(field.Commission));
	localmemcpy(field.FrozenCash, input->FrozenCash, sizeof(field.FrozenCash));
	localmemcpy(field.CashIn, input->CashIn, sizeof(field.CashIn));
	localmemcpy(field.PositionProfit, input->PositionProfit, sizeof(field.PositionProfit));
	localmemcpy(field.OffsetAmount, input->OffsetAmount, sizeof(field.OffsetAmount));
	localmemcpy(field.LongOffsetAmount, input->LongOffsetAmount, sizeof(field.LongOffsetAmount));
	localmemcpy(field.ShortOffsetAmount, input->ShortOffsetAmount, sizeof(field.ShortOffsetAmount));
	localmemcpy(field.ExchOffsetAmount, input->ExchOffsetAmount, sizeof(field.ExchOffsetAmount));
	localmemcpy(field.LongExchOffsetAmount, input->LongExchOffsetAmount, sizeof(field.LongExchOffsetAmount));
	localmemcpy(field.ShortExchOffsetAmount, input->ShortExchOffsetAmount, sizeof(field.ShortExchOffsetAmount));
	localmemcpy(field.HedgeFlag, input->HedgeFlag, sizeof(field.HedgeFlag));
	return field;
}
CTPTradeApi::CThostFtdcQueryCFMMCTradingAccountTokenField KStoCTPChange(KingstarAPI::CThostFtdcQueryCFMMCTradingAccountTokenField *input)
{
	CTPTradeApi::CThostFtdcQueryCFMMCTradingAccountTokenField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
KingstarAPI::CThostFtdcQueryCFMMCTradingAccountTokenField CTPtoKSChange(CTPTradeApi::CThostFtdcQueryCFMMCTradingAccountTokenField *input)
{
	KingstarAPI::CThostFtdcQueryCFMMCTradingAccountTokenField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	return field;
}
CTPTradeApi::CThostFtdcCFMMCTradingAccountTokenField KStoCTPChange(KingstarAPI::CThostFtdcCFMMCTradingAccountTokenField *input)
{
	CTPTradeApi::CThostFtdcCFMMCTradingAccountTokenField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.KeyID, input->KeyID, sizeof(field.KeyID));
	localmemcpy(field.Token, input->Token, sizeof(field.Token));
	return field;
}
KingstarAPI::CThostFtdcCFMMCTradingAccountTokenField CTPtoKSChange(CTPTradeApi::CThostFtdcCFMMCTradingAccountTokenField *input)
{
	KingstarAPI::CThostFtdcCFMMCTradingAccountTokenField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.ParticipantID, input->ParticipantID, sizeof(field.ParticipantID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.KeyID, input->KeyID, sizeof(field.KeyID));
	localmemcpy(field.Token, input->Token, sizeof(field.Token));
	return field;
}
CTPTradeApi::CThostFtdcReqOpenAccountField KStoCTPChange(KingstarAPI::CThostFtdcReqOpenAccountField *input)
{
	CTPTradeApi::CThostFtdcReqOpenAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.CashExchangeCode, input->CashExchangeCode, sizeof(field.CashExchangeCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcReqOpenAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcReqOpenAccountField *input)
{
	KingstarAPI::CThostFtdcReqOpenAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.CashExchangeCode, input->CashExchangeCode, sizeof(field.CashExchangeCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcReqCancelAccountField KStoCTPChange(KingstarAPI::CThostFtdcReqCancelAccountField *input)
{
	CTPTradeApi::CThostFtdcReqCancelAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.CashExchangeCode, input->CashExchangeCode, sizeof(field.CashExchangeCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcReqCancelAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcReqCancelAccountField *input)
{
	KingstarAPI::CThostFtdcReqCancelAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.CashExchangeCode, input->CashExchangeCode, sizeof(field.CashExchangeCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcReqChangeAccountField KStoCTPChange(KingstarAPI::CThostFtdcReqChangeAccountField *input)
{
	CTPTradeApi::CThostFtdcReqChangeAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.NewBankAccount, input->NewBankAccount, sizeof(field.NewBankAccount));
	localmemcpy(field.NewBankPassWord, input->NewBankPassWord, sizeof(field.NewBankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	return field;
}
KingstarAPI::CThostFtdcReqChangeAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcReqChangeAccountField *input)
{
	KingstarAPI::CThostFtdcReqChangeAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.NewBankAccount, input->NewBankAccount, sizeof(field.NewBankAccount));
	localmemcpy(field.NewBankPassWord, input->NewBankPassWord, sizeof(field.NewBankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	return field;
}
CTPTradeApi::CThostFtdcReqTransferField KStoCTPChange(KingstarAPI::CThostFtdcReqTransferField *input)
{
	CTPTradeApi::CThostFtdcReqTransferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.FutureFetchAmount, input->FutureFetchAmount, sizeof(field.FutureFetchAmount));
	localmemcpy(field.FeePayFlag, input->FeePayFlag, sizeof(field.FeePayFlag));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.TransferStatus, input->TransferStatus, sizeof(field.TransferStatus));
	return field;
}
KingstarAPI::CThostFtdcReqTransferField CTPtoKSChange(CTPTradeApi::CThostFtdcReqTransferField *input)
{
	KingstarAPI::CThostFtdcReqTransferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.FutureFetchAmount, input->FutureFetchAmount, sizeof(field.FutureFetchAmount));
	localmemcpy(field.FeePayFlag, input->FeePayFlag, sizeof(field.FeePayFlag));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.TransferStatus, input->TransferStatus, sizeof(field.TransferStatus));
	return field;
}
CTPTradeApi::CThostFtdcRspTransferField KStoCTPChange(KingstarAPI::CThostFtdcRspTransferField *input)
{
	CTPTradeApi::CThostFtdcRspTransferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.FutureFetchAmount, input->FutureFetchAmount, sizeof(field.FutureFetchAmount));
	localmemcpy(field.FeePayFlag, input->FeePayFlag, sizeof(field.FeePayFlag));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.TransferStatus, input->TransferStatus, sizeof(field.TransferStatus));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcRspTransferField CTPtoKSChange(CTPTradeApi::CThostFtdcRspTransferField *input)
{
	KingstarAPI::CThostFtdcRspTransferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.FutureFetchAmount, input->FutureFetchAmount, sizeof(field.FutureFetchAmount));
	localmemcpy(field.FeePayFlag, input->FeePayFlag, sizeof(field.FeePayFlag));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.TransferStatus, input->TransferStatus, sizeof(field.TransferStatus));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcReqRepealField KStoCTPChange(KingstarAPI::CThostFtdcReqRepealField *input)
{
	CTPTradeApi::CThostFtdcReqRepealField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RepealTimeInterval, input->RepealTimeInterval, sizeof(field.RepealTimeInterval));
	localmemcpy(field.RepealedTimes, input->RepealedTimes, sizeof(field.RepealedTimes));
	localmemcpy(field.BankRepealFlag, input->BankRepealFlag, sizeof(field.BankRepealFlag));
	localmemcpy(field.BrokerRepealFlag, input->BrokerRepealFlag, sizeof(field.BrokerRepealFlag));
	localmemcpy(field.PlateRepealSerial, input->PlateRepealSerial, sizeof(field.PlateRepealSerial));
	localmemcpy(field.BankRepealSerial, input->BankRepealSerial, sizeof(field.BankRepealSerial));
	localmemcpy(field.FutureRepealSerial, input->FutureRepealSerial, sizeof(field.FutureRepealSerial));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.FutureFetchAmount, input->FutureFetchAmount, sizeof(field.FutureFetchAmount));
	localmemcpy(field.FeePayFlag, input->FeePayFlag, sizeof(field.FeePayFlag));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.TransferStatus, input->TransferStatus, sizeof(field.TransferStatus));
	return field;
}
KingstarAPI::CThostFtdcReqRepealField CTPtoKSChange(CTPTradeApi::CThostFtdcReqRepealField *input)
{
	KingstarAPI::CThostFtdcReqRepealField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RepealTimeInterval, input->RepealTimeInterval, sizeof(field.RepealTimeInterval));
	localmemcpy(field.RepealedTimes, input->RepealedTimes, sizeof(field.RepealedTimes));
	localmemcpy(field.BankRepealFlag, input->BankRepealFlag, sizeof(field.BankRepealFlag));
	localmemcpy(field.BrokerRepealFlag, input->BrokerRepealFlag, sizeof(field.BrokerRepealFlag));
	localmemcpy(field.PlateRepealSerial, input->PlateRepealSerial, sizeof(field.PlateRepealSerial));
	localmemcpy(field.BankRepealSerial, input->BankRepealSerial, sizeof(field.BankRepealSerial));
	localmemcpy(field.FutureRepealSerial, input->FutureRepealSerial, sizeof(field.FutureRepealSerial));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.FutureFetchAmount, input->FutureFetchAmount, sizeof(field.FutureFetchAmount));
	localmemcpy(field.FeePayFlag, input->FeePayFlag, sizeof(field.FeePayFlag));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.TransferStatus, input->TransferStatus, sizeof(field.TransferStatus));
	return field;
}
CTPTradeApi::CThostFtdcRspRepealField KStoCTPChange(KingstarAPI::CThostFtdcRspRepealField *input)
{
	CTPTradeApi::CThostFtdcRspRepealField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RepealTimeInterval, input->RepealTimeInterval, sizeof(field.RepealTimeInterval));
	localmemcpy(field.RepealedTimes, input->RepealedTimes, sizeof(field.RepealedTimes));
	localmemcpy(field.BankRepealFlag, input->BankRepealFlag, sizeof(field.BankRepealFlag));
	localmemcpy(field.BrokerRepealFlag, input->BrokerRepealFlag, sizeof(field.BrokerRepealFlag));
	localmemcpy(field.PlateRepealSerial, input->PlateRepealSerial, sizeof(field.PlateRepealSerial));
	localmemcpy(field.BankRepealSerial, input->BankRepealSerial, sizeof(field.BankRepealSerial));
	localmemcpy(field.FutureRepealSerial, input->FutureRepealSerial, sizeof(field.FutureRepealSerial));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.FutureFetchAmount, input->FutureFetchAmount, sizeof(field.FutureFetchAmount));
	localmemcpy(field.FeePayFlag, input->FeePayFlag, sizeof(field.FeePayFlag));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.TransferStatus, input->TransferStatus, sizeof(field.TransferStatus));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcRspRepealField CTPtoKSChange(CTPTradeApi::CThostFtdcRspRepealField *input)
{
	KingstarAPI::CThostFtdcRspRepealField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.RepealTimeInterval, input->RepealTimeInterval, sizeof(field.RepealTimeInterval));
	localmemcpy(field.RepealedTimes, input->RepealedTimes, sizeof(field.RepealedTimes));
	localmemcpy(field.BankRepealFlag, input->BankRepealFlag, sizeof(field.BankRepealFlag));
	localmemcpy(field.BrokerRepealFlag, input->BrokerRepealFlag, sizeof(field.BrokerRepealFlag));
	localmemcpy(field.PlateRepealSerial, input->PlateRepealSerial, sizeof(field.PlateRepealSerial));
	localmemcpy(field.BankRepealSerial, input->BankRepealSerial, sizeof(field.BankRepealSerial));
	localmemcpy(field.FutureRepealSerial, input->FutureRepealSerial, sizeof(field.FutureRepealSerial));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.FutureFetchAmount, input->FutureFetchAmount, sizeof(field.FutureFetchAmount));
	localmemcpy(field.FeePayFlag, input->FeePayFlag, sizeof(field.FeePayFlag));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.TransferStatus, input->TransferStatus, sizeof(field.TransferStatus));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcReqQueryAccountField KStoCTPChange(KingstarAPI::CThostFtdcReqQueryAccountField *input)
{
	CTPTradeApi::CThostFtdcReqQueryAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	return field;
}
KingstarAPI::CThostFtdcReqQueryAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcReqQueryAccountField *input)
{
	KingstarAPI::CThostFtdcReqQueryAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	return field;
}
CTPTradeApi::CThostFtdcRspQueryAccountField KStoCTPChange(KingstarAPI::CThostFtdcRspQueryAccountField *input)
{
	CTPTradeApi::CThostFtdcRspQueryAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.BankUseAmount, input->BankUseAmount, sizeof(field.BankUseAmount));
	localmemcpy(field.BankFetchAmount, input->BankFetchAmount, sizeof(field.BankFetchAmount));
	return field;
}
KingstarAPI::CThostFtdcRspQueryAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcRspQueryAccountField *input)
{
	KingstarAPI::CThostFtdcRspQueryAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.BankUseAmount, input->BankUseAmount, sizeof(field.BankUseAmount));
	localmemcpy(field.BankFetchAmount, input->BankFetchAmount, sizeof(field.BankFetchAmount));
	return field;
}
CTPTradeApi::CThostFtdcFutureSignIOField KStoCTPChange(KingstarAPI::CThostFtdcFutureSignIOField *input)
{
	CTPTradeApi::CThostFtdcFutureSignIOField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	return field;
}
KingstarAPI::CThostFtdcFutureSignIOField CTPtoKSChange(CTPTradeApi::CThostFtdcFutureSignIOField *input)
{
	KingstarAPI::CThostFtdcFutureSignIOField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	return field;
}
CTPTradeApi::CThostFtdcRspFutureSignInField KStoCTPChange(KingstarAPI::CThostFtdcRspFutureSignInField *input)
{
	CTPTradeApi::CThostFtdcRspFutureSignInField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.PinKey, input->PinKey, sizeof(field.PinKey));
	localmemcpy(field.MacKey, input->MacKey, sizeof(field.MacKey));
	return field;
}
KingstarAPI::CThostFtdcRspFutureSignInField CTPtoKSChange(CTPTradeApi::CThostFtdcRspFutureSignInField *input)
{
	KingstarAPI::CThostFtdcRspFutureSignInField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.PinKey, input->PinKey, sizeof(field.PinKey));
	localmemcpy(field.MacKey, input->MacKey, sizeof(field.MacKey));
	return field;
}
CTPTradeApi::CThostFtdcReqFutureSignOutField KStoCTPChange(KingstarAPI::CThostFtdcReqFutureSignOutField *input)
{
	CTPTradeApi::CThostFtdcReqFutureSignOutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	return field;
}
KingstarAPI::CThostFtdcReqFutureSignOutField CTPtoKSChange(CTPTradeApi::CThostFtdcReqFutureSignOutField *input)
{
	KingstarAPI::CThostFtdcReqFutureSignOutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	return field;
}
CTPTradeApi::CThostFtdcRspFutureSignOutField KStoCTPChange(KingstarAPI::CThostFtdcRspFutureSignOutField *input)
{
	CTPTradeApi::CThostFtdcRspFutureSignOutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcRspFutureSignOutField CTPtoKSChange(CTPTradeApi::CThostFtdcRspFutureSignOutField *input)
{
	KingstarAPI::CThostFtdcRspFutureSignOutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcReqQueryTradeResultBySerialField KStoCTPChange(KingstarAPI::CThostFtdcReqQueryTradeResultBySerialField *input)
{
	CTPTradeApi::CThostFtdcReqQueryTradeResultBySerialField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.Reference, input->Reference, sizeof(field.Reference));
	localmemcpy(field.RefrenceIssureType, input->RefrenceIssureType, sizeof(field.RefrenceIssureType));
	localmemcpy(field.RefrenceIssure, input->RefrenceIssure, sizeof(field.RefrenceIssure));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	return field;
}
KingstarAPI::CThostFtdcReqQueryTradeResultBySerialField CTPtoKSChange(CTPTradeApi::CThostFtdcReqQueryTradeResultBySerialField *input)
{
	KingstarAPI::CThostFtdcReqQueryTradeResultBySerialField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.Reference, input->Reference, sizeof(field.Reference));
	localmemcpy(field.RefrenceIssureType, input->RefrenceIssureType, sizeof(field.RefrenceIssureType));
	localmemcpy(field.RefrenceIssure, input->RefrenceIssure, sizeof(field.RefrenceIssure));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	return field;
}
CTPTradeApi::CThostFtdcRspQueryTradeResultBySerialField KStoCTPChange(KingstarAPI::CThostFtdcRspQueryTradeResultBySerialField *input)
{
	CTPTradeApi::CThostFtdcRspQueryTradeResultBySerialField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.Reference, input->Reference, sizeof(field.Reference));
	localmemcpy(field.RefrenceIssureType, input->RefrenceIssureType, sizeof(field.RefrenceIssureType));
	localmemcpy(field.RefrenceIssure, input->RefrenceIssure, sizeof(field.RefrenceIssure));
	localmemcpy(field.OriginReturnCode, input->OriginReturnCode, sizeof(field.OriginReturnCode));
	localmemcpy(field.OriginDescrInfoForReturnCode, input->OriginDescrInfoForReturnCode, sizeof(field.OriginDescrInfoForReturnCode));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	return field;
}
KingstarAPI::CThostFtdcRspQueryTradeResultBySerialField CTPtoKSChange(CTPTradeApi::CThostFtdcRspQueryTradeResultBySerialField *input)
{
	KingstarAPI::CThostFtdcRspQueryTradeResultBySerialField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.Reference, input->Reference, sizeof(field.Reference));
	localmemcpy(field.RefrenceIssureType, input->RefrenceIssureType, sizeof(field.RefrenceIssureType));
	localmemcpy(field.RefrenceIssure, input->RefrenceIssure, sizeof(field.RefrenceIssure));
	localmemcpy(field.OriginReturnCode, input->OriginReturnCode, sizeof(field.OriginReturnCode));
	localmemcpy(field.OriginDescrInfoForReturnCode, input->OriginDescrInfoForReturnCode, sizeof(field.OriginDescrInfoForReturnCode));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	return field;
}
CTPTradeApi::CThostFtdcReqDayEndFileReadyField KStoCTPChange(KingstarAPI::CThostFtdcReqDayEndFileReadyField *input)
{
	CTPTradeApi::CThostFtdcReqDayEndFileReadyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.FileBusinessCode, input->FileBusinessCode, sizeof(field.FileBusinessCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	return field;
}
KingstarAPI::CThostFtdcReqDayEndFileReadyField CTPtoKSChange(CTPTradeApi::CThostFtdcReqDayEndFileReadyField *input)
{
	KingstarAPI::CThostFtdcReqDayEndFileReadyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.FileBusinessCode, input->FileBusinessCode, sizeof(field.FileBusinessCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	return field;
}
CTPTradeApi::CThostFtdcReturnResultField KStoCTPChange(KingstarAPI::CThostFtdcReturnResultField *input)
{
	CTPTradeApi::CThostFtdcReturnResultField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ReturnCode, input->ReturnCode, sizeof(field.ReturnCode));
	localmemcpy(field.DescrInfoForReturnCode, input->DescrInfoForReturnCode, sizeof(field.DescrInfoForReturnCode));
	return field;
}
KingstarAPI::CThostFtdcReturnResultField CTPtoKSChange(CTPTradeApi::CThostFtdcReturnResultField *input)
{
	KingstarAPI::CThostFtdcReturnResultField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.ReturnCode, input->ReturnCode, sizeof(field.ReturnCode));
	localmemcpy(field.DescrInfoForReturnCode, input->DescrInfoForReturnCode, sizeof(field.DescrInfoForReturnCode));
	return field;
}
CTPTradeApi::CThostFtdcVerifyFuturePasswordField KStoCTPChange(KingstarAPI::CThostFtdcVerifyFuturePasswordField *input)
{
	CTPTradeApi::CThostFtdcVerifyFuturePasswordField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcVerifyFuturePasswordField CTPtoKSChange(CTPTradeApi::CThostFtdcVerifyFuturePasswordField *input)
{
	KingstarAPI::CThostFtdcVerifyFuturePasswordField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcVerifyCustInfoField KStoCTPChange(KingstarAPI::CThostFtdcVerifyCustInfoField *input)
{
	CTPTradeApi::CThostFtdcVerifyCustInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	return field;
}
KingstarAPI::CThostFtdcVerifyCustInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcVerifyCustInfoField *input)
{
	KingstarAPI::CThostFtdcVerifyCustInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	return field;
}
CTPTradeApi::CThostFtdcVerifyFuturePasswordAndCustInfoField KStoCTPChange(KingstarAPI::CThostFtdcVerifyFuturePasswordAndCustInfoField *input)
{
	CTPTradeApi::CThostFtdcVerifyFuturePasswordAndCustInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcVerifyFuturePasswordAndCustInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcVerifyFuturePasswordAndCustInfoField *input)
{
	KingstarAPI::CThostFtdcVerifyFuturePasswordAndCustInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcDepositResultInformField KStoCTPChange(KingstarAPI::CThostFtdcDepositResultInformField *input)
{
	CTPTradeApi::CThostFtdcDepositResultInformField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.DepositSeqNo, input->DepositSeqNo, sizeof(field.DepositSeqNo));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.ReturnCode, input->ReturnCode, sizeof(field.ReturnCode));
	localmemcpy(field.DescrInfoForReturnCode, input->DescrInfoForReturnCode, sizeof(field.DescrInfoForReturnCode));
	return field;
}
KingstarAPI::CThostFtdcDepositResultInformField CTPtoKSChange(CTPTradeApi::CThostFtdcDepositResultInformField *input)
{
	KingstarAPI::CThostFtdcDepositResultInformField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.DepositSeqNo, input->DepositSeqNo, sizeof(field.DepositSeqNo));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.Deposit, input->Deposit, sizeof(field.Deposit));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.ReturnCode, input->ReturnCode, sizeof(field.ReturnCode));
	localmemcpy(field.DescrInfoForReturnCode, input->DescrInfoForReturnCode, sizeof(field.DescrInfoForReturnCode));
	return field;
}
CTPTradeApi::CThostFtdcReqSyncKeyField KStoCTPChange(KingstarAPI::CThostFtdcReqSyncKeyField *input)
{
	CTPTradeApi::CThostFtdcReqSyncKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	return field;
}
KingstarAPI::CThostFtdcReqSyncKeyField CTPtoKSChange(CTPTradeApi::CThostFtdcReqSyncKeyField *input)
{
	KingstarAPI::CThostFtdcReqSyncKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	return field;
}
CTPTradeApi::CThostFtdcRspSyncKeyField KStoCTPChange(KingstarAPI::CThostFtdcRspSyncKeyField *input)
{
	CTPTradeApi::CThostFtdcRspSyncKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcRspSyncKeyField CTPtoKSChange(CTPTradeApi::CThostFtdcRspSyncKeyField *input)
{
	KingstarAPI::CThostFtdcRspSyncKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcNotifyQueryAccountField KStoCTPChange(KingstarAPI::CThostFtdcNotifyQueryAccountField *input)
{
	CTPTradeApi::CThostFtdcNotifyQueryAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.BankUseAmount, input->BankUseAmount, sizeof(field.BankUseAmount));
	localmemcpy(field.BankFetchAmount, input->BankFetchAmount, sizeof(field.BankFetchAmount));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcNotifyQueryAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcNotifyQueryAccountField *input)
{
	KingstarAPI::CThostFtdcNotifyQueryAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.BankUseAmount, input->BankUseAmount, sizeof(field.BankUseAmount));
	localmemcpy(field.BankFetchAmount, input->BankFetchAmount, sizeof(field.BankFetchAmount));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcTransferSerialField KStoCTPChange(KingstarAPI::CThostFtdcTransferSerialField *input)
{
	CTPTradeApi::CThostFtdcTransferSerialField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.FutureAccType, input->FutureAccType, sizeof(field.FutureAccType));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.AvailabilityFlag, input->AvailabilityFlag, sizeof(field.AvailabilityFlag));
	localmemcpy(field.OperatorCode, input->OperatorCode, sizeof(field.OperatorCode));
	localmemcpy(field.BankNewAccount, input->BankNewAccount, sizeof(field.BankNewAccount));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcTransferSerialField CTPtoKSChange(CTPTradeApi::CThostFtdcTransferSerialField *input)
{
	KingstarAPI::CThostFtdcTransferSerialField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.FutureAccType, input->FutureAccType, sizeof(field.FutureAccType));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.InvestorID, input->InvestorID, sizeof(field.InvestorID));
	localmemcpy(field.FutureSerial, input->FutureSerial, sizeof(field.FutureSerial));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.TradeAmount, input->TradeAmount, sizeof(field.TradeAmount));
	localmemcpy(field.CustFee, input->CustFee, sizeof(field.CustFee));
	localmemcpy(field.BrokerFee, input->BrokerFee, sizeof(field.BrokerFee));
	localmemcpy(field.AvailabilityFlag, input->AvailabilityFlag, sizeof(field.AvailabilityFlag));
	localmemcpy(field.OperatorCode, input->OperatorCode, sizeof(field.OperatorCode));
	localmemcpy(field.BankNewAccount, input->BankNewAccount, sizeof(field.BankNewAccount));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcQryTransferSerialField KStoCTPChange(KingstarAPI::CThostFtdcQryTransferSerialField *input)
{
	CTPTradeApi::CThostFtdcQryTransferSerialField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcQryTransferSerialField CTPtoKSChange(CTPTradeApi::CThostFtdcQryTransferSerialField *input)
{
	KingstarAPI::CThostFtdcQryTransferSerialField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcNotifyFutureSignInField KStoCTPChange(KingstarAPI::CThostFtdcNotifyFutureSignInField *input)
{
	CTPTradeApi::CThostFtdcNotifyFutureSignInField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.PinKey, input->PinKey, sizeof(field.PinKey));
	localmemcpy(field.MacKey, input->MacKey, sizeof(field.MacKey));
	return field;
}
KingstarAPI::CThostFtdcNotifyFutureSignInField CTPtoKSChange(CTPTradeApi::CThostFtdcNotifyFutureSignInField *input)
{
	KingstarAPI::CThostFtdcNotifyFutureSignInField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	localmemcpy(field.PinKey, input->PinKey, sizeof(field.PinKey));
	localmemcpy(field.MacKey, input->MacKey, sizeof(field.MacKey));
	return field;
}
CTPTradeApi::CThostFtdcNotifyFutureSignOutField KStoCTPChange(KingstarAPI::CThostFtdcNotifyFutureSignOutField *input)
{
	CTPTradeApi::CThostFtdcNotifyFutureSignOutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcNotifyFutureSignOutField CTPtoKSChange(CTPTradeApi::CThostFtdcNotifyFutureSignOutField *input)
{
	KingstarAPI::CThostFtdcNotifyFutureSignOutField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcNotifySyncKeyField KStoCTPChange(KingstarAPI::CThostFtdcNotifySyncKeyField *input)
{
	CTPTradeApi::CThostFtdcNotifySyncKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcNotifySyncKeyField CTPtoKSChange(CTPTradeApi::CThostFtdcNotifySyncKeyField *input)
{
	KingstarAPI::CThostFtdcNotifySyncKeyField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.Message, input->Message, sizeof(field.Message));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.RequestID, input->RequestID, sizeof(field.RequestID));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcQryAccountregisterField KStoCTPChange(KingstarAPI::CThostFtdcQryAccountregisterField *input)
{
	CTPTradeApi::CThostFtdcQryAccountregisterField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcQryAccountregisterField CTPtoKSChange(CTPTradeApi::CThostFtdcQryAccountregisterField *input)
{
	KingstarAPI::CThostFtdcQryAccountregisterField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcAccountregisterField KStoCTPChange(KingstarAPI::CThostFtdcAccountregisterField *input)
{
	CTPTradeApi::CThostFtdcAccountregisterField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeDay, input->TradeDay, sizeof(field.TradeDay));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.OpenOrDestroy, input->OpenOrDestroy, sizeof(field.OpenOrDestroy));
	localmemcpy(field.RegDate, input->RegDate, sizeof(field.RegDate));
	localmemcpy(field.OutDate, input->OutDate, sizeof(field.OutDate));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	return field;
}
KingstarAPI::CThostFtdcAccountregisterField CTPtoKSChange(CTPTradeApi::CThostFtdcAccountregisterField *input)
{
	KingstarAPI::CThostFtdcAccountregisterField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeDay, input->TradeDay, sizeof(field.TradeDay));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.OpenOrDestroy, input->OpenOrDestroy, sizeof(field.OpenOrDestroy));
	localmemcpy(field.RegDate, input->RegDate, sizeof(field.RegDate));
	localmemcpy(field.OutDate, input->OutDate, sizeof(field.OutDate));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	return field;
}
CTPTradeApi::CThostFtdcOpenAccountField KStoCTPChange(KingstarAPI::CThostFtdcOpenAccountField *input)
{
	CTPTradeApi::CThostFtdcOpenAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.CashExchangeCode, input->CashExchangeCode, sizeof(field.CashExchangeCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcOpenAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcOpenAccountField *input)
{
	KingstarAPI::CThostFtdcOpenAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.CashExchangeCode, input->CashExchangeCode, sizeof(field.CashExchangeCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcCancelAccountField KStoCTPChange(KingstarAPI::CThostFtdcCancelAccountField *input)
{
	CTPTradeApi::CThostFtdcCancelAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.CashExchangeCode, input->CashExchangeCode, sizeof(field.CashExchangeCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcCancelAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcCancelAccountField *input)
{
	KingstarAPI::CThostFtdcCancelAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.CashExchangeCode, input->CashExchangeCode, sizeof(field.CashExchangeCode));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.DeviceID, input->DeviceID, sizeof(field.DeviceID));
	localmemcpy(field.BankSecuAccType, input->BankSecuAccType, sizeof(field.BankSecuAccType));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankSecuAcc, input->BankSecuAcc, sizeof(field.BankSecuAcc));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.OperNo, input->OperNo, sizeof(field.OperNo));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcChangeAccountField KStoCTPChange(KingstarAPI::CThostFtdcChangeAccountField *input)
{
	CTPTradeApi::CThostFtdcChangeAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.NewBankAccount, input->NewBankAccount, sizeof(field.NewBankAccount));
	localmemcpy(field.NewBankPassWord, input->NewBankPassWord, sizeof(field.NewBankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
KingstarAPI::CThostFtdcChangeAccountField CTPtoKSChange(CTPTradeApi::CThostFtdcChangeAccountField *input)
{
	KingstarAPI::CThostFtdcChangeAccountField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.TradeCode, input->TradeCode, sizeof(field.TradeCode));
	localmemcpy(field.BankID, input->BankID, sizeof(field.BankID));
	localmemcpy(field.BankBranchID, input->BankBranchID, sizeof(field.BankBranchID));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.BrokerBranchID, input->BrokerBranchID, sizeof(field.BrokerBranchID));
	localmemcpy(field.TradeDate, input->TradeDate, sizeof(field.TradeDate));
	localmemcpy(field.TradeTime, input->TradeTime, sizeof(field.TradeTime));
	localmemcpy(field.BankSerial, input->BankSerial, sizeof(field.BankSerial));
	localmemcpy(field.TradingDay, input->TradingDay, sizeof(field.TradingDay));
	localmemcpy(field.PlateSerial, input->PlateSerial, sizeof(field.PlateSerial));
	localmemcpy(field.LastFragment, input->LastFragment, sizeof(field.LastFragment));
	localmemcpy(field.SessionID, input->SessionID, sizeof(field.SessionID));
	localmemcpy(field.CustomerName, input->CustomerName, sizeof(field.CustomerName));
	localmemcpy(field.IdCardType, input->IdCardType, sizeof(field.IdCardType));
	localmemcpy(field.IdentifiedCardNo, input->IdentifiedCardNo, sizeof(field.IdentifiedCardNo));
	localmemcpy(field.Gender, input->Gender, sizeof(field.Gender));
	localmemcpy(field.CountryCode, input->CountryCode, sizeof(field.CountryCode));
	localmemcpy(field.CustType, input->CustType, sizeof(field.CustType));
	localmemcpy(field.Address, input->Address, sizeof(field.Address));
	localmemcpy(field.ZipCode, input->ZipCode, sizeof(field.ZipCode));
	localmemcpy(field.Telephone, input->Telephone, sizeof(field.Telephone));
	localmemcpy(field.MobilePhone, input->MobilePhone, sizeof(field.MobilePhone));
	localmemcpy(field.Fax, input->Fax, sizeof(field.Fax));
	localmemcpy(field.EMail, input->EMail, sizeof(field.EMail));
	localmemcpy(field.MoneyAccountStatus, input->MoneyAccountStatus, sizeof(field.MoneyAccountStatus));
	localmemcpy(field.BankAccount, input->BankAccount, sizeof(field.BankAccount));
	localmemcpy(field.BankPassWord, input->BankPassWord, sizeof(field.BankPassWord));
	localmemcpy(field.NewBankAccount, input->NewBankAccount, sizeof(field.NewBankAccount));
	localmemcpy(field.NewBankPassWord, input->NewBankPassWord, sizeof(field.NewBankPassWord));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Password, input->Password, sizeof(field.Password));
	localmemcpy(field.BankAccType, input->BankAccType, sizeof(field.BankAccType));
	localmemcpy(field.InstallID, input->InstallID, sizeof(field.InstallID));
	localmemcpy(field.VerifyCertNoFlag, input->VerifyCertNoFlag, sizeof(field.VerifyCertNoFlag));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.BrokerIDByBank, input->BrokerIDByBank, sizeof(field.BrokerIDByBank));
	localmemcpy(field.BankPwdFlag, input->BankPwdFlag, sizeof(field.BankPwdFlag));
	localmemcpy(field.SecuPwdFlag, input->SecuPwdFlag, sizeof(field.SecuPwdFlag));
	localmemcpy(field.TID, input->TID, sizeof(field.TID));
	localmemcpy(field.Digest, input->Digest, sizeof(field.Digest));
	localmemcpy(field.ErrorID, input->ErrorID, sizeof(field.ErrorID));
	localmemcpy(field.ErrorMsg, input->ErrorMsg, sizeof(field.ErrorMsg));
	return field;
}
CTPTradeApi::CThostFtdcSecAgentACIDMapField KStoCTPChange(KingstarAPI::CThostFtdcSecAgentACIDMapField *input)
{
	CTPTradeApi::CThostFtdcSecAgentACIDMapField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.BrokerSecAgentID, input->BrokerSecAgentID, sizeof(field.BrokerSecAgentID));
	return field;
}
KingstarAPI::CThostFtdcSecAgentACIDMapField CTPtoKSChange(CTPTradeApi::CThostFtdcSecAgentACIDMapField *input)
{
	KingstarAPI::CThostFtdcSecAgentACIDMapField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	localmemcpy(field.BrokerSecAgentID, input->BrokerSecAgentID, sizeof(field.BrokerSecAgentID));
	return field;
}
CTPTradeApi::CThostFtdcQrySecAgentACIDMapField KStoCTPChange(KingstarAPI::CThostFtdcQrySecAgentACIDMapField *input)
{
	CTPTradeApi::CThostFtdcQrySecAgentACIDMapField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcQrySecAgentACIDMapField CTPtoKSChange(CTPTradeApi::CThostFtdcQrySecAgentACIDMapField *input)
{
	KingstarAPI::CThostFtdcQrySecAgentACIDMapField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
CTPTradeApi::CThostFtdcUserRightsAssignField KStoCTPChange(KingstarAPI::CThostFtdcUserRightsAssignField *input)
{
	CTPTradeApi::CThostFtdcUserRightsAssignField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.DRIdentityID, input->DRIdentityID, sizeof(field.DRIdentityID));
	return field;
}
KingstarAPI::CThostFtdcUserRightsAssignField CTPtoKSChange(CTPTradeApi::CThostFtdcUserRightsAssignField *input)
{
	KingstarAPI::CThostFtdcUserRightsAssignField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.DRIdentityID, input->DRIdentityID, sizeof(field.DRIdentityID));
	return field;
}
CTPTradeApi::CThostFtdcBrokerUserRightAssignField KStoCTPChange(KingstarAPI::CThostFtdcBrokerUserRightAssignField *input)
{
	CTPTradeApi::CThostFtdcBrokerUserRightAssignField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.DRIdentityID, input->DRIdentityID, sizeof(field.DRIdentityID));
	localmemcpy(field.Tradeable, input->Tradeable, sizeof(field.Tradeable));
	return field;
}
KingstarAPI::CThostFtdcBrokerUserRightAssignField CTPtoKSChange(CTPTradeApi::CThostFtdcBrokerUserRightAssignField *input)
{
	KingstarAPI::CThostFtdcBrokerUserRightAssignField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.DRIdentityID, input->DRIdentityID, sizeof(field.DRIdentityID));
	localmemcpy(field.Tradeable, input->Tradeable, sizeof(field.Tradeable));
	return field;
}
CTPTradeApi::CThostFtdcDRTransferField KStoCTPChange(KingstarAPI::CThostFtdcDRTransferField *input)
{
	CTPTradeApi::CThostFtdcDRTransferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.OrigDRIdentityID, input->OrigDRIdentityID, sizeof(field.OrigDRIdentityID));
	localmemcpy(field.DestDRIdentityID, input->DestDRIdentityID, sizeof(field.DestDRIdentityID));
	localmemcpy(field.OrigBrokerID, input->OrigBrokerID, sizeof(field.OrigBrokerID));
	localmemcpy(field.DestBrokerID, input->DestBrokerID, sizeof(field.DestBrokerID));
	return field;
}
KingstarAPI::CThostFtdcDRTransferField CTPtoKSChange(CTPTradeApi::CThostFtdcDRTransferField *input)
{
	KingstarAPI::CThostFtdcDRTransferField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.OrigDRIdentityID, input->OrigDRIdentityID, sizeof(field.OrigDRIdentityID));
	localmemcpy(field.DestDRIdentityID, input->DestDRIdentityID, sizeof(field.DestDRIdentityID));
	localmemcpy(field.OrigBrokerID, input->OrigBrokerID, sizeof(field.OrigBrokerID));
	localmemcpy(field.DestBrokerID, input->DestBrokerID, sizeof(field.DestBrokerID));
	return field;
}
CTPTradeApi::CThostFtdcFensUserInfoField KStoCTPChange(KingstarAPI::CThostFtdcFensUserInfoField *input)
{
	CTPTradeApi::CThostFtdcFensUserInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.LoginMode, input->LoginMode, sizeof(field.LoginMode));
	return field;
}
KingstarAPI::CThostFtdcFensUserInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcFensUserInfoField *input)
{
	KingstarAPI::CThostFtdcFensUserInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	localmemcpy(field.LoginMode, input->LoginMode, sizeof(field.LoginMode));
	return field;
}
CTPTradeApi::CThostFtdcCurrTransferIdentityField KStoCTPChange(KingstarAPI::CThostFtdcCurrTransferIdentityField *input)
{
	CTPTradeApi::CThostFtdcCurrTransferIdentityField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.IdentityID, input->IdentityID, sizeof(field.IdentityID));
	return field;
}
KingstarAPI::CThostFtdcCurrTransferIdentityField CTPtoKSChange(CTPTradeApi::CThostFtdcCurrTransferIdentityField *input)
{
	KingstarAPI::CThostFtdcCurrTransferIdentityField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.IdentityID, input->IdentityID, sizeof(field.IdentityID));
	return field;
}
CTPTradeApi::CThostFtdcLoginForbiddenUserField KStoCTPChange(KingstarAPI::CThostFtdcLoginForbiddenUserField *input)
{
	CTPTradeApi::CThostFtdcLoginForbiddenUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcLoginForbiddenUserField CTPtoKSChange(CTPTradeApi::CThostFtdcLoginForbiddenUserField *input)
{
	KingstarAPI::CThostFtdcLoginForbiddenUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcQryLoginForbiddenUserField KStoCTPChange(KingstarAPI::CThostFtdcQryLoginForbiddenUserField *input)
{
	CTPTradeApi::CThostFtdcQryLoginForbiddenUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
KingstarAPI::CThostFtdcQryLoginForbiddenUserField CTPtoKSChange(CTPTradeApi::CThostFtdcQryLoginForbiddenUserField *input)
{
	KingstarAPI::CThostFtdcQryLoginForbiddenUserField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.UserID, input->UserID, sizeof(field.UserID));
	return field;
}
CTPTradeApi::CThostFtdcMulticastGroupInfoField KStoCTPChange(KingstarAPI::CThostFtdcMulticastGroupInfoField *input)
{
	CTPTradeApi::CThostFtdcMulticastGroupInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.GroupIP, input->GroupIP, sizeof(field.GroupIP));
	localmemcpy(field.GroupPort, input->GroupPort, sizeof(field.GroupPort));
	localmemcpy(field.SourceIP, input->SourceIP, sizeof(field.SourceIP));
	return field;
}
KingstarAPI::CThostFtdcMulticastGroupInfoField CTPtoKSChange(CTPTradeApi::CThostFtdcMulticastGroupInfoField *input)
{
	KingstarAPI::CThostFtdcMulticastGroupInfoField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.GroupIP, input->GroupIP, sizeof(field.GroupIP));
	localmemcpy(field.GroupPort, input->GroupPort, sizeof(field.GroupPort));
	localmemcpy(field.SourceIP, input->SourceIP, sizeof(field.SourceIP));
	return field;
}
CTPTradeApi::CThostFtdcTradingAccountReserveField KStoCTPChange(KingstarAPI::CThostFtdcTradingAccountReserveField *input)
{
	CTPTradeApi::CThostFtdcTradingAccountReserveField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Reserve, input->Reserve, sizeof(field.Reserve));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}
KingstarAPI::CThostFtdcTradingAccountReserveField CTPtoKSChange(CTPTradeApi::CThostFtdcTradingAccountReserveField *input)
{
	KingstarAPI::CThostFtdcTradingAccountReserveField field;
	memset(&field, 0, sizeof(field));
	localmemcpy(field.BrokerID, input->BrokerID, sizeof(field.BrokerID));
	localmemcpy(field.AccountID, input->AccountID, sizeof(field.AccountID));
	localmemcpy(field.Reserve, input->Reserve, sizeof(field.Reserve));
	localmemcpy(field.CurrencyID, input->CurrencyID, sizeof(field.CurrencyID));
	return field;
}

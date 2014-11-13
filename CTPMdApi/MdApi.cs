using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.Reflection;


namespace CTPMdApi
{
	/// <summary>
	/// 行情接口
	/// </summary>
	public class MdApi
	{
		const string strDllFile = "MdApi.dll";

		/// <summary>
		/// MdApi.dll/CTPMdApi.dll/thostmduserapi.dll 放在主程序的执行文件夹中
		/// </summary>
		/// <param name="_investor">投资者帐号:海风351962</param>
		/// <param name="_pwd">密码</param>
		/// <param name="_broker">经纪公司代码:2030-CTP模拟</param>
		/// <param name="_addr">前置地址:默认为CTP模拟</param>
        /// <param name="_FlowPath"></param>
		public MdApi(string _investor, string _pwd, string _broker = "2030"
            , string _addr = "tcp://asp-sim2-md1.financial-trading-platform.com:26213", string _FlowPath =null)
		{
			this.FrontAddr = _addr;
			this.BrokerID = _broker;
			this.InvestorID = _investor;
			this.password = _pwd;
            this.FlowPath = _FlowPath;
		}

		/// <summary>
		/// 前置地址
		/// </summary>
		public string FrontAddr { get; set; }
		/// <summary>
		/// 经纪公司代码ctp-2030;上期-4030;
		/// </summary>
		public string BrokerID { get; set; }
		/// <summary>
		/// 投资者代码 351962-申万
		/// </summary>
		public string InvestorID { get; set; }
		/// <summary>
		/// 密码
		/// </summary>
		private string password;
        private string FlowPath;

		/// <summary>
		/// 获取当前交易日:只有登录成功后,才能得到正确的交易日
		/// </summary>
		/// <returns></returns>
		public string GetTradingDay() { return getTradingDay(); }
		[DllImport(strDllFile, EntryPoint = "?GetTradingDay@@YAPBDXZ", CallingConvention = CallingConvention.Cdecl)]
		static extern string getTradingDay();
		
		/// <summary>
		/// 登录
		/// </summary>
        public void Connect() { connect(this.FrontAddr, this.FlowPath); }
        [DllImport(strDllFile, EntryPoint = "?Connect@@YAXPAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern void connect(string pFrontAddr,string FlowPath);

		/// <summary>
		/// 断开连接
		/// </summary>
		public void DisConnect() { disConnect(); }
		[DllImport(strDllFile, EntryPoint = "?DisConnect@@YAXXZ", CallingConvention = CallingConvention.Cdecl)]
		static extern void disConnect();

		/// <summary>
		/// 登录
		/// </summary>
		public void UserLogin() { userLogin(this.BrokerID, this.InvestorID, this.password); }
		[DllImport(strDllFile, EntryPoint = "?ReqUserLogin@@YAXQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern void userLogin(string BROKER_ID, string INVESTOR_ID, string PASSWORD);

		/// <summary>
		/// 用户注销
		/// </summary>
		public void UserLogout() { userLogout(this.BrokerID, this.InvestorID); }
		[DllImport(strDllFile, EntryPoint = "?ReqUserLogout@@YAXQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern void userLogout(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 订阅行情
		/// </summary>
		/// <param name="instruments">合约代码:可填多个,订阅所有填null</param>
		public void SubMarketData(params string[] instruments) { subMarketData(instruments, instruments == null ? 0 : instruments.Length); }
		[DllImport(strDllFile, EntryPoint = "?SubMarketData@@YAXQAPADH@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern void subMarketData(string[] instrumentsID, int nCount);

		/// <summary>
		/// 退订行情
		/// </summary>
		/// <param name="instruments">合约代码:可填多个,退订所有填null</param>
		public void UnSubMarketData(params string[] instruments) { unSubMarketData(instruments, instruments == null ? 0 : instruments.Length); }
		[DllImport(strDllFile, EntryPoint = "?UnSubscribeMarketData@@YAXQAPADH@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern void unSubMarketData(string[] ppInstrumentID, int nCount);

		//回调函数 ==================================================================================================================
		#region 错误响应
		[DllImport(strDllFile, EntryPoint = "?RegOnRspError@@YGXP6GHPAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnRspError(RspError cb);
		RspError rspError;
		/// <summary>
		/// 
		/// </summary>
		public delegate void RspError(ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 连接响应
		/// </summary>
		public event RspError OnRspError
		{
			add { rspError += value; regOnRspError(rspError); }
			remove { rspError -= value; regOnRspError(rspError); }

		}
		#endregion

		#region 心跳响应
		[DllImport(strDllFile, EntryPoint = "?RegOnHeartBeatWarning@@YGXP6GHH@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnHeartBeatWarning(HeartBeatWarning cb);
		HeartBeatWarning heartBeatWarning;
		/// <summary>
		/// 
		/// </summary>
		public delegate void HeartBeatWarning(int nTimeLapse);
		/// <summary>
		/// 心跳响应
		/// </summary>
		public event HeartBeatWarning OnHeartBeatWarning
		{
			add { heartBeatWarning += value; regOnHeartBeatWarning(heartBeatWarning); }
			remove { heartBeatWarning -= value; regOnHeartBeatWarning(heartBeatWarning); }

		}
		#endregion

		#region 连接响应
		[DllImport(strDllFile, EntryPoint = "?RegOnFrontConnected@@YGXP6GHXZ@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnFrontConnected(FrontConnected cb);
		FrontConnected frontConnected;
		/// <summary>
		/// 
		/// </summary>
		public delegate void FrontConnected();
		/// <summary>
		/// 连接响应
		/// </summary>
		public event FrontConnected OnFrontConnected
		{
			add { frontConnected += value; regOnFrontConnected(frontConnected); }
			remove { frontConnected -= value; regOnFrontConnected(frontConnected); }

		}
		#endregion

		#region 断开应答
		[DllImport(strDllFile, EntryPoint = "?RegOnFrontDisconnected@@YGXP6GHH@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnFrontDisconnected(FrontDisconnected cb);
		FrontDisconnected frontDisconnected;
		/// <summary>
		/// 
		/// </summary>
		public delegate void FrontDisconnected(int nReason);
		/// <summary>
		/// 断开应答
		/// </summary>
		public event FrontDisconnected OnFrontDisconnected
		{
			add { frontDisconnected += value; regOnFrontDisconnected(frontDisconnected); }
			remove { frontDisconnected -= value; regOnFrontDisconnected(frontDisconnected); }
		}
		#endregion

		#region 登入请求应答
		[DllImport(strDllFile, EntryPoint = "?RegOnRspUserLogin@@YGXP6GHPAUCThostFtdcRspUserLoginField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnRspUserLogin(RspUserLogin cb);
		RspUserLogin rspUserLogin;
		/// <summary>
		/// 
		/// </summary>
		public delegate void RspUserLogin(ref CThostFtdcRspUserLoginField pRspUserLogin, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 登入请求应答
		/// </summary>
		public event RspUserLogin OnRspUserLogin
		{
			add { rspUserLogin += value; regOnRspUserLogin(rspUserLogin); }
			remove { rspUserLogin -= value; regOnRspUserLogin(rspUserLogin); }
		}
		#endregion

		#region 登出请求应答
		[DllImport(strDllFile, EntryPoint = "?RegOnRspUserLogout@@YGXP6GHPAUCThostFtdcUserLogoutField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnRspUserLogout(RspUserLogout cb);
		RspUserLogout rspUserLogout;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="pUserLogout"></param>
		/// <param name="pRspInfo"></param>
		/// <param name="nRequestID"></param>
		/// <param name="bIsLast"></param>
		public delegate void RspUserLogout(ref CThostFtdcUserLogoutField pUserLogout, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 登出请求应答
		/// </summary>
		public event RspUserLogout OnRspUserLogout
		{
			add { rspUserLogout += value; regOnRspUserLogout(rspUserLogout); }
			remove { rspUserLogout -= value; regOnRspUserLogout(rspUserLogout); }
		}
		#endregion

		#region 订阅行情应答
		[DllImport(strDllFile, EntryPoint = "?RegOnRspSubMarketData@@YGXP6GHPAUCThostFtdcSpecificInstrumentField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnRspSubMarketData(RspSubMarketData cb);
		RspSubMarketData rspSubMarketData;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="pSpecificInstrument"></param>
		/// <param name="pRspInfo"></param>
		/// <param name="nRequestID"></param>
		/// <param name="bIsLast"></param>
		public delegate void RspSubMarketData(ref CThostFtdcSpecificInstrumentField pSpecificInstrument, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 订阅行情应答
		/// </summary>
		public event RspSubMarketData OnRspSubMarketData
		{
			add { rspSubMarketData += value; regOnRspSubMarketData(rspSubMarketData); }
			remove { rspSubMarketData -= value; regOnRspSubMarketData(rspSubMarketData); }
		}
		#endregion

		#region 退订请求应答
		[DllImport(strDllFile, EntryPoint = "?RegOnRspUnSubMarketData@@YGXP6GHPAUCThostFtdcSpecificInstrumentField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnRspUnSubMarketData(RspUnSubMarketData cb);
		RspUnSubMarketData rspUnSubMarketData;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="pSpecificInstrument"></param>
		/// <param name="pRspInfo"></param>
		/// <param name="nRequestID"></param>
		/// <param name="bIsLast"></param>
		public delegate void RspUnSubMarketData(ref CThostFtdcSpecificInstrumentField pSpecificInstrument, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 退订请求应答
		/// </summary>
		public event RspUnSubMarketData OnRspUnSubMarketData
		{
			add { rspUnSubMarketData += value; regOnRspUnSubMarketData(rspUnSubMarketData); }
			remove { rspUnSubMarketData -= value; regOnRspUnSubMarketData(rspUnSubMarketData); }
		}
		#endregion

		#region 深度行情通知
		[DllImport(strDllFile, EntryPoint = "?RegOnRtnDepthMarketData@@YGXP6GHPAUCThostFtdcDepthMarketDataField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnRtnDepthMarketData(RtnDepthMarketData cb);
		RtnDepthMarketData rtnDepthMarketData;

		/// <summary>
		/// 
		/// </summary>
		/// <param name="pDepthMarketData"></param>
		public delegate void RtnDepthMarketData(ref CThostFtdcDepthMarketDataField pDepthMarketData);
		/// <summary>
		/// 深度行情通知
		/// </summary>
		public event RtnDepthMarketData OnRtnDepthMarketData
		{
			add { rtnDepthMarketData += value; regOnRtnDepthMarketData(rtnDepthMarketData); }
			remove { rtnDepthMarketData -= value; regOnRtnDepthMarketData(rtnDepthMarketData); }
		}
		#endregion
	}
}

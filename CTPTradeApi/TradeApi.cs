using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace CTPTradeApi
{
	/// <summary>
	/// 交易接口
	/// </summary>
	public class TradeApi
	{
		const string dllName = "TradeApi.dll";

		/// <summary>
		/// TradeApi.dll/CTPTradeApi.dll/thosttraderapi.dll 放在主程序的执行文件夹中
		/// </summary>
		/// <param name="_investor">投资者帐号:海风351962</param>
		/// <param name="_pwd">密码</param>
		/// <param name="_broker">经纪公司代码:2030-CTP模拟</param>
		/// <param name="_addr">前置地址:默认为CTP模拟</param>
		public TradeApi(string _investor, string _pwd, string _broker = "2030"
            , string _addr = "tcp://asp-sim2-front1.financial-trading-platform.com:26205", string _FlowPath ="")
		{
			this.FrontAddr = _addr;
			this.BrokerID = _broker;
			this.InvestorID = _investor;
			this.passWord = _pwd;
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
		/// 投资者代码
		/// </summary>
		public string InvestorID { get; set; }

		/// <summary>
		/// 前置编号
		/// </summary>
		public int FrontID { get; set; }

		/// <summary>
		/// 会话编号
		/// </summary>
		public int SessionID { get; set; }

		/// <summary>
		/// 最大报单引用
		/// </summary>
		public int MaxOrderRef { get; set; }

		private string passWord;
        private string FlowPath;
		
		/// <summary>
		/// 登录
		/// </summary>
        public void Connect() { connect(this.FrontAddr, this.FlowPath); }
        [DllImport(dllName, EntryPoint = "?Connect@@YAXPAD0@Z", CallingConvention = CallingConvention.Cdecl)]
        static extern void connect(string FrontAddr, string FlowPath);

		/// <summary>
		/// 断开
		/// </summary>
		public void DisConnect() { disConnect(); }
		[DllImport(dllName, EntryPoint = "?DisConnect@@YAXXZ", CallingConvention = CallingConvention.Cdecl)]
		static extern void disConnect();

		/// <summary>
		/// 获取交易日
		/// </summary>
		/// <returns></returns>
		public string GetTradingDay()
		{ return getTradingDay(); }
		[DllImport(dllName, EntryPoint = "?GetTradingDay@@YAPBDXZ", CallingConvention = CallingConvention.Cdecl)]
		static extern string getTradingDay();


        /// <summary>
        /// 获取RequestID
        /// </summary>
        /// <returns></returns>
        public int GetRequestID()
        { return getRequestID(); }
        [DllImport(dllName, EntryPoint = "?GetRequestID@@YAHXZ", CallingConvention = CallingConvention.Cdecl)]
        static extern int getRequestID();

		/// <summary>
		/// 登入请求
		/// </summary>
		public int UserLogin() { return reqUserLogin(this.BrokerID, this.InvestorID, this.passWord); }
		[DllImport(dllName, EntryPoint = "?ReqUserLogin@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqUserLogin(string BROKER_ID, string INVESTOR_ID, string PASSWORD);

		/// <summary>
		/// 发送登出请求
		/// </summary>
		public int UserLogout() { return reqUserLogout(this.BrokerID, this.InvestorID); }
		[DllImport(dllName, EntryPoint = "?ReqUserLogout@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqUserLogout(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 更新用户口令
		/// </summary>
		/// <param name="userID"></param>
		/// <param name="oldPassword"></param>
		/// <param name="newPassword"></param>
		public int UserPasswordupdate(string userID, string oldPassword, string newPassword)
		{ return reqUserPasswordUpdate(this.BrokerID, userID, oldPassword, newPassword); }
		[DllImport(dllName, EntryPoint = "?ReqUserPasswordUpdate@@YAHQAD000@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqUserPasswordUpdate(string BROKER_ID, string USER_ID, string OLD_PASSWORD, string NEW_PASSWORD);

		/// <summary>
		/// 资金账户口令更新请求
		/// </summary>
		/// <param name="accountID"></param>
		/// <param name="oldPassword"></param>
		/// <param name="newPassword"></param>
		public int TradingAccountPasswordUpdate(string accountID, string oldPassword, string newPassword)
		{ return reqTradingAccountPasswordUpdate(this.BrokerID, accountID, oldPassword, newPassword); }
		[DllImport(dllName, EntryPoint = "?ReqTradingAccountPasswordUpdate@@YAHQAD000@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqTradingAccountPasswordUpdate(string BROKER_ID, string ACCOUNT_ID, string OLD_PASSWORD, string NEW_PASSWORD);

		/// <summary>
		/// 下单:录入报单
		/// </summary>
		/// <param name="order">输入的报单</param>
		public int OrderInsert(CThostFtdcInputOrderField order) { return reqOrderInsert(ref order); }
		/// <summary>
		/// 开平仓:限价单
		/// </summary>
		/// <param name="InstrumentID">合约代码</param>
		/// <param name="OffsetFlag">平仓:仅上期所平今时使用CloseToday/其它情况均使用Close</param>
		/// <param name="Direction">买卖</param>
		/// <param name="Price">价格</param>
		/// <param name="Volume">手数</param>
		public int OrderInsert(string InstrumentID, TThostFtdcOffsetFlagType OffsetFlag, TThostFtdcDirectionType Direction, double Price, int Volume)
		{
			CThostFtdcInputOrderField tmp = new CThostFtdcInputOrderField();
			tmp.BrokerID = this.BrokerID;
			tmp.BusinessUnit = null;
			tmp.ContingentCondition = TThostFtdcContingentConditionType.Immediately;
			tmp.ForceCloseReason = TThostFtdcForceCloseReasonType.NotForceClose;
			tmp.InvestorID = this.InvestorID;
			tmp.IsAutoSuspend = (int)TThostFtdcBoolType.No;
			tmp.MinVolume = 1;
			tmp.OrderPriceType = TThostFtdcOrderPriceTypeType.LimitPrice;
			tmp.OrderRef = (++this.MaxOrderRef).ToString();
			tmp.TimeCondition = TThostFtdcTimeConditionType.GFD;	//当日有效
			tmp.UserForceClose = (int)TThostFtdcBoolType.No;
			tmp.UserID = this.InvestorID;
			tmp.VolumeCondition = TThostFtdcVolumeConditionType.AV;
			tmp.CombHedgeFlag_0 = TThostFtdcHedgeFlagType.Speculation;

			tmp.InstrumentID = InstrumentID;
			tmp.CombOffsetFlag_0 = OffsetFlag;
			tmp.Direction = Direction;
			tmp.LimitPrice = Price;
			tmp.VolumeTotalOriginal = Volume;
			return reqOrderInsert(ref tmp);
		}
		/// <summary>
		/// 开平仓:市价单
		/// </summary>
		/// <param name="InstrumentID"></param>
		/// <param name="OffsetFlag">平仓:仅上期所平今时使用CloseToday/其它情况均使用Close</param>
		/// <param name="Direction"></param>
		/// <param name="Volume"></param>
        public int OrderInsert(string InstrumentID, TThostFtdcOffsetFlagType OffsetFlag, TThostFtdcDirectionType Direction, int Volume)
		{
			CThostFtdcInputOrderField tmp = new CThostFtdcInputOrderField();
			tmp.BrokerID = this.BrokerID;
			tmp.BusinessUnit = null;
			tmp.ContingentCondition = TThostFtdcContingentConditionType.Immediately;
			tmp.ForceCloseReason = TThostFtdcForceCloseReasonType.NotForceClose;
			tmp.InvestorID = this.InvestorID;
			tmp.IsAutoSuspend = (int)TThostFtdcBoolType.No;
			tmp.MinVolume = 1;
			tmp.OrderPriceType = TThostFtdcOrderPriceTypeType.AnyPrice;
			tmp.OrderRef = (++this.MaxOrderRef).ToString();
			tmp.TimeCondition = TThostFtdcTimeConditionType.IOC;	//立即完成,否则撤单
			tmp.UserForceClose = (int)TThostFtdcBoolType.No;
			tmp.UserID = this.InvestorID;
			tmp.VolumeCondition = TThostFtdcVolumeConditionType.AV;
			tmp.CombHedgeFlag_0 = TThostFtdcHedgeFlagType.Speculation;

			tmp.InstrumentID = InstrumentID;
			tmp.CombOffsetFlag_0 = OffsetFlag;
			tmp.Direction = Direction;
			tmp.LimitPrice = 0;
			tmp.VolumeTotalOriginal = Volume;
			return reqOrderInsert(ref tmp);
		}
		/// <summary>
		/// 开平仓:触发单
		/// </summary>
		/// <param name="InstrumentID"></param>
		/// <param name="ConditionType">触发单类型</param>
		/// <param name="ConditionPrice">触发价格</param>
		/// <param name="OffsetFlag">平仓:仅上期所平今时使用CloseToday/其它情况均使用Close</param>
		/// <param name="Direction"></param>
		/// <param name="PriceType">下单类型</param>
		/// <param name="Price">下单价格:仅当下单类型为LimitPrice时有效</param>
		/// <param name="Volume"></param>
		public int OrderInsert(string InstrumentID, TThostFtdcContingentConditionType ConditionType
			, double ConditionPrice, TThostFtdcOffsetFlagType OffsetFlag, TThostFtdcDirectionType Direction, TThostFtdcOrderPriceTypeType PriceType, double Price, int Volume)
		{
			CThostFtdcInputOrderField tmp = new CThostFtdcInputOrderField();
			tmp.BrokerID = this.BrokerID;
			tmp.BusinessUnit = null;
			tmp.ForceCloseReason = TThostFtdcForceCloseReasonType.NotForceClose;
			tmp.InvestorID = this.InvestorID;
			tmp.IsAutoSuspend = (int)TThostFtdcBoolType.No;
			tmp.MinVolume = 1;
			tmp.OrderRef = (++this.MaxOrderRef).ToString();
			tmp.TimeCondition = TThostFtdcTimeConditionType.GFD;
			tmp.UserForceClose = (int)TThostFtdcBoolType.No;
			tmp.UserID = this.InvestorID;
			tmp.VolumeCondition = TThostFtdcVolumeConditionType.AV;
			tmp.CombHedgeFlag_0 = TThostFtdcHedgeFlagType.Speculation;

			tmp.InstrumentID = InstrumentID;
			tmp.CombOffsetFlag_0 = OffsetFlag;
			tmp.Direction = Direction;
			tmp.ContingentCondition = ConditionType;	//触发类型
			tmp.StopPrice = Price;						//触发价格
			tmp.OrderPriceType = PriceType;				//下单类型
			tmp.LimitPrice = Price;						//下单价格:Price = LimitPrice 时有效
			tmp.VolumeTotalOriginal = Volume;
			return reqOrderInsert(ref tmp);
		}
		[DllImport(dllName, EntryPoint = "?ReqOrderInsert@@YAHPAUCThostFtdcInputOrderField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqOrderInsert(ref CThostFtdcInputOrderField req);
        /// <summary>
        /// 撤单
        /// </summary>
        /// <param name="InstrumentID"></param>
        /// <param name="FrontID"></param>
        /// <param name="SessionID"></param>
        /// <param name="OrderRef"></param>
        /// <param name="ExchangeID"></param>
        /// <param name="OrderSysID"></param>
        public int OrderAction(CThostFtdcInputOrderActionField poa)
        {
            return reqOrderAction(ref poa);
        }
		/// <summary>
		/// 撤单
		/// </summary>
		/// <param name="InstrumentID"></param>
		/// <param name="FrontID"></param>
		/// <param name="SessionID"></param>
		/// <param name="OrderRef"></param>
		/// <param name="ExchangeID"></param>
		/// <param name="OrderSysID"></param>
		public int OrderAction(string InstrumentID, int FrontID = 0, int SessionID = 0, string OrderRef = "0", string ExchangeID = null, string OrderSysID = null)
		{
			CThostFtdcInputOrderActionField tmp = new CThostFtdcInputOrderActionField();
			tmp.ActionFlag = TThostFtdcActionFlagType.Delete;
			tmp.BrokerID = this.BrokerID;
			tmp.InvestorID = this.InvestorID;
			//tmp.UserID = this.InvestorID;
			tmp.InstrumentID = InstrumentID;
			//tmp.VolumeChange = int.Parse(lvi.SubItems["VolumeTotalOriginal"].Text);
			if (FrontID != 0)
				tmp.FrontID = FrontID;
			if (SessionID != 0)
				tmp.SessionID = SessionID;
			if (OrderRef != "0")
				tmp.OrderRef = OrderRef;
			tmp.ExchangeID = ExchangeID;
			if (OrderSysID != null)
				tmp.OrderSysID = new string('\0', 21 - OrderSysID.Length) + OrderSysID;	//OrderSysID右对齐
			return reqOrderAction(ref tmp);
		}
		[DllImport(dllName, EntryPoint = "?ReqOrderAction@@YAHPAUCThostFtdcInputOrderActionField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqOrderAction(ref CThostFtdcInputOrderActionField pOrder);

		/// <summary>
		/// 查询最大允许报单数量请求
		/// </summary>
		/// <param name="pMaxOrderVolume"></param>
		public int QueryMaxOrderVolume(CThostFtdcQueryMaxOrderVolumeField pMaxOrderVolume)
		{ return reqQueryMaxOrderVolume(ref pMaxOrderVolume); }
		[DllImport(dllName, EntryPoint = "?ReqQueryMaxOrderVolume@@YAHPAUCThostFtdcQueryMaxOrderVolumeField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQueryMaxOrderVolume(ref CThostFtdcQueryMaxOrderVolumeField pMaxOrderVolume);

		/// <summary>
		/// 确认结算结果
		/// </summary>
		/// <s></s>
		public int SettlementInfoConfirm() { return reqSettlementInfoConfirm(this.BrokerID, this.InvestorID); }
		[DllImport(dllName, EntryPoint = "?ReqSettlementInfoConfirm@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqSettlementInfoConfirm(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 请求查询报单:不填-查所有
		/// </summary>
		/// <param name="_exchangeID"></param>
		/// <param name="_timeStart"></param>
		/// <param name="_timeEnd"></param>
		/// <param name="_instrumentID"></param>
		/// <param name="_orderSysID"></param>
		public int QryOrder(string _exchangeID = null, string _timeStart = null, string _timeEnd = null
			, string _instrumentID = null, string _orderSysID = null)
		{
			CThostFtdcQryOrderField tmp = new CThostFtdcQryOrderField();
			tmp.BrokerID = this.BrokerID;
			tmp.InvestorID = this.InvestorID;
			tmp.ExchangeID = _exchangeID;
			tmp.InsertTimeStart = _timeStart;
			tmp.InsertTimeEnd = _timeEnd;
			tmp.InstrumentID = _instrumentID;
			tmp.OrderSysID = _orderSysID;
			return reqQryOrder(ref tmp);
		}
		[DllImport(dllName, EntryPoint = "?ReqQryOrder@@YAHPAUCThostFtdcQryOrderField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryOrder(ref CThostFtdcQryOrderField pQryOrder);

		/// <summary>
		///  请求查询成交:不填-查所有
		/// </summary>
		/// <param name="_exchangeID"></param>
		/// <param name="_timeStart"></param>
		/// <param name="_timeEnd"></param>
		/// <param name="_instrumentID"></param>
		/// <param name="_tradeID"></param>
		public int QryTrade(DateTime? _timeStart = null, DateTime? _timeEnd = null
			, string _instrumentID = null,string _exchangeID = null,  string _tradeID = null)
		{
			CThostFtdcQryTradeField tmp = new CThostFtdcQryTradeField();
			tmp.BrokerID = this.BrokerID;
			tmp.InvestorID = this.InvestorID;
			tmp.ExchangeID = _exchangeID;
			tmp.TradeTimeStart = _timeStart == null ? null : _timeStart.Value.ToString("HH:mm:ss");
			tmp.TradeTimeEnd = _timeEnd == null ? null : _timeEnd.Value.ToString("HH:mm:ss");
			tmp.InstrumentID = _instrumentID;
			tmp.TradeID = _tradeID;
			return reqQryTrade(ref tmp);
		}
        /// <summary>
        ///  请求查询成交:不填-查所有
        /// </summary>
        /// <param name="_exchangeID"></param>
        /// <param name="_timeStart"></param>
        /// <param name="_timeEnd"></param>
        /// <param name="_instrumentID"></param>
        /// <param name="_tradeID"></param>
        public int QryTrade(string _timeStart = null, string _timeEnd = null
            , string _instrumentID = null, string _exchangeID = null, string _tradeID = null)
        {
            CThostFtdcQryTradeField tmp = new CThostFtdcQryTradeField();
            tmp.BrokerID = this.BrokerID;
            tmp.InvestorID = this.InvestorID;
            tmp.ExchangeID = _exchangeID;
            tmp.TradeTimeStart = _timeStart;
            tmp.TradeTimeEnd = _timeEnd ;
            tmp.InstrumentID = _instrumentID;
            tmp.TradeID = _tradeID;
            return reqQryTrade(ref tmp);
        }
		[DllImport(dllName, EntryPoint = "?ReqQryTrade@@YAHPAUCThostFtdcQryTradeField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryTrade(ref CThostFtdcQryTradeField pQryTrade);

		/// <summary>
		/// 查询投资者持仓
		/// </summary>
		/// <param name="instrument">合约代码:不填-查所有</param>
		public int QryInvestorPosition(string instrument = null)
		{ return reqQryInvestorPosition(this.BrokerID, this.InvestorID, instrument); }
		[DllImport(dllName, EntryPoint = "?ReqQryInvestorPosition@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryInvestorPosition(string BROKER_ID, string INVESTOR_ID, string Instrument);

		/// <summary>
		/// 查询帐户资金请求
		/// </summary>
		public int QryTradingAccount() { return reqQryTradingAccount(this.BrokerID, this.InvestorID); }
		[DllImport(dllName, EntryPoint = "?ReqQryTradingAccount@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryTradingAccount(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 请求查询投资者
		/// </summary>
		public int QryInvestor() { return reqQryInvestor(this.BrokerID, this.InvestorID); }
		[DllImport(dllName, EntryPoint = "?ReqQryInvestor@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryInvestor(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 请求查询交易编码:参数不填-查所有
		/// </summary>
		/// <param name="clientID">客户ID</param>
		/// <param name="exchangeID">交易所ID</param>
		public int QryTradingCode(string clientID = null, string exchangeID = null)
		{ return reqQryTradingCode(this.BrokerID, this.InvestorID, clientID, exchangeID); }
		[DllImport(dllName, EntryPoint = "?ReqQryTradingCode@@YAHQAD000@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryTradingCode(string BROKER_ID, string INVESTOR_ID, string CLIENT_ID, string EXCHANGE_ID);

		/// <summary>
		/// 请求查询合约保证金率:能为null;每次只能查一个合约
		/// </summary>
		/// <param name="hedgeFlag">投机/套保</param>
		/// <param name="instrumentID">合约代码:不填-查所有</param>
		public int QryInstrumentMarginRate(string instrumentID,TThostFtdcHedgeFlagType hedgeFlag = TThostFtdcHedgeFlagType.Speculation)
		{ 
			return reqQryInstrumentMarginRate(this.BrokerID, this.InvestorID, instrumentID, hedgeFlag); 
		}
		[DllImport(dllName, EntryPoint = "?ReqQryInstrumentMarginRate@@YAHQAD00D@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryInstrumentMarginRate(string BROKER_ID, string INVESTOR_ID, string INSTRUMENT_ID, TThostFtdcHedgeFlagType HEDGE_FLAG);

		/// <summary>
		/// 请求查询合约手续费率
		/// </summary>
		/// <param name="instrumentID">合约代码</param>
		public int QryInstrumentCommissionRate(string instrumentID)
		{ return reqQryInstrumentCommissionRate(this.BrokerID, this.InvestorID, instrumentID); }
		[DllImport(dllName, EntryPoint = "?ReqQryInstrumentCommissionRate@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryInstrumentCommissionRate(string BROKER_ID, string INVESTOR_ID, string INSTRUMENT_ID);

		/// <summary>
		/// 请求查询交易所
		/// </summary>
		/// <param name="exchangeID"></param>
		public int QryExchange(string exchangeID) { return reqQryExchange(exchangeID); }
		[DllImport(dllName, EntryPoint = "?ReqQryExchange@@YAHQAD@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryExchange(string EXCHANGE_ID);

		/// <summary>
		/// 查询合约
		/// </summary>
		/// <param name="instrument">合约代码:不填-查所有</param>
		public int QryInstrument(string instrument = null) { return reqQryInstrument(instrument); }
		[DllImport(dllName, EntryPoint = "?ReqQryInstrument@@YAHQAD@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryInstrument(string Instrument);

		/// <summary>
		/// 查询行情
		/// </summary>
		/// <param name="instrument">合约代码</param>
		public int QryDepthMarketData(string instrument) { return reqQryDepthMarketData(instrument); }
		[DllImport(dllName, EntryPoint = "?ReqQryDepthMarketData@@YAHQAD@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryDepthMarketData(string Instrument);

		/// <summary>
		/// 请求查询投资者结算结果
		/// </summary>
		public int QrySettlementInfo(string _date=null)
		{ return reqQrySettlementInfo(this.BrokerID, this.InvestorID, _date); }// tradingDay.ToString("yyyyMMdd")); }
		[DllImport(dllName, EntryPoint = "?ReqQrySettlementInfo@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQrySettlementInfo(string BROKER_ID, string INVESTOR_ID, string TRADING_DAY);

		/// <summary>
		/// 查询投资者持仓明细
		/// </summary>
		/// <param name="instrument">合约代码:不填-查所有</param>
		public int QryInvestorPositionDetail(string instrument = null)
		{ return reqQryInvestorPositionDetail(this.BrokerID, this.InvestorID, instrument); }
		[DllImport(dllName, EntryPoint = "?ReqQryInvestorPositionDetail@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryInvestorPositionDetail(string BROKER_ID, string INVESTOR_ID, string Instrument);

		/// <summary>
		/// 请求查询客户通知
		/// </summary>
		public int QryNotice() { return reqQryNotice(this.BrokerID); }
		[DllImport(dllName, EntryPoint = "?ReqQryNotice@@YAHQAD@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryNotice(string BROKERID);

		/// <summary>
		/// 请求查询结算信息确认
		/// </summary>
		public int QrySettlementInfoConfirm()
		{ return reqQrySettlementInfoConfirm(this.BrokerID, this.InvestorID); }
		[DllImport(dllName, EntryPoint = "?ReqQrySettlementInfoConfirm@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQrySettlementInfoConfirm(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 请求查询**组合**持仓明细
		/// </summary>
		/// <param name="instrumentID">合约代码:不填-查所有</param>
		public int QryInvestorPositionCombinaDetail(string instrumentID = null)
		{ return reqQryInvestorPositionCombineDetail(this.BrokerID, this.InvestorID, instrumentID); }
		[DllImport(dllName, EntryPoint = "?ReqQryInvestorPositionCombineDetail@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryInvestorPositionCombineDetail(string BROKER_ID, string INVESTOR_ID, string INSTRUMENT_ID);

		/// <summary>
		/// 请求查询保证金监管系统经纪公司资金账户密钥
		/// </summary>
		public int QryCFMMCTradingAccountKey()
		{ return reqQryCFMMCTradingAccountKey(this.BrokerID, this.InvestorID); }
		[DllImport(dllName, EntryPoint = "?ReqQryCFMMCTradingAccountKey@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryCFMMCTradingAccountKey(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 请求查询交易通知
		/// </summary>
		public int QryTradingNotice()
		{ return reqQryTradingNotice(this.BrokerID, this.InvestorID); }
		[DllImport(dllName, EntryPoint = "?ReqQryTradingNotice@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryTradingNotice(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 请求查询经纪公司交易参数
		/// </summary>
		public int QryBrokerTradingParams()
		{ return reqQryBrokerTradingParams(this.BrokerID, this.InvestorID); }
		[DllImport(dllName, EntryPoint = "?ReqQryBrokerTradingParams@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryBrokerTradingParams(string BROKER_ID, string INVESTOR_ID);

		/// <summary>
		/// 请求查询经纪公司交易算法
		/// </summary>
		/// <param name="exchangeID">交易所代码</param>
		/// <param name="instrumentID">合约代码</param>
		public int QryBrokerTradingAlgos(string exchangeID, string instrumentID)
		{ return reqQryBrokerTradingAlgos(this.BrokerID, exchangeID, instrumentID); }
		[DllImport(dllName, EntryPoint = "?ReqQryBrokerTradingAlgos@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryBrokerTradingAlgos(string BROKER_ID, string EXCHANGE_ID, string INSTRUMENT_ID);

		/// <summary>
		/// 预埋单录入请求
		/// </summary>
		/// <param name="field"></param>
		public int ParkedOrderInsert(CThostFtdcParkedOrderField field)
		{ return reqParkedOrderInsert(ref field); }
		/// <summary>
		/// 预埋单录入请求
		/// </summary>
		/// <param name="InstrumentID"></param>
		/// <param name="OffsetFlag"></param>
		/// <param name="Direction"></param>
		/// <param name="Price"></param>
		/// <param name="Volume"></param>
		public int ParkedOrderInsert(string InstrumentID, TThostFtdcOffsetFlagType OffsetFlag, TThostFtdcDirectionType Direction, double Price, int Volume)
		{
			CThostFtdcParkedOrderField tmp = new CThostFtdcParkedOrderField();
			tmp.BrokerID = this.BrokerID;
			tmp.BusinessUnit = null;
			tmp.ContingentCondition = TThostFtdcContingentConditionType.ParkedOrder;
			tmp.ForceCloseReason = TThostFtdcForceCloseReasonType.NotForceClose;
			tmp.InvestorID = this.InvestorID;
			tmp.IsAutoSuspend = (int)TThostFtdcBoolType.No;
			tmp.MinVolume = 1;
			tmp.OrderPriceType = TThostFtdcOrderPriceTypeType.LimitPrice;
			tmp.OrderRef = (++this.MaxOrderRef).ToString();
			tmp.TimeCondition = TThostFtdcTimeConditionType.GFD;
			tmp.UserForceClose = (int)TThostFtdcBoolType.No;
			tmp.UserID = this.InvestorID;
			tmp.VolumeCondition = TThostFtdcVolumeConditionType.AV;
			tmp.CombHedgeFlag_0 = TThostFtdcHedgeFlagType.Speculation;

			tmp.InstrumentID = InstrumentID;
			tmp.CombOffsetFlag_0 = OffsetFlag;
			tmp.Direction = Direction;
			tmp.LimitPrice = Price;
			tmp.VolumeTotalOriginal = Volume;
			return reqParkedOrderInsert(ref tmp);
		}
		[DllImport(dllName, EntryPoint = "?ReqParkedOrderInsert@@YAHPAUCThostFtdcParkedOrderField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqParkedOrderInsert(ref CThostFtdcParkedOrderField pField);

		/// <summary>
		/// 预埋撤单录入请求
		/// </summary>
		/// <param name="field"></param>
		public int ReqParkedOrderAction(CThostFtdcParkedOrderActionField field)
		{ return reqParkedOrderAction(ref field); }
        /// <summary>
        /// 预埋撤单录入请求
        /// </summary>
        /// <param name="InstrumentID"></param>
        /// <param name="FrontID"></param>
        /// <param name="SessionID"></param>
        /// <param name="OrderRef"></param>
        /// <param name="ExchangeID"></param>
        /// <param name="OrderSysID"></param>
        /// <returns></returns>
		public int ReqParkedOrderAction(string InstrumentID, int FrontID, int SessionID, string OrderRef, string ExchangeID = null, string OrderSysID = null)
		{
			CThostFtdcParkedOrderActionField tmp = new CThostFtdcParkedOrderActionField();
			tmp.ActionFlag = TThostFtdcActionFlagType.Delete;
			tmp.BrokerID = this.BrokerID;
			tmp.InvestorID = this.InvestorID;
			//tmp.UserID = this.InvestorID;
			tmp.InstrumentID = InstrumentID;
			//tmp.VolumeChange = int.Parse(lvi.SubItems["VolumeTotalOriginal"].Text);

			tmp.FrontID = FrontID;
			tmp.SessionID = SessionID;
			tmp.OrderRef = OrderRef;
			tmp.ExchangeID = ExchangeID;
			if (OrderSysID != null)
				tmp.OrderSysID = new string('\0', 21 - OrderSysID.Length) + OrderSysID;	//OrderSysID右对齐
			return reqParkedOrderAction(ref tmp);
		}
		[DllImport(dllName, EntryPoint = "?ReqParkedOrderAction@@YAHPAUCThostFtdcParkedOrderActionField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqParkedOrderAction(ref CThostFtdcParkedOrderActionField pField);

		/// <summary>
		/// 请求删除预埋单
		/// </summary>
		/// <param name="BROKER_ID"></param>
		/// <param name="INVESTOR_ID"></param>
		/// <param name="ParkedOrder_ID"></param>
		public int ReqRemoveParkedOrder(string ParkedOrder_ID)
		{ return reqRemoveParkedOrder(this.BrokerID, this.InvestorID, ParkedOrder_ID); }
		[DllImport(dllName, EntryPoint = "?ReqRemoveParkedOrder@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqRemoveParkedOrder(string BROKER_ID, string INVESTOR_ID, string ParkedOrder_ID);

		/// <summary>
		/// 请求删除预埋撤单
		/// </summary>
		/// <param name="BROKER_ID"></param>
		/// <param name="INVESTOR_ID"></param>
		/// <param name="ParkedOrderAction_ID"></param>
		public int ReqRemoveParkedOrderAction(string ParkedOrderAction_ID)
		{ return reqRemoveParkedOrderAction(this.BrokerID, this.InvestorID, ParkedOrderAction_ID); }
		[DllImport(dllName, EntryPoint = "?ReqRemoveParkedOrderAction@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqRemoveParkedOrderAction(string BROKER_ID, string INVESTOR_ID, string ParkedOrderAction_ID);

		/// <summary>
		/// 请求查询转帐银行
		/// </summary>
		/// <param name="Bank_ID"></param>
		/// <param name="BankBrch_ID"></param>
		public int ReqQryTransferBank(string Bank_ID, string BankBrch_ID)
		{ return reqQryTransferBank(Bank_ID, BankBrch_ID); }
		[DllImport(dllName, EntryPoint = "?ReqQryTransferBank@@YAHQAD0@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryTransferBank(string Bank_ID, string BankBrch_ID);

		/// <summary>
		/// 请求查询转帐流水
		/// </summary>
		/// <param name="Broker_ID"></param>
		/// <param name="Account_ID"></param>
		/// <param name="Bank_ID"></param>
		public int ReqQryTransferSerial(string Bank_ID)
		{ return reqQryTransferSerial(this.BrokerID, this.InvestorID, Bank_ID); }
		[DllImport(dllName, EntryPoint = "?ReqQryTransferSerial@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryTransferSerial(string Broker_ID, string Account_ID, string Bank_ID);


        /// <summary>
        /// 请求查询银期签约关系
        /// </summary>
        /// <param name="Broker_ID"></param>
        /// <param name="Account_ID"></param>
        /// <param name="Bank_ID"></param>
        public int ReqQryAccountregister(string Bank_ID)
        { return reqQryAccountregister(this.BrokerID, this.InvestorID, Bank_ID); }
        [DllImport(dllName, EntryPoint = "?ReqQryAccountregister@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
        static extern int reqQryAccountregister(string Broker_ID, string Account_ID, string Bank_ID);


		/// <summary>
		/// 请求查询签约银行
		/// </summary>
		/// <param name="Broker_ID"></param>
		/// <param name="Bank_ID"></param>
		/// <param name="BankBrch_ID"></param>
		public int ReqQryContractBank()
		{ return reqQryContractBank(this.BrokerID, null, null); }
		[DllImport(dllName, EntryPoint = "?ReqQryContractBank@@YAHQAD00@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryContractBank(string Broker_ID, string Bank_ID, string BankBrch_ID);

		/// <summary>
		/// 请求查询预埋单
		/// </summary>
		/// <param name="Broker_ID"></param>
		/// <param name="Investor_ID"></param>
		/// <param name="Instrument_ID"></param>
		/// <param name="Exchange_ID"></param>
		public int ReqQryParkedOrder()
		{ return reqQryParkedOrder(this.BrokerID, this.InvestorID, null, null); }
		[DllImport(dllName, EntryPoint = "?ReqQryParkedOrder@@YAHQAD000@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryParkedOrder(string Broker_ID, string Investor_ID, string Instrument_ID, string Exchange_ID);

		/// <summary>
		/// 请求查询预埋撤单
		/// </summary>
		/// <param name="Broker_ID"></param>
		/// <param name="Investor_ID"></param>
		/// <param name="Instrument_ID"></param>
		/// <param name="Exchange_ID"></param>
		public int ReqQryParkedOrderAction()
		{ return reqQryParkedOrderAction(this.BrokerID, this.InvestorID, null, null); }
		[DllImport(dllName, EntryPoint = "?ReqQryParkedOrderAction@@YAHQAD000@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQryParkedOrderAction(string Broker_ID, string Investor_ID, string Instrument_ID, string Exchange_ID);

		/// <summary>
		/// 期货发起银行资金转期货请求
		/// </summary>
		/// <param name="field"></param>
		public int ReqFromBankToFutureByFuture(CThostFtdcReqTransferField field)
		{ return reqFromBankToFutureByFuture(ref field); }
		[DllImport(dllName, EntryPoint = "?ReqFromBankToFutureByFuture@@YAHPAUCThostFtdcReqTransferField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqFromBankToFutureByFuture(ref CThostFtdcReqTransferField pField);

		/// <summary>
		/// 期货发起期货资金转银行请求
		/// </summary>
		/// <param name="field"></param>
		public int ReqFromFutureToBankByFuture(CThostFtdcReqTransferField field)
		{ return reqFromFutureToBankByFuture(ref field); }
		[DllImport(dllName, EntryPoint = "?ReqFromFutureToBankByFuture@@YAHPAUCThostFtdcReqTransferField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqFromFutureToBankByFuture(ref CThostFtdcReqTransferField pField);

		/// <summary>
		/// 期货发起查询银行余额请求
		/// </summary>
		/// <param name="field"></param>
		public int ReqQueryBankAccountMoneyByFuture(CThostFtdcReqQueryAccountField field)
		{ return reqQueryBankAccountMoneyByFuture(ref field); }
		[DllImport(dllName, EntryPoint = "?ReqQueryBankAccountMoneyByFuture@@YAHPAUCThostFtdcReqQueryAccountField@@@Z", CallingConvention = CallingConvention.Cdecl)]
		static extern int reqQueryBankAccountMoneyByFuture(ref CThostFtdcReqQueryAccountField pField);

		//回调函数 =====================================================================================================================
		[DllImport(dllName, EntryPoint = "?RegOnFrontConnected@@YGXP6GHXZ@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnFrontConnected(FrontConnect fc);
		FrontConnect frontConnect;
		/// <summary>
		/// 
		/// </summary>
		public delegate void FrontConnect();
		/// <summary>
		/// 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
		/// </summary>
		public event FrontConnect OnFrontConnect
		{
			add { frontConnect += value; regOnFrontConnected(frontConnect); }
			remove { frontConnect -= value; regOnFrontConnected(frontConnect); }
		}

		[DllImport(dllName, EntryPoint = "?RegOnFrontDisconnected@@YGXP6GHH@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnDisConnected(DisConnected dc);
		DisConnected disConnected;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="reason"></param>
		public delegate void DisConnected(int reason);
		/// <summary>
		/// 当客户端与交易后台通信连接断开时，该方法被调用。当发生这个情况后，API会自动重新连接，客户端可不做处理。
		/// </summary>
		public event DisConnected OnDisConnected
		{
			add { disConnected += value; regOnDisConnected(disConnected); }
			remove { disConnected -= value; regOnDisConnected(disConnected); }
		}

		[DllImport(dllName, EntryPoint = "?RegOnHeartBeatWarning@@YGXP6GHH@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regOnHeartBeatWarning(HeartBeatWarning hbw);
		HeartBeatWarning heartBeatWarning;
		/// <summary>
		/// 
		/// </summary>
		/// <param name="pTimeLapes"></param>
		public delegate void HeartBeatWarning(int pTimeLapes);
		/// <summary>
		/// 心跳超时警告。当长时间未收到报文时，该方法被调用。
		/// </summary>
		public event HeartBeatWarning OnHeartBeatWarning
		{
			add { heartBeatWarning += value; regOnHeartBeatWarning(heartBeatWarning); }
			remove { heartBeatWarning -= value; regOnHeartBeatWarning(heartBeatWarning); }
		}

		///期货发起银行资金转期货错误回报
		[DllImport(dllName, EntryPoint = "?RegErrRtnBankToFutureByFuture@@YGXP6GHPAUCThostFtdcReqTransferField@@PAUCThostFtdcRspInfoField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regErrRtnBankToFutureByFuture(ErrRtnBankToFutureByFuture cb);
		ErrRtnBankToFutureByFuture errRtnBankToFutureByFuture;
		public delegate void ErrRtnBankToFutureByFuture(ref CThostFtdcReqTransferField pReqTransfer, ref CThostFtdcRspInfoField pRspInfo);
		/// <summary>
		/// 期货发起银行资金转期货错误回报
		/// </summary>
		public event ErrRtnBankToFutureByFuture OnErrRtnBankToFutureByFuture
		{
			add { errRtnBankToFutureByFuture += value; regErrRtnBankToFutureByFuture(errRtnBankToFutureByFuture); }
			remove { errRtnBankToFutureByFuture -= value; regErrRtnBankToFutureByFuture(errRtnBankToFutureByFuture); }
		}

		///期货发起期货资金转银行错误回报
		[DllImport(dllName, EntryPoint = "?RegErrRtnFutureToBankByFuture@@YGXP6GHPAUCThostFtdcReqTransferField@@PAUCThostFtdcRspInfoField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regErrRtnFutureToBankByFuture(ErrRtnFutureToBankByFuture cb);
		ErrRtnFutureToBankByFuture errRtnFutureToBankByFuture;
		public delegate void ErrRtnFutureToBankByFuture(ref CThostFtdcReqTransferField pReqTransfer, ref CThostFtdcRspInfoField pRspInfo);
		/// <summary>
		/// 期货发起期货资金转银行错误回报
		/// </summary>
		public event ErrRtnFutureToBankByFuture OnErrRtnFutureToBankByFuture
		{
			add { errRtnFutureToBankByFuture += value; regErrRtnFutureToBankByFuture(errRtnFutureToBankByFuture); }
			remove { errRtnFutureToBankByFuture -= value; regErrRtnFutureToBankByFuture(errRtnFutureToBankByFuture); }
		}

		///报单操作错误回报
		[DllImport(dllName, EntryPoint = "?RegErrRtnOrderAction@@YGXP6GHPAUCThostFtdcOrderActionField@@PAUCThostFtdcRspInfoField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regErrRtnOrderAction(ErrRtnOrderAction cb);
		ErrRtnOrderAction errRtnOrderAction;
		public delegate void ErrRtnOrderAction(ref CThostFtdcOrderActionField pOrderAction, ref CThostFtdcRspInfoField pRspInfo);
		/// <summary>
		/// 报单操作错误回报
		/// </summary>
		public event ErrRtnOrderAction OnErrRtnOrderAction
		{
			add { errRtnOrderAction += value; regErrRtnOrderAction(errRtnOrderAction); }
			remove { errRtnOrderAction -= value; regErrRtnOrderAction(errRtnOrderAction); }
		}

		///报单录入错误回报
		[DllImport(dllName, EntryPoint = "?RegErrRtnOrderInsert@@YGXP6GHPAUCThostFtdcInputOrderField@@PAUCThostFtdcRspInfoField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regErrRtnOrderInsert(ErrRtnOrderInsert cb);
		ErrRtnOrderInsert errRtnOrderInsert;
		public delegate void ErrRtnOrderInsert(ref CThostFtdcInputOrderField pInputOrder, ref CThostFtdcRspInfoField pRspInfo);
		/// <summary>
		/// 报单录入错误回报
		/// </summary>
		public event ErrRtnOrderInsert OnErrRtnOrderInsert
		{
			add { errRtnOrderInsert += value; regErrRtnOrderInsert(errRtnOrderInsert); }
			remove { errRtnOrderInsert -= value; regErrRtnOrderInsert(errRtnOrderInsert); }
		}

		///期货发起查询银行余额错误回报
		[DllImport(dllName, EntryPoint = "?RegErrRtnQueryBankBalanceByFuture@@YGXP6GHPAUCThostFtdcReqQueryAccountField@@PAUCThostFtdcRspInfoField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regErrRtnQueryBankBalanceByFuture(ErrRtnQueryBankBalanceByFuture cb);
		ErrRtnQueryBankBalanceByFuture errRtnQueryBankBalanceByFuture;
		public delegate void ErrRtnQueryBankBalanceByFuture(ref CThostFtdcReqQueryAccountField pReqQueryAccount, ref CThostFtdcRspInfoField pRspInfo);
		/// <summary>
		/// 期货发起查询银行余额错误回报
		/// </summary>
		public event ErrRtnQueryBankBalanceByFuture OnErrRtnQueryBankBalanceByFuture
		{
			add { errRtnQueryBankBalanceByFuture += value; regErrRtnQueryBankBalanceByFuture(errRtnQueryBankBalanceByFuture); }
			remove { errRtnQueryBankBalanceByFuture -= value; regErrRtnQueryBankBalanceByFuture(errRtnQueryBankBalanceByFuture); }
		}

		///系统运行时期货端手工发起冲正银行转期货错误回报
		[DllImport(dllName, EntryPoint = "?RegErrRtnRepealBankToFutureByFutureManual@@YGXP6GHPAUCThostFtdcReqRepealField@@PAUCThostFtdcRspInfoField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regErrRtnRepealBankToFutureByFutureManual(ErrRtnRepealBankToFutureByFutureManual cb);
		ErrRtnRepealBankToFutureByFutureManual errRtnRepealBankToFutureByFutureManual;
		public delegate void ErrRtnRepealBankToFutureByFutureManual(ref CThostFtdcReqRepealField pReqRepeal, ref CThostFtdcRspInfoField pRspInfo);
		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货错误回报
		/// </summary>
		public event ErrRtnRepealBankToFutureByFutureManual OnErrRtnRepealBankToFutureByFutureManual
		{
			add { errRtnRepealBankToFutureByFutureManual += value; regErrRtnRepealBankToFutureByFutureManual(errRtnRepealBankToFutureByFutureManual); }
			remove { errRtnRepealBankToFutureByFutureManual -= value; regErrRtnRepealBankToFutureByFutureManual(errRtnRepealBankToFutureByFutureManual); }
		}

		///系统运行时期货端手工发起冲正期货转银行错误回报
		[DllImport(dllName, EntryPoint = "?RegErrRtnRepealFutureToBankByFutureManual@@YGXP6GHPAUCThostFtdcReqRepealField@@PAUCThostFtdcRspInfoField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regErrRtnRepealFutureToBankByFutureManual(ErrRtnRepealFutureToBankByFutureManual cb);
		ErrRtnRepealFutureToBankByFutureManual errRtnRepealFutureToBankByFutureManual;
		public delegate void ErrRtnRepealFutureToBankByFutureManual(ref CThostFtdcReqRepealField pReqRepeal, ref CThostFtdcRspInfoField pRspInfo);
		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行错误回报
		/// </summary>
		public event ErrRtnRepealFutureToBankByFutureManual OnErrRtnRepealFutureToBankByFutureManual
		{
			add { errRtnRepealFutureToBankByFutureManual += value; regErrRtnRepealFutureToBankByFutureManual(errRtnRepealFutureToBankByFutureManual); }
			remove { errRtnRepealFutureToBankByFutureManual -= value; regErrRtnRepealFutureToBankByFutureManual(errRtnRepealFutureToBankByFutureManual); }
		}

		///错误应答
		[DllImport(dllName, EntryPoint = "?RegRspError@@YGXP6GHPAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspError(RspError cb);
		RspError rspError;
		public delegate void RspError(ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 错误应答
		/// </summary>
		public event RspError OnRspError
		{
			add { rspError += value; regRspError(rspError); }
			remove { rspError -= value; regRspError(rspError); }
		}

		///期货发起银行资金转期货应答
		[DllImport(dllName, EntryPoint = "?RegRspFromBankToFutureByFuture@@YGXP6GHPAUCThostFtdcReqTransferField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspFromBankToFutureByFuture(RspFromBankToFutureByFuture cb);
		RspFromBankToFutureByFuture rspFromBankToFutureByFuture;
		public delegate void RspFromBankToFutureByFuture(ref CThostFtdcReqTransferField pReqTransfer, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 期货发起银行资金转期货应答
		/// </summary>
		public event RspFromBankToFutureByFuture OnRspFromBankToFutureByFuture
		{
			add { rspFromBankToFutureByFuture += value; regRspFromBankToFutureByFuture(rspFromBankToFutureByFuture); }
			remove { rspFromBankToFutureByFuture -= value; regRspFromBankToFutureByFuture(rspFromBankToFutureByFuture); }
		}

		///期货发起期货资金转银行应答
		[DllImport(dllName, EntryPoint = "?RegRspFromFutureToBankByFuture@@YGXP6GHPAUCThostFtdcReqTransferField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspFromFutureToBankByFuture(RspFromFutureToBankByFuture cb);
		RspFromFutureToBankByFuture rspFromFutureToBankByFuture;
		public delegate void RspFromFutureToBankByFuture(ref CThostFtdcReqTransferField pReqTransfer, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 期货发起期货资金转银行应答
		/// </summary>
		public event RspFromFutureToBankByFuture OnRspFromFutureToBankByFuture
		{
			add { rspFromFutureToBankByFuture += value; regRspFromFutureToBankByFuture(rspFromFutureToBankByFuture); }
			remove { rspFromFutureToBankByFuture -= value; regRspFromFutureToBankByFuture(rspFromFutureToBankByFuture); }
		}

		///报单操作请求响应
		[DllImport(dllName, EntryPoint = "?RegRspOrderAction@@YGXP6GHPAUCThostFtdcInputOrderActionField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspOrderAction(RspOrderAction cb);
		RspOrderAction rspOrderAction;
		public delegate void RspOrderAction(ref CThostFtdcInputOrderActionField pInputOrderAction, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 报单操作请求响应
		/// </summary>
		public event RspOrderAction OnRspOrderAction
		{
			add { rspOrderAction += value; regRspOrderAction(rspOrderAction); }
			remove { rspOrderAction -= value; regRspOrderAction(rspOrderAction); }
		}

		///报单录入请求响应
		[DllImport(dllName, EntryPoint = "?RegRspOrderInsert@@YGXP6GHPAUCThostFtdcInputOrderField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspOrderInsert(RspOrderInsert cb);
		RspOrderInsert rspOrderInsert;
		public delegate void RspOrderInsert(ref CThostFtdcInputOrderField pInputOrder, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 报单录入请求响应
		/// </summary>
		public event RspOrderInsert OnRspOrderInsert
		{
			add { rspOrderInsert += value; regRspOrderInsert(rspOrderInsert); }
			remove { rspOrderInsert -= value; regRspOrderInsert(rspOrderInsert); }
		}

		///预埋撤单录入请求响应
		[DllImport(dllName, EntryPoint = "?RegRspParkedOrderAction@@YGXP6GHPAUCThostFtdcParkedOrderActionField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspParkedOrderAction(RspParkedOrderAction cb);
		RspParkedOrderAction rspParkedOrderAction;
		public delegate void RspParkedOrderAction(ref CThostFtdcParkedOrderActionField pParkedOrderAction, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 预埋撤单录入请求响应
		/// </summary>
		public event RspParkedOrderAction OnRspParkedOrderAction
		{
			add { rspParkedOrderAction += value; regRspParkedOrderAction(rspParkedOrderAction); }
			remove { rspParkedOrderAction -= value; regRspParkedOrderAction(rspParkedOrderAction); }
		}

		///预埋单录入请求响应
		[DllImport(dllName, EntryPoint = "?RegRspParkedOrderInsert@@YGXP6GHPAUCThostFtdcParkedOrderField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspParkedOrderInsert(RspParkedOrderInsert cb);
		RspParkedOrderInsert rspParkedOrderInsert;
		public delegate void RspParkedOrderInsert(ref CThostFtdcParkedOrderField pParkedOrder, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 预埋单录入请求响应
		/// </summary>
		public event RspParkedOrderInsert OnRspParkedOrderInsert
		{
			add { rspParkedOrderInsert += value; regRspParkedOrderInsert(rspParkedOrderInsert); }
			remove { rspParkedOrderInsert -= value; regRspParkedOrderInsert(rspParkedOrderInsert); }
		}

		///请求查询经纪公司交易算法响应
		[DllImport(dllName, EntryPoint = "?RegRspQryBrokerTradingAlgos@@YGXP6GHPAUCThostFtdcBrokerTradingAlgosField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryBrokerTradingAlgos(RspQryBrokerTradingAlgos cb);
		RspQryBrokerTradingAlgos rspQryBrokerTradingAlgos;
		public delegate void RspQryBrokerTradingAlgos(ref CThostFtdcBrokerTradingAlgosField pBrokerTradingAlgos, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询经纪公司交易算法响应
		/// </summary>
		public event RspQryBrokerTradingAlgos OnRspQryBrokerTradingAlgos
		{
			add { rspQryBrokerTradingAlgos += value; regRspQryBrokerTradingAlgos(rspQryBrokerTradingAlgos); }
			remove { rspQryBrokerTradingAlgos -= value; regRspQryBrokerTradingAlgos(rspQryBrokerTradingAlgos); }
		}

		///请求查询经纪公司交易参数响应
		[DllImport(dllName, EntryPoint = "?RegRspQryBrokerTradingParams@@YGXP6GHPAUCThostFtdcBrokerTradingParamsField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryBrokerTradingParams(RspQryBrokerTradingParams cb);
		RspQryBrokerTradingParams rspQryBrokerTradingParams;
		public delegate void RspQryBrokerTradingParams(ref CThostFtdcBrokerTradingParamsField pBrokerTradingParams, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询经纪公司交易参数响应
		/// </summary>
		public event RspQryBrokerTradingParams OnRspQryBrokerTradingParams
		{
			add { rspQryBrokerTradingParams += value; regRspQryBrokerTradingParams(rspQryBrokerTradingParams); }
			remove { rspQryBrokerTradingParams -= value; regRspQryBrokerTradingParams(rspQryBrokerTradingParams); }
		}

		///查询保证金监管系统经纪公司资金账户密钥响应
		[DllImport(dllName, EntryPoint = "?RegRspQryCFMMCTradingAccountKey@@YGXP6GHPAUCThostFtdcCFMMCTradingAccountKeyField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryCFMMCTradingAccountKey(RspQryCFMMCTradingAccountKey cb);
		RspQryCFMMCTradingAccountKey rspQryCFMMCTradingAccountKey;
		public delegate void RspQryCFMMCTradingAccountKey(ref CThostFtdcCFMMCTradingAccountKeyField pCFMMCTradingAccountKey, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 查询保证金监管系统经纪公司资金账户密钥响应
		/// </summary>
		public event RspQryCFMMCTradingAccountKey OnRspQryCFMMCTradingAccountKey
		{
			add { rspQryCFMMCTradingAccountKey += value; regRspQryCFMMCTradingAccountKey(rspQryCFMMCTradingAccountKey); }
			remove { rspQryCFMMCTradingAccountKey -= value; regRspQryCFMMCTradingAccountKey(rspQryCFMMCTradingAccountKey); }
		}

		///请求查询签约银行响应
		[DllImport(dllName, EntryPoint = "?RegRspQryContractBank@@YGXP6GHPAUCThostFtdcContractBankField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryContractBank(RspQryContractBank cb);
		RspQryContractBank rspQryContractBank;
		public delegate void RspQryContractBank(ref CThostFtdcContractBankField pContractBank, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询签约银行响应
		/// </summary>
		public event RspQryContractBank OnRspQryContractBank
		{
			add { rspQryContractBank += value; regRspQryContractBank(rspQryContractBank); }
			remove { rspQryContractBank -= value; regRspQryContractBank(rspQryContractBank); }
		}

		///请求查询行情响应
		[DllImport(dllName, EntryPoint = "?RegRspQryDepthMarketData@@YGXP6GHPAUCThostFtdcDepthMarketDataField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryDepthMarketData(RspQryDepthMarketData cb);
		RspQryDepthMarketData rspQryDepthMarketData;
		public delegate void RspQryDepthMarketData(ref CThostFtdcDepthMarketDataField pDepthMarketData, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询行情响应
		/// </summary>
		public event RspQryDepthMarketData OnRspQryDepthMarketData
		{
			add { rspQryDepthMarketData += value; regRspQryDepthMarketData(rspQryDepthMarketData); }
			remove { rspQryDepthMarketData -= value; regRspQryDepthMarketData(rspQryDepthMarketData); }
		}

		///请求查询交易所响应
		[DllImport(dllName, EntryPoint = "?RegRspQryExchange@@YGXP6GHPAUCThostFtdcExchangeField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryExchange(RspQryExchange cb);
		RspQryExchange rspQryExchange;
		public delegate void RspQryExchange(ref CThostFtdcExchangeField pExchange, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询交易所响应
		/// </summary>
		public event RspQryExchange OnRspQryExchange
		{
			add { rspQryExchange += value; regRspQryExchange(rspQryExchange); }
			remove { rspQryExchange -= value; regRspQryExchange(rspQryExchange); }
		}

		///请求查询合约响应
		[DllImport(dllName, EntryPoint = "?RegRspQryInstrument@@YGXP6GHPAUCThostFtdcInstrumentField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryInstrument(RspQryInstrument cb);
		RspQryInstrument rspQryInstrument;
		public delegate void RspQryInstrument(ref CThostFtdcInstrumentField pInstrument, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询合约响应
		/// </summary>
		public event RspQryInstrument OnRspQryInstrument
		{
			add { rspQryInstrument += value; regRspQryInstrument(rspQryInstrument); }
			remove { rspQryInstrument -= value; regRspQryInstrument(rspQryInstrument); }
		}

		///请求查询合约手续费率响应
		[DllImport(dllName, EntryPoint = "?RegRspQryInstrumentCommissionRate@@YGXP6GHPAUCThostFtdcInstrumentCommissionRateField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryInstrumentCommissionRate(RspQryInstrumentCommissionRate cb);
		RspQryInstrumentCommissionRate rspQryInstrumentCommissionRate;
		public delegate void RspQryInstrumentCommissionRate(ref CThostFtdcInstrumentCommissionRateField pInstrumentCommissionRate, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询合约手续费率响应
		/// </summary>
		public event RspQryInstrumentCommissionRate OnRspQryInstrumentCommissionRate
		{
			add { rspQryInstrumentCommissionRate += value; regRspQryInstrumentCommissionRate(rspQryInstrumentCommissionRate); }
			remove { rspQryInstrumentCommissionRate -= value; regRspQryInstrumentCommissionRate(rspQryInstrumentCommissionRate); }
		}

		///请求查询合约保证金率响应
		[DllImport(dllName, EntryPoint = "?RegRspQryInstrumentMarginRate@@YGXP6GHPAUCThostFtdcInstrumentMarginRateField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryInstrumentMarginRate(RspQryInstrumentMarginRate cb);
		RspQryInstrumentMarginRate rspQryInstrumentMarginRate;
		public delegate void RspQryInstrumentMarginRate(ref CThostFtdcInstrumentMarginRateField pInstrumentMarginRate, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询合约保证金率响应
		/// </summary>
		public event RspQryInstrumentMarginRate OnRspQryInstrumentMarginRate
		{
			add { rspQryInstrumentMarginRate += value; regRspQryInstrumentMarginRate(rspQryInstrumentMarginRate); }
			remove { rspQryInstrumentMarginRate -= value; regRspQryInstrumentMarginRate(rspQryInstrumentMarginRate); }
		}

		///请求查询投资者响应
		[DllImport(dllName, EntryPoint = "?RegRspQryInvestor@@YGXP6GHPAUCThostFtdcInvestorField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryInvestor(RspQryInvestor cb);
		RspQryInvestor rspQryInvestor;
		public delegate void RspQryInvestor(ref CThostFtdcInvestorField pInvestor, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询投资者响应
		/// </summary>
		public event RspQryInvestor OnRspQryInvestor
		{
			add { rspQryInvestor += value; regRspQryInvestor(rspQryInvestor); }
			remove { rspQryInvestor -= value; regRspQryInvestor(rspQryInvestor); }
		}

		///请求查询投资者持仓响应
		[DllImport(dllName, EntryPoint = "?RegRspQryInvestorPosition@@YGXP6GHPAUCThostFtdcInvestorPositionField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryInvestorPosition(RspQryInvestorPosition cb);
		RspQryInvestorPosition rspQryInvestorPosition;
		public delegate void RspQryInvestorPosition(ref CThostFtdcInvestorPositionField pInvestorPosition, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询投资者持仓响应
		/// </summary>
		public event RspQryInvestorPosition OnRspQryInvestorPosition
		{
			add { rspQryInvestorPosition += value; regRspQryInvestorPosition(rspQryInvestorPosition); }
			remove { rspQryInvestorPosition -= value; regRspQryInvestorPosition(rspQryInvestorPosition); }
		}

		///请求查询投资者持仓明细响应
		[DllImport(dllName, EntryPoint = "?RegRspQryInvestorPositionCombineDetail@@YGXP6GHPAUCThostFtdcInvestorPositionCombineDetailField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryInvestorPositionCombineDetail(RspQryInvestorPositionCombineDetail cb);
		RspQryInvestorPositionCombineDetail rspQryInvestorPositionCombineDetail;
		public delegate void RspQryInvestorPositionCombineDetail(ref CThostFtdcInvestorPositionCombineDetailField pInvestorPositionCombineDetail, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// </summary>
		public event RspQryInvestorPositionCombineDetail OnRspQryInvestorPositionCombineDetail
		{
			add { rspQryInvestorPositionCombineDetail += value; regRspQryInvestorPositionCombineDetail(rspQryInvestorPositionCombineDetail); }
			remove { rspQryInvestorPositionCombineDetail -= value; regRspQryInvestorPositionCombineDetail(rspQryInvestorPositionCombineDetail); }
		}

		///请求查询投资者持仓明细响应
		[DllImport(dllName, EntryPoint = "?RegRspQryInvestorPositionDetail@@YGXP6GHPAUCThostFtdcInvestorPositionDetailField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryInvestorPositionDetail(RspQryInvestorPositionDetail cb);
		RspQryInvestorPositionDetail rspQryInvestorPositionDetail;
		public delegate void RspQryInvestorPositionDetail(ref CThostFtdcInvestorPositionDetailField pInvestorPositionDetail, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询投资者持仓明细响应
		/// </summary>
		public event RspQryInvestorPositionDetail OnRspQryInvestorPositionDetail
		{
			add { rspQryInvestorPositionDetail += value; regRspQryInvestorPositionDetail(rspQryInvestorPositionDetail); }
			remove { rspQryInvestorPositionDetail -= value; regRspQryInvestorPositionDetail(rspQryInvestorPositionDetail); }
		}

		///请求查询客户通知响应
		[DllImport(dllName, EntryPoint = "?RegRspQryNotice@@YGXP6GHPAUCThostFtdcNoticeField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryNotice(RspQryNotice cb);
		RspQryNotice rspQryNotice;
		public delegate void RspQryNotice(ref CThostFtdcNoticeField pNotice, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询客户通知响应
		/// </summary>
		public event RspQryNotice OnRspQryNotice
		{
			add { rspQryNotice += value; regRspQryNotice(rspQryNotice); }
			remove { rspQryNotice -= value; regRspQryNotice(rspQryNotice); }
		}

		///请求查询报单响应
		[DllImport(dllName, EntryPoint = "?RegRspQryOrder@@YGXP6GHPAUCThostFtdcOrderField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryOrder(RspQryOrder cb);
		RspQryOrder rspQryOrder;
		public delegate void RspQryOrder(ref CThostFtdcOrderField pOrder, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询报单响应
		/// </summary>
		public event RspQryOrder OnRspQryOrder
		{
			add { rspQryOrder += value; regRspQryOrder(rspQryOrder); }
			remove { rspQryOrder -= value; regRspQryOrder(rspQryOrder); }
		}

		///请求查询预埋单响应
		[DllImport(dllName, EntryPoint = "?RegRspQryParkedOrder@@YGXP6GHPAUCThostFtdcParkedOrderField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryParkedOrder(RspQryParkedOrder cb);
		RspQryParkedOrder rspQryParkedOrder;
		public delegate void RspQryParkedOrder(ref CThostFtdcParkedOrderField pParkedOrder, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询预埋单响应
		/// </summary>
		public event RspQryParkedOrder OnRspQryParkedOrder
		{
			add { rspQryParkedOrder += value; regRspQryParkedOrder(rspQryParkedOrder); }
			remove { rspQryParkedOrder -= value; regRspQryParkedOrder(rspQryParkedOrder); }
		}

		///请求查询预埋撤单响应
		[DllImport(dllName, EntryPoint = "?RegRspQryParkedOrderAction@@YGXP6GHPAUCThostFtdcParkedOrderActionField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryParkedOrderAction(RspQryParkedOrderAction cb);
		RspQryParkedOrderAction rspQryParkedOrderAction;
		public delegate void RspQryParkedOrderAction(ref CThostFtdcParkedOrderActionField pParkedOrderAction, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询预埋撤单响应
		/// </summary>
		public event RspQryParkedOrderAction OnRspQryParkedOrderAction
		{
			add { rspQryParkedOrderAction += value; regRspQryParkedOrderAction(rspQryParkedOrderAction); }
			remove { rspQryParkedOrderAction -= value; regRspQryParkedOrderAction(rspQryParkedOrderAction); }
		}

		///请求查询投资者结算结果响应
		[DllImport(dllName, EntryPoint = "?RegRspQrySettlementInfo@@YGXP6GHPAUCThostFtdcSettlementInfoField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQrySettlementInfo(RspQrySettlementInfo cb);
		RspQrySettlementInfo rspQrySettlementInfo;
		public delegate void RspQrySettlementInfo(ref CThostFtdcSettlementInfoField pSettlementInfo, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询投资者结算结果响应
		/// </summary>
		public event RspQrySettlementInfo OnRspQrySettlementInfo
		{
			add { rspQrySettlementInfo += value; regRspQrySettlementInfo(rspQrySettlementInfo); }
			remove { rspQrySettlementInfo -= value; regRspQrySettlementInfo(rspQrySettlementInfo); }
		}

		///请求查询结算信息确认响应
		[DllImport(dllName, EntryPoint = "?RegRspQrySettlementInfoConfirm@@YGXP6GHPAUCThostFtdcSettlementInfoConfirmField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQrySettlementInfoConfirm(RspQrySettlementInfoConfirm cb);
		RspQrySettlementInfoConfirm rspQrySettlementInfoConfirm;
		public delegate void RspQrySettlementInfoConfirm(ref CThostFtdcSettlementInfoConfirmField pSettlementInfoConfirm, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询结算信息确认响应
		/// </summary>
		public event RspQrySettlementInfoConfirm OnRspQrySettlementInfoConfirm
		{
			add { rspQrySettlementInfoConfirm += value; regRspQrySettlementInfoConfirm(rspQrySettlementInfoConfirm); }
			remove { rspQrySettlementInfoConfirm -= value; regRspQrySettlementInfoConfirm(rspQrySettlementInfoConfirm); }
		}

		///请求查询成交响应
		[DllImport(dllName, EntryPoint = "?RegRspQryTrade@@YGXP6GHPAUCThostFtdcTradeField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryTrade(RspQryTrade cb);
		RspQryTrade rspQryTrade;
		public delegate void RspQryTrade(ref CThostFtdcTradeField pTrade, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询成交响应
		/// </summary>
		public event RspQryTrade OnRspQryTrade
		{
			add { rspQryTrade += value; regRspQryTrade(rspQryTrade); }
			remove { rspQryTrade -= value; regRspQryTrade(rspQryTrade); }
		}

		///请求查询资金账户响应
		[DllImport(dllName, EntryPoint = "?RegRspQryTradingAccount@@YGXP6GHPAUCThostFtdcTradingAccountField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryTradingAccount(RspQryTradingAccount cb);
		RspQryTradingAccount rspQryTradingAccount;
		public delegate void RspQryTradingAccount(ref CThostFtdcTradingAccountField pTradingAccount, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询资金账户响应
		/// </summary>
		public event RspQryTradingAccount OnRspQryTradingAccount
		{
			add { rspQryTradingAccount += value; regRspQryTradingAccount(rspQryTradingAccount); }
			remove { rspQryTradingAccount -= value; regRspQryTradingAccount(rspQryTradingAccount); }
		}

		///请求查询交易编码响应
		[DllImport(dllName, EntryPoint = "?RegRspQryTradingCode@@YGXP6GHPAUCThostFtdcTradingCodeField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryTradingCode(RspQryTradingCode cb);
		RspQryTradingCode rspQryTradingCode;
		public delegate void RspQryTradingCode(ref CThostFtdcTradingCodeField pTradingCode, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询交易编码响应
		/// </summary>
		public event RspQryTradingCode OnRspQryTradingCode
		{
			add { rspQryTradingCode += value; regRspQryTradingCode(rspQryTradingCode); }
			remove { rspQryTradingCode -= value; regRspQryTradingCode(rspQryTradingCode); }
		}

		///请求查询交易通知响应
		[DllImport(dllName, EntryPoint = "?RegRspQryTradingNotice@@YGXP6GHPAUCThostFtdcTradingNoticeField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryTradingNotice(RspQryTradingNotice cb);
		RspQryTradingNotice rspQryTradingNotice;
		public delegate void RspQryTradingNotice(ref CThostFtdcTradingNoticeField pTradingNotice, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询交易通知响应
		/// </summary>
		public event RspQryTradingNotice OnRspQryTradingNotice
		{
			add { rspQryTradingNotice += value; regRspQryTradingNotice(rspQryTradingNotice); }
			remove { rspQryTradingNotice -= value; regRspQryTradingNotice(rspQryTradingNotice); }
		}

		///请求查询转帐银行响应
		[DllImport(dllName, EntryPoint = "?RegRspQryTransferBank@@YGXP6GHPAUCThostFtdcTransferBankField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryTransferBank(RspQryTransferBank cb);
		RspQryTransferBank rspQryTransferBank;
		public delegate void RspQryTransferBank(ref CThostFtdcTransferBankField pTransferBank, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询转帐银行响应
		/// </summary>
		public event RspQryTransferBank OnRspQryTransferBank
		{
			add { rspQryTransferBank += value; regRspQryTransferBank(rspQryTransferBank); }
			remove { rspQryTransferBank -= value; regRspQryTransferBank(rspQryTransferBank); }
		}

		///请求查询转帐流水响应
		[DllImport(dllName, EntryPoint = "?RegRspQryTransferSerial@@YGXP6GHPAUCThostFtdcTransferSerialField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQryTransferSerial(RspQryTransferSerial cb);
		RspQryTransferSerial rspQryTransferSerial;
		public delegate void RspQryTransferSerial(ref CThostFtdcTransferSerialField pTransferSerial, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 请求查询转帐流水响应
		/// </summary>
		public event RspQryTransferSerial OnRspQryTransferSerial
		{
			add { rspQryTransferSerial += value; regRspQryTransferSerial(rspQryTransferSerial); }
			remove { rspQryTransferSerial -= value; regRspQryTransferSerial(rspQryTransferSerial); }
		}

        ///请求查询银期签约关系响应
        [DllImport(dllName, EntryPoint = "?RegRspQryAccountregister@@YGXP6GHPAUCThostFtdcAccountregisterField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
        static extern void regRspQryAccountregister(RspQryAccountregister cb);
        RspQryAccountregister rspQryAccountregister;
        public delegate void RspQryAccountregister(ref CThostFtdcAccountregisterField pAccountregister, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
        /// <summary>
        /// 请求查询转帐流水响应
        /// </summary>
        public event RspQryAccountregister OnRspQryAccountregister
        {
            add { rspQryAccountregister += value; regRspQryAccountregister(rspQryAccountregister); }
            remove { rspQryAccountregister -= value; regRspQryAccountregister(rspQryAccountregister); }
        }


		///期货发起查询银行余额应答
		[DllImport(dllName, EntryPoint = "?RegRspQueryBankAccountMoneyByFuture@@YGXP6GHPAUCThostFtdcReqQueryAccountField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQueryBankAccountMoneyByFuture(RspQueryBankAccountMoneyByFuture cb);
		RspQueryBankAccountMoneyByFuture rspQueryBankAccountMoneyByFuture;
		public delegate void RspQueryBankAccountMoneyByFuture(ref CThostFtdcReqQueryAccountField pReqQueryAccount, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 期货发起查询银行余额应答
		/// </summary>
		public event RspQueryBankAccountMoneyByFuture OnRspQueryBankAccountMoneyByFuture
		{
			add { rspQueryBankAccountMoneyByFuture += value; regRspQueryBankAccountMoneyByFuture(rspQueryBankAccountMoneyByFuture); }
			remove { rspQueryBankAccountMoneyByFuture -= value; regRspQueryBankAccountMoneyByFuture(rspQueryBankAccountMoneyByFuture); }
		}

		///查询最大报单数量响应
		[DllImport(dllName, EntryPoint = "?RegRspQueryMaxOrderVolume@@YGXP6GHPAUCThostFtdcQueryMaxOrderVolumeField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspQueryMaxOrderVolume(RspQueryMaxOrderVolume cb);
		RspQueryMaxOrderVolume rspQueryMaxOrderVolume;
		public delegate void RspQueryMaxOrderVolume(ref CThostFtdcQueryMaxOrderVolumeField pQueryMaxOrderVolume, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 查询最大报单数量响应
		/// </summary>
		public event RspQueryMaxOrderVolume OnRspQueryMaxOrderVolume
		{
			add { rspQueryMaxOrderVolume += value; regRspQueryMaxOrderVolume(rspQueryMaxOrderVolume); }
			remove { rspQueryMaxOrderVolume -= value; regRspQueryMaxOrderVolume(rspQueryMaxOrderVolume); }
		}

		///删除预埋单响应
		[DllImport(dllName, EntryPoint = "?RegRspRemoveParkedOrder@@YGXP6GHPAUCThostFtdcRemoveParkedOrderField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspRemoveParkedOrder(RspRemoveParkedOrder cb);
		RspRemoveParkedOrder rspRemoveParkedOrder;
		public delegate void RspRemoveParkedOrder(ref CThostFtdcRemoveParkedOrderField pRemoveParkedOrder, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 删除预埋单响应
		/// </summary>
		public event RspRemoveParkedOrder OnRspRemoveParkedOrder
		{
			add { rspRemoveParkedOrder += value; regRspRemoveParkedOrder(rspRemoveParkedOrder); }
			remove { rspRemoveParkedOrder -= value; regRspRemoveParkedOrder(rspRemoveParkedOrder); }
		}

		///删除预埋撤单响应
		[DllImport(dllName, EntryPoint = "?RegRspRemoveParkedOrderAction@@YGXP6GHPAUCThostFtdcRemoveParkedOrderActionField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspRemoveParkedOrderAction(RspRemoveParkedOrderAction cb);
		RspRemoveParkedOrderAction rspRemoveParkedOrderAction;
		public delegate void RspRemoveParkedOrderAction(ref CThostFtdcRemoveParkedOrderActionField pRemoveParkedOrderAction, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 删除预埋撤单响应
		/// </summary>
		public event RspRemoveParkedOrderAction OnRspRemoveParkedOrderAction
		{
			add { rspRemoveParkedOrderAction += value; regRspRemoveParkedOrderAction(rspRemoveParkedOrderAction); }
			remove { rspRemoveParkedOrderAction -= value; regRspRemoveParkedOrderAction(rspRemoveParkedOrderAction); }
		}

		///投资者结算结果确认响应
		[DllImport(dllName, EntryPoint = "?RegRspSettlementInfoConfirm@@YGXP6GHPAUCThostFtdcSettlementInfoConfirmField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspSettlementInfoConfirm(RspSettlementInfoConfirm cb);
		RspSettlementInfoConfirm rspSettlementInfoConfirm;
		public delegate void RspSettlementInfoConfirm(ref CThostFtdcSettlementInfoConfirmField pSettlementInfoConfirm, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 投资者结算结果确认响应
		/// </summary>
		public event RspSettlementInfoConfirm OnRspSettlementInfoConfirm
		{
			add { rspSettlementInfoConfirm += value; regRspSettlementInfoConfirm(rspSettlementInfoConfirm); }
			remove { rspSettlementInfoConfirm -= value; regRspSettlementInfoConfirm(rspSettlementInfoConfirm); }
		}

		///资金账户口令更新请求响应
		[DllImport(dllName, EntryPoint = "?RegRspTradingAccountPasswordUpdate@@YGXP6GHPAUCThostFtdcTradingAccountPasswordUpdateField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspTradingAccountPasswordUpdate(RspTradingAccountPasswordUpdate cb);
		RspTradingAccountPasswordUpdate rspTradingAccountPasswordUpdate;
		public delegate void RspTradingAccountPasswordUpdate(ref CThostFtdcTradingAccountPasswordUpdateField pTradingAccountPasswordUpdate, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 资金账户口令更新请求响应
		/// </summary>
		public event RspTradingAccountPasswordUpdate OnRspTradingAccountPasswordUpdate
		{
			add { rspTradingAccountPasswordUpdate += value; regRspTradingAccountPasswordUpdate(rspTradingAccountPasswordUpdate); }
			remove { rspTradingAccountPasswordUpdate -= value; regRspTradingAccountPasswordUpdate(rspTradingAccountPasswordUpdate); }
		}

		///登录请求响应
		[DllImport(dllName, EntryPoint = "?RegRspUserLogin@@YGXP6GHPAUCThostFtdcRspUserLoginField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspUserLogin(RspUserLogin cb);
		RspUserLogin rspUserLogin;
		public delegate void RspUserLogin(ref CThostFtdcRspUserLoginField pRspUserLogin, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 登录请求响应
		/// </summary>
		public event RspUserLogin OnRspUserLogin
		{
			add { rspUserLogin += value; regRspUserLogin(rspUserLogin); }
			remove { rspUserLogin -= value; regRspUserLogin(rspUserLogin); }
		}

		///登出请求响应
		[DllImport(dllName, EntryPoint = "?RegRspUserLogout@@YGXP6GHPAUCThostFtdcUserLogoutField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspUserLogout(RspUserLogout cb);
		RspUserLogout rspUserLogout;
		public delegate void RspUserLogout(ref CThostFtdcUserLogoutField pUserLogout, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 登出请求响应
		/// </summary>
		public event RspUserLogout OnRspUserLogout
		{
			add { rspUserLogout += value; regRspUserLogout(rspUserLogout); }
			remove { rspUserLogout -= value; regRspUserLogout(rspUserLogout); }
		}

		///用户口令更新请求响应
		[DllImport(dllName, EntryPoint = "?RegRspUserPasswordUpdate@@YGXP6GHPAUCThostFtdcUserPasswordUpdateField@@PAUCThostFtdcRspInfoField@@H_N@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRspUserPasswordUpdate(RspUserPasswordUpdate cb);
		RspUserPasswordUpdate rspUserPasswordUpdate;
		public delegate void RspUserPasswordUpdate(ref CThostFtdcUserPasswordUpdateField pUserPasswordUpdate, ref CThostFtdcRspInfoField pRspInfo, int nRequestID, bool bIsLast);
		/// <summary>
		/// 用户口令更新请求响应
		/// </summary>
		public event RspUserPasswordUpdate OnRspUserPasswordUpdate
		{
			add { rspUserPasswordUpdate += value; regRspUserPasswordUpdate(rspUserPasswordUpdate); }
			remove { rspUserPasswordUpdate -= value; regRspUserPasswordUpdate(rspUserPasswordUpdate); }
		}

		///提示条件单校验错误
		[DllImport(dllName, EntryPoint = "?RegRtnErrorConditionalOrder@@YGXP6GHPAUCThostFtdcErrorConditionalOrderField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnErrorConditionalOrder(RtnErrorConditionalOrder cb);
		RtnErrorConditionalOrder rtnErrorConditionalOrder;
		public delegate void RtnErrorConditionalOrder(ref CThostFtdcErrorConditionalOrderField pErrorConditionalOrder);
		/// <summary>
		/// 提示条件单校验错误
		/// </summary>
		public event RtnErrorConditionalOrder OnRtnErrorConditionalOrder
		{
			add { rtnErrorConditionalOrder += value; regRtnErrorConditionalOrder(rtnErrorConditionalOrder); }
			remove { rtnErrorConditionalOrder -= value; regRtnErrorConditionalOrder(rtnErrorConditionalOrder); }
		}

		///银行发起银行资金转期货通知
		[DllImport(dllName, EntryPoint = "?RegRtnFromBankToFutureByBank@@YGXP6GHPAUCThostFtdcRspTransferField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnFromBankToFutureByBank(RtnFromBankToFutureByBank cb);
		RtnFromBankToFutureByBank rtnFromBankToFutureByBank;
		public delegate void RtnFromBankToFutureByBank(ref CThostFtdcRspTransferField pRspTransfer);
		/// <summary>
		/// 银行发起银行资金转期货通知
		/// </summary>
		public event RtnFromBankToFutureByBank OnRtnFromBankToFutureByBank
		{
			add { rtnFromBankToFutureByBank += value; regRtnFromBankToFutureByBank(rtnFromBankToFutureByBank); }
			remove { rtnFromBankToFutureByBank -= value; regRtnFromBankToFutureByBank(rtnFromBankToFutureByBank); }
		}

		///期货发起银行资金转期货通知
		[DllImport(dllName, EntryPoint = "?RegRtnFromBankToFutureByFuture@@YGXP6GHPAUCThostFtdcRspTransferField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnFromBankToFutureByFuture(RtnFromBankToFutureByFuture cb);
		RtnFromBankToFutureByFuture rtnFromBankToFutureByFuture;
		public delegate void RtnFromBankToFutureByFuture(ref CThostFtdcRspTransferField pRspTransfer);
		/// <summary>
		/// 期货发起银行资金转期货通知
		/// </summary>
		public event RtnFromBankToFutureByFuture OnRtnFromBankToFutureByFuture
		{
			add { rtnFromBankToFutureByFuture += value; regRtnFromBankToFutureByFuture(rtnFromBankToFutureByFuture); }
			remove { rtnFromBankToFutureByFuture -= value; regRtnFromBankToFutureByFuture(rtnFromBankToFutureByFuture); }
		}

		///银行发起期货资金转银行通知
		[DllImport(dllName, EntryPoint = "?RegRtnFromFutureToBankByBank@@YGXP6GHPAUCThostFtdcRspTransferField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnFromFutureToBankByBank(RtnFromFutureToBankByBank cb);
		RtnFromFutureToBankByBank rtnFromFutureToBankByBank;
		public delegate void RtnFromFutureToBankByBank(ref CThostFtdcRspTransferField pRspTransfer);
		/// <summary>
		/// 银行发起期货资金转银行通知
		/// </summary>
		public event RtnFromFutureToBankByBank OnRtnFromFutureToBankByBank
		{
			add { rtnFromFutureToBankByBank += value; regRtnFromFutureToBankByBank(rtnFromFutureToBankByBank); }
			remove { rtnFromFutureToBankByBank -= value; regRtnFromFutureToBankByBank(rtnFromFutureToBankByBank); }
		}

		///期货发起期货资金转银行通知
		[DllImport(dllName, EntryPoint = "?RegRtnFromFutureToBankByFuture@@YGXP6GHPAUCThostFtdcRspTransferField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnFromFutureToBankByFuture(RtnFromFutureToBankByFuture cb);
		RtnFromFutureToBankByFuture rtnFromFutureToBankByFuture;
		public delegate void RtnFromFutureToBankByFuture(ref CThostFtdcRspTransferField pRspTransfer);
		/// <summary>
		/// 期货发起期货资金转银行通知
		/// </summary>
		public event RtnFromFutureToBankByFuture OnRtnFromFutureToBankByFuture
		{
			add { rtnFromFutureToBankByFuture += value; regRtnFromFutureToBankByFuture(rtnFromFutureToBankByFuture); }
			remove { rtnFromFutureToBankByFuture -= value; regRtnFromFutureToBankByFuture(rtnFromFutureToBankByFuture); }
		}

		///合约交易状态通知
		[DllImport(dllName, EntryPoint = "?RegRtnInstrumentStatus@@YGXP6GHPAUCThostFtdcInstrumentStatusField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnInstrumentStatus(RtnInstrumentStatus cb);
		RtnInstrumentStatus rtnInstrumentStatus;
		public delegate void RtnInstrumentStatus(ref CThostFtdcInstrumentStatusField pInstrumentStatus);
		/// <summary>
		/// 合约交易状态通知
		/// </summary>
		public event RtnInstrumentStatus OnRtnInstrumentStatus
		{
			add { rtnInstrumentStatus += value; regRtnInstrumentStatus(rtnInstrumentStatus); }
			remove { rtnInstrumentStatus -= value; regRtnInstrumentStatus(rtnInstrumentStatus); }
		}

		///报单通知
		[DllImport(dllName, EntryPoint = "?RegRtnOrder@@YGXP6GHPAUCThostFtdcOrderField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnOrder(RtnOrder cb);
		RtnOrder rtnOrder;
		public delegate void RtnOrder(ref CThostFtdcOrderField pOrder);
		/// <summary>
		/// 报单通知
		/// </summary>
		public event RtnOrder OnRtnOrder
		{
			add { rtnOrder += value; regRtnOrder(rtnOrder); }
			remove { rtnOrder -= value; regRtnOrder(rtnOrder); }
		}

		///期货发起查询银行余额通知
		[DllImport(dllName, EntryPoint = "?RegRtnQueryBankBalanceByFuture@@YGXP6GHPAUCThostFtdcNotifyQueryAccountField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnQueryBankBalanceByFuture(RtnQueryBankBalanceByFuture cb);
		RtnQueryBankBalanceByFuture rtnQueryBankBalanceByFuture;
		public delegate void RtnQueryBankBalanceByFuture(ref CThostFtdcNotifyQueryAccountField pNotifyQueryAccount);
		/// <summary>
		/// 期货发起查询银行余额通知
		/// </summary>
		public event RtnQueryBankBalanceByFuture OnRtnQueryBankBalanceByFuture
		{
			add { rtnQueryBankBalanceByFuture += value; regRtnQueryBankBalanceByFuture(rtnQueryBankBalanceByFuture); }
			remove { rtnQueryBankBalanceByFuture -= value; regRtnQueryBankBalanceByFuture(rtnQueryBankBalanceByFuture); }
		}

		///银行发起冲正银行转期货通知
		[DllImport(dllName, EntryPoint = "?RegRtnRepealFromBankToFutureByBank@@YGXP6GHPAUCThostFtdcRspRepealField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnRepealFromBankToFutureByBank(RtnRepealFromBankToFutureByBank cb);
		RtnRepealFromBankToFutureByBank rtnRepealFromBankToFutureByBank;
		public delegate void RtnRepealFromBankToFutureByBank(ref CThostFtdcRspRepealField pRspRepeal);
		/// <summary>
		/// 银行发起冲正银行转期货通知
		/// </summary>
		public event RtnRepealFromBankToFutureByBank OnRtnRepealFromBankToFutureByBank
		{
			add { rtnRepealFromBankToFutureByBank += value; regRtnRepealFromBankToFutureByBank(rtnRepealFromBankToFutureByBank); }
			remove { rtnRepealFromBankToFutureByBank -= value; regRtnRepealFromBankToFutureByBank(rtnRepealFromBankToFutureByBank); }
		}

		///期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		[DllImport(dllName, EntryPoint = "?RegRtnRepealFromBankToFutureByFuture@@YGXP6GHPAUCThostFtdcRspRepealField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnRepealFromBankToFutureByFuture(RtnRepealFromBankToFutureByFuture cb);
		RtnRepealFromBankToFutureByFuture rtnRepealFromBankToFutureByFuture;
		public delegate void RtnRepealFromBankToFutureByFuture(ref CThostFtdcRspRepealField pRspRepeal);
		/// <summary>
		/// 期货发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// </summary>
		public event RtnRepealFromBankToFutureByFuture OnRtnRepealFromBankToFutureByFuture
		{
			add { rtnRepealFromBankToFutureByFuture += value; regRtnRepealFromBankToFutureByFuture(rtnRepealFromBankToFutureByFuture); }
			remove { rtnRepealFromBankToFutureByFuture -= value; regRtnRepealFromBankToFutureByFuture(rtnRepealFromBankToFutureByFuture); }
		}

		///系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		[DllImport(dllName, EntryPoint = "?RegRtnRepealFromBankToFutureByFutureManual@@YGXP6GHPAUCThostFtdcRspRepealField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnRepealFromBankToFutureByFutureManual(RtnRepealFromBankToFutureByFutureManual cb);
		RtnRepealFromBankToFutureByFutureManual rtnRepealFromBankToFutureByFutureManual;
		public delegate void RtnRepealFromBankToFutureByFutureManual(ref CThostFtdcRspRepealField pRspRepeal);
		/// <summary>
		/// 系统运行时期货端手工发起冲正银行转期货请求，银行处理完毕后报盘发回的通知
		/// </summary>
		public event RtnRepealFromBankToFutureByFutureManual OnRtnRepealFromBankToFutureByFutureManual
		{
			add { rtnRepealFromBankToFutureByFutureManual += value; regRtnRepealFromBankToFutureByFutureManual(rtnRepealFromBankToFutureByFutureManual); }
			remove { rtnRepealFromBankToFutureByFutureManual -= value; regRtnRepealFromBankToFutureByFutureManual(rtnRepealFromBankToFutureByFutureManual); }
		}

		///银行发起冲正期货转银行通知
		[DllImport(dllName, EntryPoint = "?RegRtnRepealFromFutureToBankByBank@@YGXP6GHPAUCThostFtdcRspRepealField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnRepealFromFutureToBankByBank(RtnRepealFromFutureToBankByBank cb);
		RtnRepealFromFutureToBankByBank rtnRepealFromFutureToBankByBank;
		public delegate void RtnRepealFromFutureToBankByBank(ref CThostFtdcRspRepealField pRspRepeal);
		/// <summary>
		/// 银行发起冲正期货转银行通知
		/// </summary>
		public event RtnRepealFromFutureToBankByBank OnRtnRepealFromFutureToBankByBank
		{
			add { rtnRepealFromFutureToBankByBank += value; regRtnRepealFromFutureToBankByBank(rtnRepealFromFutureToBankByBank); }
			remove { rtnRepealFromFutureToBankByBank -= value; regRtnRepealFromFutureToBankByBank(rtnRepealFromFutureToBankByBank); }
		}

		///期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		[DllImport(dllName, EntryPoint = "?RegRtnRepealFromFutureToBankByFuture@@YGXP6GHPAUCThostFtdcRspRepealField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnRepealFromFutureToBankByFuture(RtnRepealFromFutureToBankByFuture cb);
		RtnRepealFromFutureToBankByFuture rtnRepealFromFutureToBankByFuture;
		public delegate void RtnRepealFromFutureToBankByFuture(ref CThostFtdcRspRepealField pRspRepeal);
		/// <summary>
		/// 期货发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// </summary>
		public event RtnRepealFromFutureToBankByFuture OnRtnRepealFromFutureToBankByFuture
		{
			add { rtnRepealFromFutureToBankByFuture += value; regRtnRepealFromFutureToBankByFuture(rtnRepealFromFutureToBankByFuture); }
			remove { rtnRepealFromFutureToBankByFuture -= value; regRtnRepealFromFutureToBankByFuture(rtnRepealFromFutureToBankByFuture); }
		}

		///系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		[DllImport(dllName, EntryPoint = "?RegRtnRepealFromFutureToBankByFutureManual@@YGXP6GHPAUCThostFtdcRspRepealField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnRepealFromFutureToBankByFutureManual(RtnRepealFromFutureToBankByFutureManual cb);
		RtnRepealFromFutureToBankByFutureManual rtnRepealFromFutureToBankByFutureManual;
		public delegate void RtnRepealFromFutureToBankByFutureManual(ref CThostFtdcRspRepealField pRspRepeal);
		/// <summary>
		/// 系统运行时期货端手工发起冲正期货转银行请求，银行处理完毕后报盘发回的通知
		/// </summary>
		public event RtnRepealFromFutureToBankByFutureManual OnRtnRepealFromFutureToBankByFutureManual
		{
			add { rtnRepealFromFutureToBankByFutureManual += value; regRtnRepealFromFutureToBankByFutureManual(rtnRepealFromFutureToBankByFutureManual); }
			remove { rtnRepealFromFutureToBankByFutureManual -= value; regRtnRepealFromFutureToBankByFutureManual(rtnRepealFromFutureToBankByFutureManual); }
		}

		///成交通知
		[DllImport(dllName, EntryPoint = "?RegRtnTrade@@YGXP6GHPAUCThostFtdcTradeField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnTrade(RtnTrade cb);
		RtnTrade rtnTrade;
		public delegate void RtnTrade(ref CThostFtdcTradeField pTrade);
		/// <summary>
		/// 成交通知
		/// </summary>
		public event RtnTrade OnRtnTrade
		{
			add { rtnTrade += value; regRtnTrade(rtnTrade); }
			remove { rtnTrade -= value; regRtnTrade(rtnTrade); }
		}

		///交易通知
		[DllImport(dllName, EntryPoint = "?RegRtnTradingNotice@@YGXP6GHPAUCThostFtdcTradingNoticeInfoField@@@Z@Z", CallingConvention = CallingConvention.StdCall)]
		static extern void regRtnTradingNotice(RtnTradingNotice cb);
		RtnTradingNotice rtnTradingNotice;
		public delegate void RtnTradingNotice(ref CThostFtdcTradingNoticeInfoField pTradingNoticeInfo);
		/// <summary>
		/// 交易通知
		/// </summary>
		public event RtnTradingNotice OnRtnTradingNotice
		{
			add { rtnTradingNotice += value; regRtnTradingNotice(rtnTradingNotice); }
			remove { rtnTradingNotice -= value; regRtnTradingNotice(rtnTradingNotice); }
		}
	}
}

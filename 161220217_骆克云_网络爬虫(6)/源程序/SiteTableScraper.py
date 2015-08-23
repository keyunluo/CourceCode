#-*- coding:utf-8 -*-

from  openpyxl.workbook  import  Workbook  
import urllib.request,urllib.error
import time
from bs4 import BeautifulSoup
import simplejson 

countnumber=1
Filename = "../(6)-161220217-骆克云.xlsx"
wb=Workbook()

#获取json数据
def getjsondata():
    url='http://hq.finance.ifeng.com/q.php?l=g_Ag_T_D_,g_Au_T_D_,g_Au100g,g_Au99_95,g_Au99_99,g_Pt99_95,g_Au_T_N1_,g_Au_T_N2_,g_kingXianhuo,g_gangXianhuo,g_baiyingxianhuo,g_boXianhuo,g_baXianhuo,g_mbj,g_mj,g_djy,g_mhjl,g_mbyl,g_djb,g_djj,g_dj&f=json&e=show_hq();&random=0.40822120290249586'
    req = urllib.request.Request(url)
    #异常处理
    try: response = urllib.request.urlopen(req)
    except urllib.error.HTTPError as e:
        print(e.code)
    text = response.read().decode("utf8")
    jsondata=simplejson.loads(text[11:-13])
    return jsondata


def parse():

    url_to_fetch = 'http://app.finance.ifeng.com/list/gold.php'
    #异常处理
    try:connection = urllib.request.urlopen(url_to_fetch)
    except urllib.error.HTTPError as e:
        print(e.code)
    text = connection.read()
    page_soup = BeautifulSoup(text)
    sheet=wb.create_sheet(0,title="第%d次爬取"%countnumber)
    
    #动态网页的抓取
    jsondata=getjsondata()

    for table in page_soup.find_all("table"):
        table_soup = BeautifulSoup(str(table))

        for body in table_soup:
            body = BeautifulSoup(str(body))
            rows = body.find_all("tr")


            for tr in rows:
                cols = tr.find_all(["td", "th"])

                if len(cols)==1:
                    Action=[True,False,False]
                else:                    Action[0]=False

                colsArr = []
                
                count=1;
                for td in cols:
                    data_set = str(td.string).strip()
                    if count==2 and Action[2]:
                       index=data_set.rfind("_",0,len(data_set))
                       extract=data_set[0:index]
                       data=jsondata[extract]
                       colsArr.append("%.2f"%data[0])
                       colsArr.append("%.2f"%data[2])
                       colsArr.append("%.2f"%data[5])
                       colsArr.append("%.2f%%"%data[6])
                       colsArr.append("%.2f"%data[1])
                       colsArr.append("%.2f"%data[3])
                       colsArr.append("%.2f"%data[4])
                       colsArr.append(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(data[7])))
                       break
                      
                    count=count+1
                    colsArr.append(data_set)
              
                if Action[2]:
                    colsArr.append(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())))
                    Action[1]=False
                if Action[1]:
                    colsArr.append("抓取时间")
                    Action[2]=True
                if Action[0]:
                    Action[1]=True
                    Action[0]=False
                sheet.append(colsArr)
    

    #静态网页的抓取
    url_static='http://www.fyme.com.cn/pub/index_hq_ifeng.php'
    try:connection = urllib.request.urlopen(url_static)
    except urllib.error.HTTPError as e:
        print(e.code)
    text = connection.read()
    page_soup = BeautifulSoup(text)

    for table in page_soup.find_all("table"):
        table_soup = BeautifulSoup(str(table))
        for body in table_soup:
            body = BeautifulSoup(str(body))
            rows = body.find_all("tr")
            count=0
            for tr in rows:
                count=count+1
                if count==1:
                    header=["泛亚有色金属交易所"]
                    sheet.append(header)
                    continue
                elif count==2:
                    header=["品种名称","结算价","最新价","开盘价","最高价","最低价","涨跌","成交量","总成交金额","订货量","抓取时间"]
                    sheet.append(header)
                    continue
                cols = tr.find_all(["td", "th"])
                colsArr = []                
                for td in cols:
                    data_set = str(td.string).strip()
                    colsArr.append(data_set)
                if (len(colsArr)!=10):
                    continue
                colsArr.append(time.strftime('%Y-%m-%d %H:%M:%S', time.localtime(time.time())))
                sheet.append(colsArr)

    



if __name__ == "__main__":
    while True:
        now=int(time.time())
        print("******************第%i次爬取数据******************"%countnumber)
        print(">>> 现在时间是: %s,开始爬取网页..."%time.strftime('%Y-%m-%d,%H:%M:%S', time.localtime(now)))
        parse()
        print(">>> 网页爬取完成，结果在'(6)-161220217-骆克云.xlsx表格'中")
        print(">>> 准备睡眠十分钟后重新爬取...")
        print(">>> 如果想停止运行，请按Ctrl+C键结束程序...")
        print("--------------------------------------------------\n")
        countnumber=countnumber+1
        wb.save(Filename)
        time.sleep(600)   

   

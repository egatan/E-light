import serial
ard = serial.Serial('COM5', 9600)

import pymysql
import datetime


conn = pymysql.connect(host='localhost', user='root', password='apmsetup',
                       db='egatan', charset='utf8')
curs = conn.cursor()

sql = "select DATE_FORMAT(reserve_date, '%Y-%m-%d'), DATE_FORMAT(reserve_time, '%H:%i'), led_theme FROM reserve_detail"
sql2 = "select count(*) FROM reserve_detail"


while 1:
   
    curs.execute(sql2)
    rs = curs.fetchone()
    
    curs.execute(sql)
    
    p = []
    
    for i in range(0,rs[0]):  
        rs2 = curs.fetchone()
        p.append(rs2)
        

    now = datetime.datetime.now()
    nowDate = now.strftime('%Y-%m-%d')
    nowTime = now.strftime('%H:%M')
#    print('for 시작')
    
    state = 0 
    
    for i in p:
        
        if nowDate in i and nowTime in i:
            
            state = 1
            
            led_theme = i[2]
            
            if led_theme == 'heart':
                
                ard.write(b'y')
                print ('heart')
                break
                
            elif led_theme == 'star':
                ard.write(b's')
                print ('star')
                break
            elif led_theme == 'smile':
                ard.write(b'n')
                print ('smile')
                break
            elif led_theme == 'xmas_tree':
                ard.write(b'p')
                print ('xmas_tree')
                break
            elif led_theme == 'blossom':
                ard.write(b'q')
                print ('blossom')
                break
            elif led_theme == 'hbd_cake':
                ard.write(b'r')
                print ('hbd_cake')
                break
            elif led_theme == 'park':
                ard.write(b't')
                print ('park')
                break
            else:
                print('break전')
                break
        
    if(state != 1):
            ard.write(b'o')
#            print('off')
#           print('for 끝')
            
             
conn.commit()
conn.close()
   
    
          
<head>
   <title> E-Light </title>
   <meta charset="utf-8">

   <style>
   

      
   #div_root{
      margin:  auto; 
      width:   800px;

   }  

   #div_top{
      width:   30%:
      height: 100px;
      text-align:    left;
      float: left;         
   }

   #div_hello{
      width:   70%:
      height: 100px;
      text-align:    left; 
   }

   #div_menu{
      width:   9%;
      height: 300px;
      float:   left; 
      text-align:    center;  
   }

   #div_line{
      width: 1%;
      height: 300px;
      float: left;

   }
   #div_con{
      width: 90%;
      height:  300px;
      float:  center;
      text-align:    center;
   }

   </style>
</head>


<body>

   <div id = div_top>
      <img src="logo5.jpg" width="327" height="100" onclick = "location.href='home5.php?id='$id'';">
   

      
   </div>

   <div id = div_hello>
      <div id="introduce">
         <br / ><br />
         <form action="login_check5.php" method="post">
            <?php
         
            $con = mysql_connect("localhost", "root", "apmsetup");
            mysql_select_db("egatan");


            mysql_query("set session character_set_connection=utf8;");

            mysql_query("set session character_set_results=utf8;");

            mysql_query("set session character_set_client=utf8;");
            
            $id=$_GET[id];

            $query = "select * from reserve_detail";
            $result = mysql_query($query, $con);

            $total_records = mysql_num_rows($result);
            $timestamp = new DateTime($result -> DT);
            

            $result2 = mysql_query("SELECT * FROM manager where id='$id'");
            //$getID="select ID from manager where id='$id'";
            
            while($row=mysql_fetch_array($result2, MYSQL_ASSOC)){
            
            $name=$row["Name"];
            $ID=$row["id"];
            $PW=$row["pw"];
            $park=$row["Park"];
            } 
            
            echo "관리자님 안녕하세요!";
            echo "<br>";
            print $timestamp->format("Y년m월d일 "); 
            echo "예약된 이벤트는 총 $total_records 건입니다.";

            ?>
         <a href='logout5.php'><input type='button' value='Logout'></a>
      </div>

   
   </div>

   <br  /><br  /><br  />


   <div id = div_menu>
      <button
         type = "button"
         onclick = "location.href='practice.php';"
         style =  "color: #fff;
         background: skyblue;
         font-size:1.2em;
         border-radius:0.2em;">예약 확인</button>
      <br  />
      <button
         type = "button"
         onclick = "location.href='practice2.php';"
         style =  "color: #fff;
         background: skyblue;
         font-size:1.2em;
         border-radius:0.2em;">회원 정보</button>     
   </div>

   <div id = div_line>
      
         <HR width="1" size="600">
      
   </div>

   <div id = "div_con" >
      <img src="공원.jpg" width="600" height="400">
      
   </div>
</body>


<head>
	<meta charset="utf-8">
	<title> E-Light </title>

	<style>


	#div_root{
		margin: 	auto;
		width: 	800px;
	}

	#div_top{
		width: 	30%:
		height: 100px;
		text-align: 	left;
		float: left;
	}

	#div_hello{
		width: 	70%:
		height: 100px;
		text-align: 	left;

	}

	#div_menu{
		width: 	9%;
		height: 300px;
		float: 	left;
		text-align: 	center;
	}

	#div_line{
		width: 1%;
		height: 300px;
		float: left;

	}
	#div_con{
		width: 90%;
		height: 	300px;
		float:  center;
		text-align: 	center;
	}

	</style>
</head>


<body>

	<div id = div_top>
		<img src="logo3.png" width="280" height="110" onclick = "location.href='home5.php';">

	</div>

	<div id = div_hello>
		<div id="introduce">
			<br / ><br />

			<form action="home5.php" method="post">

			<?php
				$con = mysql_connect("localhost", "root", "apmsetup");
				mysql_select_db("egatan");

				mysql_query("set session character_set_connection=utf8;");

				mysql_query("set session character_set_results=utf8;");

				mysql_query("set session character_set_client=utf8;");



				$id=$_GET[id];

				//$query = "select * from reserve_detail";


        $id=$_SESSION['id'];

				$result=mysql_query("select * from reserve_detail where id='$id'");

				$result2 = mysql_query("SELECT * FROM user where id='$id'");
				//$getID="select ID from manager where id='$id'";

				while($row=mysql_fetch_array($result2, MYSQL_ASSOC)){

				$name=$row["Name"];
				$ID=$row["id"];
				$PW=$row["pw"];
				$park=$row["Park"];
				}


				$total_records = mysql_num_rows($result);
				$timestamp = new DateTime($result -> DT);


				echo "$id 님 안녕하세요!";
				echo "<br>";
				print $timestamp->format("Y년m월d일 ");
				echo "예약된 이벤트는 총 $total_records 건입니다.";

				?>

        <button
  				type = "button"
  				onclick = "location.href='../reservation2.php';"
  				style =  "color: #fff;
  				background: skyblue;
  				font-size:1.4em;
  				border-radius:0.2em;
  			  margin-left:200px;">예약하기</button>

  				<button
  					type = "button"
  					onclick = "location.href='../admin/adminpanal2.php';"
  					style =  "color: #fff;
  					background: skyblue;
  					font-size:1.4em;
  					border-radius:0.2em;
  					margin-left:20px;
  					margin-bottom:20px;
  					">예약확인</button>
  					<button
  						type = "button"
  						onclick = "location.href='../logout.php';"
  						style =  "color: #fff;
  						background: skyblue;
  						font-size:1.4em;
  						border-radius:0.2em;
  						margin-left:20px;
  						margin-bottom:20px;
  						">로그아웃</button>




		</div>
	</div>

  <hr>
  <br />



	<div id = "div_con"  >

		<table class = "tblType1" border = 0 cellspacing=0 cellpadding = 0 style="text-align: center" >
			<tr>
        <th width = "150" class = "th1"> 예약번호</th>
				<th width = "150" class = "th1"> 아이디 </th>
				<th width = "150" class = "th2"> 예약날짜 </th>
				<th width = "150" class = "th2"> 예약시간 </th>
				<th width = "150" class = "th2"> 도시 </th>
				<th width = "150" class = "th2"> 구</th>
				<th width = "150" class = "th2"> 공원 </th>
				<th width = "150" class = "th4"> 구역 </th>
				<th width = "150" class = "th5"> led 테마 </th>
        <!-- <th width = "150" class = "th5"> UPDATE </th>
        <th width = "150" class = "th5"> DELETE </th> -->
			</tr>

			<tr height = 1 bgcolor=black><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td><td></td>
			</tr><tr>

				  <?php
	  			include('../include/connect.php');
          $id=$_SESSION['id'];
          $sql="select * from reserve_detail where id='$id'";
	  			//$sql="select * from reserve_detail ";
	  				$row=mysql_query($sql) or die (mysql_error($con));

	  			  ?>

	  			  <?php

	  				while($data=mysql_fetch_array($row))
	  				{
	  				?>
	  					<tr>
                <td><?php echo $data[num]; ?></td>
	  					<td><?php echo $data[id]; ?></td>
	 					<td><?php echo $data[reserve_date]; ?></td>
	 					<td><?php echo $data[reserve_time]; ?></td>
	 					<td><?php echo $data[city]; ?></td>
	  					<td><?php echo $data[district]; ?></td>
	  					<td><?php echo $data[park]; ?></td>
   	  					<td><?php echo $data[area]; ?></td>
      					<td><?php echo $data[led_theme]; ?></td>

                <!-- <td><a href="update.php?id=<?php echo $data[id]; ?>">update</a></td>
               <td><a href="delete.php?id=<?php echo $data[id]; ?>">delete</a></td> -->

		  				</tr>

	  				<?php
	  				}

					?>

	  	</table>

	</div>
</body>

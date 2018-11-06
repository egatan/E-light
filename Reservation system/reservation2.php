<?php
@ob_start();
session_start();
header('Content-Type: text/html; charset=utf-8');
?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.0 Transitional//EN">
<html>
<head>
<style type="text/css">
	#contenar{
		height: 100%;
		width: 100%;

	}
	#r{
		margin-top: 5%;
		margin-bottom: 5%;
		margin-right: 5%;
		margin-left: 5%;
		float: center;
		background-color:#BEF781;

	}

	/* table{
		width:60%;
		height: 100px;
		margin: auto;
		text-align: center;
	} */
	</style>



</head>

<body>
<?php
include('include/connect.php');

//session_start();
if(isset($_POST['sub']))
{
$name=$_POST['name'];
$id=$_POST['id'];
$reserve_date=$_POST['reserve_date'];
$reserve_time=$_POST['reserve_time'];
$city=$_POST['field_1'];
$district=$_POST['field_2'];
$park=$_POST['field_3'];
$area=$_POST['field_4'];
$led_theme=$_POST['field_5'];

$s1="INSERT INTO reserve_detail (id,reserve_date,reserve_time,city,district,park,area,led_theme)VALUES('".$id."','".$reserve_date."','".$reserve_time."','".$city."','".$district."','".$park."','".$area."','".$led_theme."')";
mysql_query($s1) or die (mysql_error($con));
header("location:success.php");
}
?>


<br>
<!-- <img src="logo3.png" width="280" height="110" align="middle">예약 페이지 -->
<h2 align="center" id="h">예약 페이지</h2>
<div id="contenar" >

	<div id="r" >
	<form action="reservation2.php" method="POST">

	<tr>
	<!-- <h2 align="center" id="h">예약 페이지</h2> -->
  <h3>
	<?php session_start(); if(isset($_SESSION['id'])){ echo $_SESSION['id']; } ?> 님 환영합니다!</h3>

        <table >
          <tr>
          <tr>
            <td width="113">예약 날짜</td>
            <td width="215">
              <input name="reserve_date1" type="date"  value="<?php if(isset($_POST['reserve_date1'])){ echo $_POST['reserve_date1']; }?>" /></td>
          </tr>
          <tr>
            <td>예약 시간</td>
            <td>
              <input name="reserve_time1" type="time" value="<?php if(isset($_POST['reserve_time1'])){ echo $_POST['reserve_time1']; }?>" onchange='this.form.submit()' /></td>
          </tr>
					<?php


					 ?>


       </table>
		</form>
		<form action="reservation2.php" method="POST">
        <table >

          <tr>
            <td width="113"></td>
            <td width="215">
              <input name="reserve_date" type="hidden" value=" <?php if(isset($_POST['reserve_date1'])){ echo $_POST['reserve_date1']; }?> " /></td>
          </tr>
          <tr>
            <td><input name="name" type="hidden" value="<?php session_start(); if(isset($_POST['name'])){ echo $_POST['name']; } ?>"  /></td>
            <td><input name="id" type="hidden" value="<?php session_start(); if(isset($_SESSION['id'])){ echo $_SESSION['id']; } ?>"  />
              <input name="reserve_time" type="hidden" value=" <?php if(isset($_POST['reserve_time1'])){ echo $_POST['reserve_time1']; }?> "  /></td>
          </tr>
		  <tr>
            <td>도시 선택 </td>
            <td>
              <select class="text_select" id="field_1" name="field_1" >
<option value="00">- 선택 -</option>
<option value='서울' name='field_1'>서울</option>
<!-- <option value='서울' name='field_1'>인천</option> -->

  </select>
<script>
    document.getElementById("field_1").value = "<?=$field_1?>";
</script>

     <tr>
            <td>지역 선택 </td>
            <td>
              <select class="text_select" id="field_2" name="field_2" >
<option value="00">- 선택 -</option>
<option value='영등포구' name='field_2'>영등포구</option>
<option value='성동구' name='field_2'>성동구</option>
<option value='중구' name='field_2'>중구</option>
<option value='마포구' name='field_2'>마포구</option>
<option value='송파구' name='field_2'>송파구</option>
<option value='종로구' name='field_2'>종로구</option>

            </select></td>
          </tr>
<script>
		document.getElementById("field_2").value = "<?=$field_2?>";
</script>
      <tr>
            <td>공원 선택 </td>
            <td>
              <select class="text_select" id="field_3" name="field_3" >
<option value="00">- 선택 -</option>
<option value='여의도 한강공원' name='field_3'>여의도 한강공원</option>
<option value='서울숲 공원'  name='field_3'>서울숲 공원</option>
<option value='남산 공원' name='field_3'>남산 공원</option>
<option value='월드컵 공원' name='field_3'>월드컵 공원</option>
<option value='올림픽 공원' name='field_3'>올림픽 공원</option>
<option value='낙산공원' name='field_3'>낙산공원</option>


            </select></td>
          </tr>
<script>
		document.getElementById("field_3").value = "<?=$field_3?>";
</script>
          <tr>
                <td>구역 선택 </td>
                <td>
                  <select class="text_select" id="field_4" name="field_4" >
<option value="00">- 선택 -</option>
<option value='1' name='field_4'>1</option>
<option value='2' name='field_4'>2</option>
<option value='3' name='field_4'>3</option>
<option value='4' name='field_4'>4</option>
           </select></td>
         </tr>
<script>
    document.getElementById("field_4").value = "<?=$field_4?>";
</script>
					<tr>
							<td>LED 테마 선택 </td>
							<td>
								<select class="text_select" id="field_5" name="field_5" >
<option value="00">- 선택 -</option>
<option value='heart' name='field_5'>heart</option>
<option value='smile' name='field_5'>smile</option>
<option value='star' name='field_5'>star</option>
<option value='reverse' name='field_5'>reverse</option>
<option value='xmas_tree' name='field_5'>xmas_tree</option>
<option value='blossom' name='field_5'>blossom</option>
<option value='hbd_cake' name='field_5'>hbd_cake</option>
<option value='park' name='field_5'>park</option>

<script>
		document.getElementById("field_5").value = "<?=$field_5?>";
</script>

<tr>
	<td colspan="2" align="center">
<input type="submit" name="sub" value="Submit" /></td>
	</tr>

</table>
</form>

<script language="javascript" type="text/javascript">
function notEmpty(){

var e1 = document.getElementById("field_1");
var e2 = document.getElementById("field_2");
var e3 = document.getElementById("field_3");
var e4 = document.getElementById("field_4");
var e5 = document.getElementById("field_5");

var strUser = e1.options[e1.selectedIndex].value;
var strUser = e2.options[e2.selectedIndex].value;
var strUser = e3.options[e3.selectedIndex].value;
var strUser = e4.options[e4.selectedIndex].value;
var strUser = e5.options[e5.selectedIndex].value;

// var strUser=document.getElementById('a1').innerHTML=strUser;


}
notEmpty()

    document.getElementById("field_1").onchange = notEmpty;
    document.getElementById("field_2").onchange = notEmpty;
    document.getElementById("field_3").onchange = notEmpty;
    document.getElementById("field_4").onchange = notEmpty;
    document.getElementById("field_5").onchange = notEmpty;


			</script>




	</div>
</div>
</body>
</html>

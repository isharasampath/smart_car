const char HOME_PAGE[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
<style>
table, th, td {
  border: 0px solid black;
  border-collapse: collapse;
}

table.center {
  margin-left: auto; 
  margin-right: auto;
}

.button {
  background-color: #000000;
  border: none;
  color: white;
  padding: 15px 32px;
  text-align: center;
  text-decoration: none;
  display: inline-block;
  font-size: 50px;
  margin: 4px 2px;
  cursor: pointer;
  width:220px;
  height:80px;
}
</style>
</head>
<body>

<table class="center">
  <tr>
    <th><div class="button" id="btnFL" ontouchstart="mouseDownFL()" ontouchend="mouseUpFL()" onmousedown="mouseDownFL()" onmouseup="mouseUpFL()">&#11009</div></th>
    <th><div class="button" id="btnF" ontouchstart="mouseDownF()" ontouchend="mouseUpF()" onmousedown="mouseDownF()" onmouseup="mouseUpF()">&#8679</div></th> 
    <th><div class="button" id="btnFR" ontouchstart="mouseDownFR()" ontouchend="mouseUpFR()" onmousedown="mouseDownFR()" onmouseup="mouseUpFR()">&#11008</div></th>
  </tr>
  <tr>
    <th><div class="button" id="btnBL" ontouchstart="mouseDownBL()" ontouchend="mouseUpBL()" onmousedown="mouseDownBL()" onmouseup="mouseUpBL()">&#11011</div></th>
    <th><div class="button" id="btnB" ontouchstart="mouseDownB()" ontouchend="mouseUpB()" onmousedown="mouseDownB()" onmouseup="mouseUpB()">&#8681</div></th> 
    <th><div class="button" id="btnBR" ontouchstart="mouseDownBR()" ontouchend="mouseUpBR()" onmousedown="mouseDownBR()" onmouseup="mouseUpBR()">&#11010</div></th>
  </tr>
</table>



<script>
function mouseDownF() {
  document.getElementById("btnF").style.color = "red";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=FF", true);
  xhr.send();
}

function mouseDownFL() {
  document.getElementById("btnFL").style.color = "red";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=FL", true);
  xhr.send();
}

function mouseDownFR() {
  document.getElementById("btnFR").style.color = "red";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=FR", true);
  xhr.send();
}

function mouseDownB() {
  document.getElementById("btnB").style.color = "red";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=BB", true);
  xhr.send();
}

function mouseDownBL() {
  document.getElementById("btnBL").style.color = "red";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=BL", true);
  xhr.send();
}

function mouseDownBR() {
  document.getElementById("btnBR").style.color = "red";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=BR", true);
  xhr.send();
}

function mouseUpF() {
  document.getElementById("btnF").style.color = "white";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=SS", true);
  xhr.send();
}

function mouseUpFL() {
  document.getElementById("btnFL").style.color = "white";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=SS", true);
  xhr.send();
}

function mouseUpFR() {
  document.getElementById("btnFR").style.color = "white";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=SS", true);
  xhr.send();
}

function mouseUpB() {
  document.getElementById("btnB").style.color = "white";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=SS", true);
  xhr.send();
}

function mouseUpBL() {
  document.getElementById("btnBL").style.color = "white";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=SS", true);
  xhr.send();
}

function mouseUpBR() {
  document.getElementById("btnBR").style.color = "white";
  var xhr = new XMLHttpRequest();
  xhr.open("GET", "/drive?mode=SS", true);
  xhr.send();
}
</script>

</body>
</html>
)=====";

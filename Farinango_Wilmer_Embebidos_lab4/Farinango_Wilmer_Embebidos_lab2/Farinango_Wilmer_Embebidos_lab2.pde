import processing.serial.*;
Serial port;
float datoEstatura;
float auxEstatura=0;
float datoPeso;
int aux=0;
PFont font;
PImage img;

void setup (){
  
  port= new Serial(this, "COM10",9600);
  img = loadImage("descarga.png");
  size(900,500); // ancho, alto
  background(#900C3F); //color de fondo RGB
  stroke(0);
  strokeWeight(1);
  line(50,5,50,450);
  line(50,450,650,450);
  line(50,450,650,450);
  
  stroke(255,255,255);
  strokeWeight(1);
  line(125,5,125,450);
  line(200,5,200,450);
  line(275,5,275,450);
  line(350,5,350,450);
  line(425,5,425,450);
  line(500,5,500,450);
  line(575,5,575,450);
  line(650,5,650,450);
  
  line(50,400,650,400);
  line(50,350,650,350);
  line(50,300,650,300);
  line(50,250,650,250);
  line(50,200,650,200);
  line(50,150,650,150);
  line(50,100,650,100);
  line(50,50,650,50);
  
  textSize(20);
  fill(255,255,255);
  text("0",35,450);
  text("10",15,400);
  text("20",15,350);
  text("30",15,300);
  text("40",15,250);
  text("50",15,200);
  text("60",15,150);
  text("70",15,100);
  text("80",15,50);
  
  text("150",25,470);
  text("155",100,470);
  text("160",175,470);
  text("165",250,470);
  text("170",325,470);
  text("175",400,470);
  text("180",475,470);
  text("185",550,470);
  text("190",625,470);
  
  textSize(10);
  font = loadFont("Serif.bold-22.vlw"); // Leer la fuente
  textFont(font);
  fill(#FF5733);
  text("LABORATORIO 4",700,50);
  text("Wilmer Farinango",700,100);
  text("PESO/ESTATURA",700,150);
  text("x-133.39 y=1.1797",710,180);
   
}
void serialEvent(Serial port){
  datoEstatura=port.read();
  auxEstatura=int(datoEstatura); //Convertir de string a int
  println("Estatura= ");
  println(datoEstatura);
  datoPeso=datoEstatura*(1.1797)-133.39;
  println("Peso= ");
  println(datoPeso);
}

void draw(){
  
  image(img, 664, 250);
  
  if(datoPeso>0){
  stroke(100,255,100);
  strokeWeight(2);
  fill(0,255,0);
  ellipse((datoEstatura*15)-2200,450-(datoPeso)*5,10,10);
  }
  
  stroke(255,0,0);
  strokeWeight(2);
  fill(255,0,0);
  
  ellipse((170*15)-2200,450-67*5,5,5); //centro, ancho y altura
  ellipse((180*15)-2200,450-80*5,5,5); //centro, ancho y altura
  ellipse((170*15)-2200,450-65*5,5,5); //centro, ancho y altura
  ellipse((178*15)-2200,450-75*5,5,5); //centro, ancho y altura
  ellipse((160*15)-2200,450-55*5,5,5); //centro, ancho y altura
  ellipse((163*15)-2200,450-60*5,5,5); //centro, ancho y altura
  ellipse((165*15)-2200,450-63*5,5,5); //centro, ancho y altura
  ellipse((170*15)-2200,450-70*5,5,5); //centro, ancho y altura
  ellipse((164*15)-2200,450-62*5,5,5); //centro, ancho y altura
  ellipse((176*15)-2200,450-77*5,5,5); //centro, ancho y altura
  ellipse((164*15)-2200,450-60*5,5,5); //centro, ancho y altura
  ellipse((170*15)-2200,450-76*5,5,5); //centro, ancho y altura
  ellipse((170*15)-2200,450-56*5,5,5); //centro, ancho y altura
  ellipse((168*15)-2200,450-60*5,5,5); //centro, ancho y altura
  
  stroke(0,0,255);
  strokeWeight(1);
  line(150*15-2200,450-43.565*5,(190*15)-2200,450-90.753*5); //punto de inicio, punto de fin
}

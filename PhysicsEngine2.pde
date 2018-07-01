//import java.util.*;

      int   NUM_C  = 3;
final int   NUM_L  = 4;
final int   FRAME  = 100;
final float elasticLC = 100/100.0;
final int   MAX_C  = 128; 
      //float eL = 90/100.0;
      //float eC = 997/1000.0;
      float eL = 100/100.0;
      float eC = 1000/1000.0;
      
      int   NUM    = NUM_C - 1;//curlent circle
int i,j,k;


Flags             flag  = new Flags();
Circle[]          ci    = new Circle[MAX_C];
Line[]            li    = new Line[NUM_L];
Collision cd_cc = new Collision();
Collision cd_cl = new Collision();
 PVector bc = new PVector();//use for Detector
 PVector ec = new PVector();

public void setup(){
  fullScreen();
  frameRate(66);
  strokeWeight(5);
  for(i = 0;i<NUM_C;i++){
    switch(i){
      default : ci[i] = new Circle();
    }
  }
  for(i = 0;i<NUM_L;i++){
    switch(i){
      case 0:li[0] = new Line();
        li[0].set(0+FRAME,0+FRAME,width-FRAME,0+FRAME);break;
      case 1:li[1] = new Line();
        li[1].set(width-FRAME,0+FRAME,width-FRAME,height-FRAME);break;
      case 2:li[2] = new Line();
        li[2].set(width-FRAME,height-FRAME,0+FRAME,height-FRAME);break;
      case 3:li[3] = new Line();
        li[3].set(0+FRAME,height-FRAME,0+FRAME,0+FRAME);break;
        
      case 4:li[i] = new Line();
        li[4].set(300,300,800,300);break;
      case 5:li[i] = new Line();
        li[5].set(800,300,550,800);break;
      case 6:li[i] = new Line();
        li[6].set(550,800,300,300);break;
//      case 7:li[i].set(width-FRAME,height-FRAME,0+FRAME,height-FRAME);break;
      
      default : li[i] = new Line();
    }
    li[i].bpci.setNothing(li[i].bp.x,li[i].bp.y);
    li[i].epci.setNothing(li[i].ep.x,li[i].ep.y);
  }
}

public void draw(){
  background(235,255,245);
  if(flag.upKey)   {ci[NUM].sp.y-=0.32;}
  if(flag.downKey) {ci[NUM].sp.y+=0.32;}
  if(flag.rightKey){ci[NUM].sp.x+=0.32;}
  if(flag.leftKey) {ci[NUM].sp.x-=0.32;}
  
  for(i=0;i<NUM_L;i++){
    for(j=0;j<NUM_C;j++){
      if(cd_cl.detectLtoC(li[i],ci[j])){
        cd_cl.solveLtoC(li[i],ci[j]);
      }
    }
  }
  for(i=0;i<NUM_C;i++){
    for(j=i;j<NUM_C;j++){
      if(i==j)continue;
      if(abs(ci[i].po.x - ci[j].po.x) > (ci[i].radius + ci[j].radius))continue;
      if(cd_cc.detectCtoC(ci[i],ci[j])){
      cd_cc.solveCtoC(ci[i],ci[j]);
      }
    }
  }
  
  for(i = 0;i < NUM_L;i++){
    li[i].draw();
  }
  
  
  for(i = 0;i < NUM_C;i++){
    if(i == NUM_C - 1){
      fill(255,200,255);
    }else{
      fill(255,255,255);
    }
    ci[i].draw();
    ci[i].update();
  }
  
}

public void keyReleased(){
  switch(keyCode){
    case UP   :flag.upKey    = false;break;
    case DOWN :flag.downKey  = false;break;
    case RIGHT:flag.rightKey = false;break;
    case LEFT :flag.leftKey  = false;break;
  }
}
  
public void keyPressed(){
  switch(key){
    case 'p':if(NUM_C+1!=MAX_C){
      ci[NUM_C] = new Circle();
      NUM_C++;
      NUM = NUM_C - 1;
      }break;
    case 'm':if(NUM_C!=1){
      NUM_C--;
      NUM = NUM_C - 1;
      }break;
    case 'd':exit();break;
    case 's':for(k=0;k<NUM_C;k++)ci[k].sp.set(0,0);break;
  }
  
  switch(keyCode){
    case UP   :flag.upKey    = true;break;
    case DOWN :flag.downKey  = true;break;
    case RIGHT:flag.rightKey = true;break;
    case LEFT :flag.leftKey  = true;break;
  }
}
class Ky009{
  private:
  int thisNegative;
  int thisRed;
  int thisGreen;
  int thisBlue;
  public:
  Ky009(int negative, int red, int green, int blue);
  void randomLight();
  void on();
};

Ky009::Ky009(int negative, int red, int green, int blue){
  thisNegative=negative;
  thisGreen=green;
  thisRed=red;
  thisBlue=blue;
  pinMode (green, OUTPUT);
  pinMode (blue, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (negative, OUTPUT);
}
void Ky009::on(){
  digitalWrite (thisNegative, HIGH);
}
void Ky009::randomLight(){
  analogWrite (thisBlue, random(255));//green
  analogWrite (thisGreen, random(255));//red
  analogWrite (thisRed, random(255));//blue
}


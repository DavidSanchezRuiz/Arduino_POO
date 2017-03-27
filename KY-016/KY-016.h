class Ky016{
  private:
  int thisNegative;
  int thisGreen;
  int thisRed;
  int thisBlue;
  public:
  Ky016(int negative, int blue, int green, int red);
  void randomLight();
};

Ky016::Ky016(int negative, int blue, int green, int red){
  thisNegative=negative;
  thisGreen=green;
  thisRed=red;
  thisBlue=blue;
  pinMode (green, OUTPUT);
  pinMode (blue, OUTPUT);
  pinMode (red, OUTPUT);
  pinMode (negative, OUTPUT);
  digitalWrite (negative, LOW);
}
void Ky016::randomLight(){
  analogWrite (thisGreen, random(255));//green
  analogWrite (thisBlue, random(255));//blue
  analogWrite (thisRed, random(255));//red
}

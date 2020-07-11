/*
~~Kullanıcının Binary Olarak Girdiği Sayıda 1 Olan Yerlerdeki Ledlerin Yanması~~
Kullanıcı led adedi kadar 1 ve 0'lardan oluşan sayiyi girer. Girdiği sayıda
1 sayısının yeri hangi ledin sırasına karşılık geliyorsa o led yanar. 0 sayısına
karşılık gelen ledler yanmaz.
*/
int a[8] = {11,10,9,8,7,6,5,4}; //Ledlerin bulunduğu pin numaraları bir diziye atandı.
String str;
char char_array[8];
void setup() //Ledlerin bulunduğu pinler çıkış pini olarak ayarlandı.
{
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  
  Serial.begin(9600); //Seri monitör 9600 baunda ayarlandı.
}

void loop()
{
  Serial.println("Lutfen yanmasini istediginiz ledin yerine 1 sayisini giriniz:");
  while(Serial.available() == 0){} //Dışarıdan girilen bir sayı var mı yok mu kontrol edildi.Eğer girilen bir sayı yoksa while döngüsüne girdi.
  
 Serial.print("Girilen sayi:");
  str = Serial.readString(); //Kullanıcının girdiği sayı bir string değişkene atandı.
  
  str.toCharArray(char_array, str.length()); //Stringe atanan girdinin uzunluğu da hesaba katılarak elemanları teker teker char dizisine atandı.  
  for(int i=0;i<8;i++)
  {
  digitalWrite(a[i],LOW); //Programa her başlanıldığında ledlerin yanmaması sağlandı.
  }
  Serial.println(str);
  for(int i=0;i<8;i++) //Girilen sayıdaki elemanlar for döngüsü ile tarandı.
  {
  if(char_array[i] == '1') //Eleman eğer 1 ise if bloğunun içine girdi ve o sıradaki ledin yanması sağlandı.
  {
  digitalWrite(a[i], HIGH);
  }
  }
}
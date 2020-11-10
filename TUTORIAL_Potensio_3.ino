/*
   TUTORIAL POTENSIOMETER PADA ARDUINO DENGAN MAPPING NILAI DAN LED

   Pinout (dari kiri ke kanan potensiometer) :
   GND,A0,VCC

   Untuk membaca nilai dari pin analog (nilai 0 - 1023)
   dan mapping ke nilai tertentu
   cerminkan ke nyala led

   A0 -> kaki tengah potensio
   D4 -> Led Merah
   D5 -> Led Hijau
   D6 -> Led Biru
   D7 -> Led Kuning
*/

#define merah 4
#define hijau 5
#define biru 6
#define kuning 7
#define pinPotensio A0

void setup() {
  pinMode(pinPotensio, INPUT); //set menjadi input
  pinMode(merah, OUTPUT); //set menjadi output
  pinMode(hijau, OUTPUT); //set menjadi output
  pinMode(biru, OUTPUT); //set menjadi output
  pinMode(kuning, OUTPUT); //set menjadi output
  Serial.begin(115200); //memulai komunikasi serial pada baud rate 115200
  Serial.println("Mencoba mapping nilai potensiometer pada Arduino dan led indikator");
}

void loop() {
  int hasil = analogRead(pinPotensio); //ambil data nilai A0 dan simpan ke variabel hasil
  int hasilMap = map(hasil, 0, 1023, 0, 4); //mapping nilai 0 s/d 1023 ke 0 s/d 4
  Serial.println("Nilai dari potensio : " + String(hasil)); //tampilkan pada serial monitor
  Serial.println("Nilai hasil mapping : " + String(hasilMap)); //tampilkan pada serial monitor

  if (hasilMap == 0) {
    digitalWrite(kuning, LOW);
    digitalWrite(biru, LOW);
    digitalWrite(hijau, LOW);
    digitalWrite(merah, LOW);
  }

  if (hasilMap == 1) {
    digitalWrite(kuning, HIGH);
    digitalWrite(biru, LOW);
    digitalWrite(hijau, LOW);
    digitalWrite(merah, LOW);
  }

  if (hasilMap == 2) {
    digitalWrite(kuning, HIGH);
    digitalWrite(biru, HIGH);
    digitalWrite(hijau, LOW);
    digitalWrite(merah, LOW);
  }

  if (hasilMap == 3) {
    digitalWrite(kuning, HIGH);
    digitalWrite(biru, HIGH);
    digitalWrite(hijau, HIGH);
    digitalWrite(merah, LOW);
  }

  if (hasilMap == 4) {
    digitalWrite(kuning, HIGH);
    digitalWrite(biru, HIGH);
    digitalWrite(hijau, HIGH);
    digitalWrite(merah, HIGH);
  }

  delay(100);  //jeda waktu 
}

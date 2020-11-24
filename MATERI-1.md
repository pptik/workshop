# Workshop IOT

**Materi Workshop IOT untuk microcontroller IOT**

Dalam materi ini akan membahas panduan perakitan soil moisture dan pompa air.
Ada dua tahap yang akan dilakukan dalam merakit soil moisture dan pompa air yaitu: 
- Menampilkan data value dari soil moisture dan pompa air melalui serial monitor
- Mengirimkan data value dari soil moisture dan pompa air melalui serial monitor dan mengirimkan data ke MQTT agar bisa di pantau melalui aplikasi mobile, dan pada materi ini poimpa akan di kontrol secara otomatis.
 
 
 # 1. MATERI 1
 
 **PANDUAN MERAKIT SOIL MOISTURE**
 1. Komponen yang dibutuhkan:
    - Sensor soil moisture FC-28
    
    ![image](https://user-images.githubusercontent.com/18458955/94101022-38fef980-fe59-11ea-9c25-cd27c81c8872.png)

    - Wemos D1 Mini (ESP8266)
    
    ![](https://grobotronics.com/images/detailed/112/wemos-d1-mini-esp8266-wifi-development-board-0_grobo.jpg)
    
    - PCB Bolong jika ingin wiring dengan skema sendiri atau menggunakan PCB Khusus Soil Moisture
    - Kabel Jumper Female-Female jika tidak menggunakan PCB 
    
    ![](https://s1.bukalapak.com/img/134621537/w-1000/Kabel_Jumper_Female___Female_Breadboard_Arduino_Wire_Sensor_.jpg)

    - Box (Opsional)
    
    ![](https://ecs7.tokopedia.net/img/cache/700/product-1/2020/7/19/1060408/1060408_6cbbff5d-9f36-4815-8747-6aa81a5d4fe5_700_700)
    
    - Kabel data usb micro (Kabel harus bisa mengirimkan data bukan hanya power)
    - Adaptor usb 5v 1-2A 
    
    ![](https://www.jakartanotebook.com/images/products/14/63/7501/3/travel-adapter-charge-5v-20a-for-samsung-galaxy-note-ii-white-2.jpg)
   
   
  2. Langkah-langkah merakit:
  
     - Wiring komponen seperi berikut :
     
     ![sooil moisture](https://user-images.githubusercontent.com/18458955/94108775-1c1ef200-fe6a-11ea-9abd-34e59751b45c.png)

     - Lakukan Kalibrasi
       Setelah melakukan perakitan pada senssor moisture dan wemos , sebbaiknya dilakukan kalibrasi terlebih dahulu pada komponen untuk mencegah penggunaan komponen yang rusak serta memudahkan untuk melakukan annallissa jika tejadi kesalahan.
      - Kalibrasi pada wemos D1 Mini
       Langkah-langkah yang harus dilakukan ketika akan melakukan kalibrasi pada wemos adalah sebagai berikut:
        - Pastikan pin male  telah terpasang dan tidak saling terhubung nat pinnya.
        - Siapkan avometer , analog / digital.
        - Siapkan kabel adapter / kabel usb yanng akan digunakan sebagai sumbber tegangan wemos dan sebagai uploader program wemos.
        - Setelah semua komponen siap, maka hubungkan kabel charger pada wemos board, lalu hubungkan probe (+) pada avometer ke pin tegangan(yangg 5V atau 3V) kemudian probe negatif (-) pada avometer ke pin ground.
        - Setelah tepasang, nyalakan avometer, pasang ke posisi teggangann , pastikan sebelum digunakan, avometer pun sudah dilakukan kalibrasi.
        - Lalu perrhatikan nilai yang ditunjukan avometer, jika ppada teganggan 3V, maka jarum avometer (analog) akan berada di angka 2 hingga 3, jika pada avometer digital akann menunjukan angka 2,5 hingga 3,3V.
            
      - Kalibrasi pada komponen soil moisture
       Langkah-langkah  yang harus dilakukan ketika akan melakukan kalibrasi pada soil moisture adalah sebagai berkut:
        - Langkah pertama, ialah siapkan baterai sebagai sumber tegangan, avometer untuk mengecek tegangan pada sensor, dan sensor itu sendiri.
        - Lalu pin VCC pada sensor dihubungkan pada kutub positif pada baterai dan pada probe positif (+) pada avometer (biasanya yang berwarna merah). Lalu untuk pin GND, hubungkan pada kutub negative pada baterai dan juga probe negative (-) pada avometer (biasanya berwarna hitam).
        - Setelah terpasang dengan baik, set avometer pada DCv.
        - Lalu perhatikan nilai yang ditunjukkan oleh avometer, rata-rata kisaran nilainya berada pada 1,3V hingga 1,5V.
        
       - Memasang wemos pada PCB
            Setelah dilakukan kalibrasi, dan pastikan hasilnya sesuai, kemudian pasang wemos pada PCB yang telah disediakan. Hati-hati ketika melakukan pemasangan wemos pada PCB, pastikan pin nya sesuai. Setelah terpasang, lalu solder bagian-bagian yang terhubung, untuk memudahkan solder bagian pin yang dijadikan sebagai input, sumber tegangan dan ground. Tetapi, untuk menghindari kesalahan ketika program di run pada wemos, sebaiknya semua pin di solder, agar semua jalur terhubung dan tidak sulit ketika melakukan analisis.
            ![image](https://user-images.githubusercontent.com/18458955/94388790-40374780-0178-11eb-888a-2686de828357.png)
            
       - Memasang soil sensor pada PCB
       
            **IKUTI SKEMA WIRING** ==> [Skema Wiring](https://user-images.githubusercontent.com/18458955/94108775-1c1ef200-fe6a-11ea-9abd-34e59751b45c.png)
            
            Pada soil sensor terdapat 6 pin, yang terbagi pada dua sisi, dengan 2 pin sebagai pin inputan untuk mendeteksi kelembaban. Pada sisi lainnya, terdapat 4 pin, yakni pin VCC (input tegangan), GND (input ground), D0 (digital out untuk digital output), dan AO (analog out untuk analog output). Pin VCC dan GND dipasang pada pin yang sesuai pada PCB. Untuk VCC pasang pada tegangan 5V dan GND pasang pada ground. 
Proses pemasangan, sambungkan  kabel jumper female ke pin soil sesuai denggan skema. Kemudian untuk DO dipasang pada pin () pada PCB dan AO pada pin AO di PCB. 
            ![](https://www.circuitstoday.com/wp-content/uploads/2017/03/Pin-out.jpg)
            ![](https://cf.shopee.co.id/file/5fc160e882d3b7c741788f8502149ddb)
       - Memasang soil sensor pada PC
           Sambungkan kabel data / kabel usb ke usb hub pada wemos 
           ![](https://devonhubner.org/pix/wemos_d1_mini_usb_connected_for_flashing.jpg)
       - Input Program
           Setelah proses perakitan selesai, input program pada wemos, kemudian lakukan running dan cek apakah alat bekerja dengan baik atau tidak.
           ikuti [Program](https://github.com/pptik/pkl-online-iot/tree/master/Microcontroller/Tahap-1-Serial-Monitor/soil-moisture-serial) berikut!
           Program menggunakan : 
           - Arduinno IDE [Download](https://www.arduino.cc/download_handler.php?f=/arduino-1.8.13-windows.exe)
           - ESP8266 Board Library, Cara install dapat dilihat [Disini](https://kelasrobot.com/2-cara-sukses-pasang-install-board-esp8226-ke-arduino-ide/)
           Setelah alikasi dan library di siapkan, jalankan program yang telah di [Download](https://github.com/pptik/pkl-online-iot/blob/master/Microcontroller/Tahap-1-Serial-Monitor/soil-moisture-serial/soil-moisture-serial.ino). Dan lakukan eksekusi program. Sebelum eksekusi program lakukan set up pada Arduino IDE untuk untuk wemos D1 Mini denggan melihat [Tutorial](http://www.jogjarobotika.com/blog/tutorial-install-wemos-pada-arduino-ide-b135.html)
        - Pengujian Soil Moisture
          Pada tahap ini, proses perakitan telah selesai dilakukan dan siap untuk melakukan pengujian dengan cara memasang soil moisture pada tanah untuk kemudian perhatikan nilai yang didapat oleh sensor, apakah sesuai atau tidak dengan program yang sebelumnya telah dibuat.
Berikut contoh data yang dihasilkan oleh sensor yang ditampilkan pada serial monitor arduino IDE. **PASTIKAN SERIAL DI SET 115200**
          ![](/Images/serial-monitor-soil.png)
          Contoh implementasi di tanah: 
          ![](/Images/implementasi-soil.jpg)
          Untuk lebih lengkapnya dapat di lihat di [Video Perakitan](http://forum.pptik.id/showthread.php?tid=703)
          


        
        
            
        
            
            
       
            

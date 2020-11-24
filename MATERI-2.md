# Workshop IOT

**Materi Workshop IOT untuk microcontroller IOT**

Dalam materi ini akan membahas panduan perakitan soil moisture dan pompa air.
Ada dua tahap yang akan dilakukan dalam merakit soil moisture dan pompa air yaitu: 
- Menampilkan data value dari soil moisture dan pompa air melalui serial monitor
- Mengirimkan data value dari soil moisture dan pompa air melalui serial monitor dan mengirimkan data ke MQTT agar bisa di pantau melalui aplikasi mobile, dan pada materi ini poimpa akan di kontrol secara otomatis.
 

 # 1. MATERI 2
 
 **PANDUAN MERAKIT RELAY WATER PUMP**
 1. Komponen yang dibutuhkan:
    - Relay module (Yang akan digunakan 1 channel)
      ![image](https://ecs7.tokopedia.net/img/cache/700/product-1/2017/9/30/4346518/4346518_cdeaadda-91f9-423a-a522-39363131b487_640_640.jpg)

    - Node MCU LOLIN (ESP8266)

      ![image](https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcRSC5tbxGBMb41OhqELPso3nOClE2iBtVekhQ&usqp=CAU)

    - Submersible water pump mini DC 5v

      ![image](https://muthuslogic.com/wp-content/uploads/2020/07/Mini-Submersible-Pump.jpg)

    - PCB bolong / PCB Jadi
    - Box (Opsional)
    - Kabel data usb micro (Kabel harus bisa mengirimkan data bukan hanya power)
    - Adaptor usb 5v 1-2A 
    - Kabel jumper female-female

      ![](https://s1.bukalapak.com/img/134621537/w-1000/Kabel_Jumper_Female___Female_Breadboard_Arduino_Wire_Sensor_.jpg)


 2. Langkah-langkah merakit
 
    Skema wiring : 
    ![image](https://github.com/pptik/pkl-online-iot/blob/master/Images/skema-relay.png)
      -  Lakukan pemasangan pin pada wemos
         Pada NodeMCU, pin masih terpisah dan belum terpasang pada board microcontroller, maka perlu dilakukan proses pemasangan pin pada board agar NodeMCU dapat digunakan. Proses pemasangan memerlukan solder dan juga timah. 
      -  Pemasangan wemos pada PCB
         Setelah pin terpasang pada NodeMCU, lalu setelahnya dilakukan kalibrasi pin wemos (cara kalibrasi wemos dapat dilihat pada bab perakitan soil moisture), wemos dapat langsung dipasang pada PCB. Seperti biasa, diperlukan solder dan timah untuk melakukan pemasangan wemos pada PCB. Dan pastikan timah tidak saling terhubung antar pin, karena dapat menyebabkan pin tidak berfungsi.
      -  Pemasangan relay pada PCB
         Setelah pemasangan NodeMCU selesai dilakukan, langkah selanjutnya ialah memasang relay yang akan dijadikan sebagai saklar untuk pompa bekerja (menyiram tanaman). Pemasangan relay memerlukan solatip bolak-balik agar relay dapat terpasang dengan baik pada PCB.
      -  Memasang kabel jumper
         Setelah relay terpasang, langkah selanjutnya yang perlu dilakukan ialah memasang pin header yang posisinya persis dibawah Node MCU untuk kemudian dapat dihubungkan dengan kabel jumper yang akan menghubungkan pin input pada relay, power dan ground. Sebelumnya, pin header di solder agar terhubung pada pin D1, power 3,3V dan ground. Jika kesulitan pada saat menyolder pin header menuju Node MCU,bisa gunakan kawat jumper.
      -  Hubungkan relay pada pompa
         Node MCU dan relay terpasang pada PCB, serta pin header terpasang, maka langkah selanjutnya ialah melakukan pemasangan pompa relay. Ground dari pompa dihubungkan pada ground microcontroller, sedangkan power pada pompa dihubungkan pada NO di relay. COM pada relay dihubungkan pada power 3,3V pada microcontroller.
      -  Input program
         Setelah pompa terpasang dan dipastikan terhubung dengan wemos dan relay, maka langkah selanjutnya ialah melakukan upload program pada wemos untuk kemudian melakukan uji coba apakah rangkaian yang dibuat telah sesuai dan terhubung juga pompa dapat bekerja dengan baik atau tidak. 
         Source code untuk pompa dapat diakses pada link berikut:
      






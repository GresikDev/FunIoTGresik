#Pre Requisite

OS: Linux, Windows dan Mac
Internet
software: Arduino ID
optional: - Driver Wemos


#Installation untuk Ubuntu (18.04)
Download Arduino pada halaman https://www.arduino.cc/en/Main/Software
Install arduino

#catatan tambahan jika terjadi tidak dapat upload untuk ubuntu
Pastikan wemos terkoneksi, pada kasus saya dikenali dengan /dev/ttyUSB0
Cara melihatnya dengan ls -l /dev/ttyUSB* akan menghasilkan 
	crw-rw---- 1 root dialout 188, 0 5 apr 23.01 ttyUSB0
	dimana "root" adalah sebagai owner ttyUSB0.
	ubah owner kepada user anda dengan mengetikan pada konsole terminal: "sudo usermod -a -G dialout ${USER}"
	atau jika masih belum berhasil, dapat dengan perintah: "sudo chown nama_user /dev/ttyUSB0"
	


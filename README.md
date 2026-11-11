# Proyek Sistem Monitoring Stok dan Penjualan Kantin Kampus

## Identitas Mahasiswa
* **Nama Lengkap:** Rahmi Fauzziah
* **NIM:** C2583207032
* **Kelas:** PTI3A
* **Program Studi:** Pendidikan Teknologi Informasi (PTI)
* **Mata Kuliah:** Algoritma dan Pemrograman Lanjutan
* **Dosen Pengampu:** Taofik Muhammad, M.Kom

---

## Deskripsi Singkat Proyek
Proyek ini merupakan aplikasi terminal/console berbasis bahasa pemrograman C yang dirancang untuk mengelola dan memantau ketersediaan stok barang serta memproses transaksi kasir di kantin kampus. 

Aplikasi ini mampu menyimpan data produk, memproses pembelian beberapa item sekaligus dalam satu transaksi, memperbarui stok secara otomatis, menghitung total pendapatan kantin, menentukan produk terlaris, melakukan pencarian barang, mengurutkan data produk, serta memberikan peringatan dini untuk produk dengan stok yang menipis (< 5 unit).

---

## Daftar Fitur Aplikasi
1. **Lihat Daftar Produk:** Menampilkan nomor, nama, harga, sisa stok, dan total unit terjual untuk seluruh produk.
2. **Tambah Produk Baru:** Memasukkan varian produk baru ke dalam penyimpanan sistem (maksimal 50 produk).
3. **Ubah Produk:** Memperbarui data harga dan jumlah stok untuk produk tertentu yang terdaftar.
4. **Transaksi Penjualan:** Memproses pembelian beberapa produk sekaligus dalam satu kali transaksi dengan pengecekan ketersediaan stok.
5. **Tambah Stok:** Menambahkan kuantitas stok barang yang sudah tersimpan.
6. **Cari Produk:** Mencari data produk berdasarkan kata kunci nama produk (substring search).
7. **Urutkan Produk:** Mengurutkan daftar produk berdasarkan harga termurah (Ascending) atau penjualan terbanyak (Descending).
8. **Laporan Penjualan:** Menyajikan rekapitulasi total unit terjual, total omset pendapatan kantin, serta deteksi produk paling laris secara otomatis.
9. **Cek Stok Menipis:** Menampilkan peringatan dini khusus untuk produk yang sisa stoknya kurang dari 5 unit.
0. **Keluar:** Mengakhiri jalannya program console.

---

## Penjelasan Struktur Data Array
Sesuai instruksi tugas proyek, program ini menggunakan **Array** sebagai struktur data utama tanpa database eksternal:
* `char nama_produk[50][50]`: Array karakter dua dimensi (2D) yang berfungsi menyimpan string nama produk.
* `int harga_produk[50]`: Array satu dimensi (1D) integer untuk menyimpan harga per unit setiap produk.
* `int stok_produk[50]`: Array satu dimensi (1D) integer untuk menyimpan sisa jumlah stok barang.
* `int total_terjual[50]`: Array satu dimensi (1D) integer untuk mencatat jumlah akumulasi unit yang berhasil terjual.
* `int jumlah_data`: Variabel penanda indeks untuk mengontrol jumlah data aktif dalam array hingga batas maksimal 50 item.

---

## Petunjuk Kompilasi dan Menjalankan Program

### 1. Kompilasi Kode Program
Buka terminal / Command Prompt pada lokasi direktori berkas `kantin_kampus.c`, lalu jalankan perintah kompilasi GCC:

```bash
gcc kantinkampus.c -o kantinkampus
```

### 2. Menjalankan Aplikasi
* **Sistem Operasi Windows:**
  ```bash
  kantinkampus.exe
  ```
* **Sistem Operasi Linux / macOS:**
  ```bash
  ./kantinkampus
  ```

---

## Dokumentasi dan Hasil Pengujian (Testing)

Berikut adalah tabel dokumentasi 7 skenario pengujian program yang telah dilaksanakan sesuai dengan ketentuan soal UTS:

| No. | Skenario | Input atau Tindakan | Hasil yang Diharapkan | Bukti Screenshot |
| :---: | :--- | :--- | :--- | :---: |
| 1 | **Tambah produk** | Memilih menu 2, memasukkan produk baru `Chiken Curry`, harga `25000`, stok `15` | Produk `Chiken Curry` berhasil disimpan dan muncul dalam daftar produk (Menu 1) | ![Screenshot1.png](Tampilan%20Program-UTS/Screenshot1.png) |
| 2 | **Transaksi** | Memilih menu 4, membeli `Nasi Goreng` (3 pcs), `Es Teh Manis` (3 pcs) dan `Gorengan` (1 pcs) dalam 1 transaksi | Subtotal tiap barang dan total pembayaran terhitung dengan akurat pada struk | ![Screenshot2.1.png](Tampilan%20Program-UTS/Screenshot2.1.png) |
| 3 | **Pembaruan stok** | Memeriksa data produk (Menu 1) setelah menyelesaikan transaksi pada skenario 2 | Stok `Nasi Goreng`, `Es Teh` & `Gorengan` berkurang, jumlah terjual bertambah | ![Screenshot3.png](Tampilan%20Program-UTS/Screenshot3.png) |
| 4 | **Stok tidak cukup** | Memilih menu 4, membeli `Mie Ayam` sejumlah `6` unit (melebihi stok yang ada = 3) | Transaksi ditolak dengan pesan peringatan; jumlah stok barang tetap/tidak berubah | ![Screenshot4.png](Tampilan%20Program-UTS/Screenshot4.png) |
| 5 | **Laporan** | Memilih menu 8 (Laporan Penjualan) | Total unit terjual, total pendapatan kantin, & produk terlaris dihitung dengan benar | ![Screenshot5.png](Tampilan%20Program-UTS/Screenshot5.png) |
| 6 | **Pengurutan** | Memilih menu 7, urutkan berdasarkan harga termurah dan jumlah penjualan terbanyak  | Urutan posisi produk pada daftar berubah sesuai dengan metode pengurutan yang dipilih (Jumlah penjualan terbanyak) | ![Screenshot6.png](Tampilan%20Program-UTS/Screenshot6.png) |
| 7 | **Pencarian dan stok** | Memilih menu 6 (Cari produk `Nasi Goreng`) dan menu 9 (Cek stok < 5) `Mie Ayam` | Menampilkan hasil pencarian produk `Nasi` dan `Mie Ayam` daftar peringatan barang bersisa < 5 | ![Screenshot7.1.png](Tampilan%20Program-UTS/Screenshot7.1.png) & ![Screenshot7.2.png](Tampilan%20Program-UTS/Screenshot7.2.png) |


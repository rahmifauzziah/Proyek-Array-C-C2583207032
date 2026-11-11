#include <stdio.h>
#include <string.h>

#define MAX_PRODUK 50

// (Array Utama)
char nama_produk[MAX_PRODUK][50] = {
    "Nasi Goreng",
    "Es Teh Manis",
    "Mie Ayam",
    "Gorengan",
    "Air Mineral"
};
int harga_produk[MAX_PRODUK] = {12000, 4000, 10000, 1500, 3000};
int stok_produk[MAX_PRODUK] = {15, 30, 3, 40, 25};
int total_terjual[MAX_PRODUK] = {0, 0, 0, 0, 0};
int jumlah_data = 5;

//  Fungsi
void tampilkanMenu();
void lihatDaftarProduk();
void tambahProduk();
void ubahProduk();
void transaksiPenjualan();
void tambahStok();
void cariProduk();
void urutkanProduk();
void laporanPenjualan();
void cekStokMenipis();
void bersihkanBuffer();

int main() {
    int pilihan;

    do {
        tampilkanMenu();
        printf("Pilih menu (0-9): ");
        if (scanf("%d", &pilihan) != 1) {
            printf("\n[Kesalahan] Input harus berupa angka!\n");
            bersihkanBuffer();
            continue;
        }
        bersihkanBuffer();

        switch (pilihan) {
            case 1:
                lihatDaftarProduk();
                break;
            case 2:
                tambahProduk();
                break;
            case 3:
                ubahProduk();
                break;
            case 4:
                transaksiPenjualan();
                break;
            case 5:
                tambahStok();
                break;
            case 6:
                cariProduk();
                break;
            case 7:
                urutkanProduk();
                break;
            case 8:
                laporanPenjualan();
                break;
            case 9:
                cekStokMenipis();
                break;
            case 0:
                printf("\nTerima kasih telah menggunakan program ini!\n");
                break;
            default:
                printf("\n[Kesalahan] Pilihan menu tidak tersedia!\n");
        }

        if (pilihan != 0) {
            printf("\nTekan Enter untuk melanjutkan...");
            getchar();
        }
    } while (pilihan != 0);

    return 0;
}

// Fungsi membersihkan buffer input
void bersihkanBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Menampilkan Menu Utama
void tampilkanMenu() {
    printf("\n==================================================\n");
    printf("   SISTEM MONITORING STOK & PENJUALAN KANTIN\n");
    printf("==================================================\n");
    printf("1. Lihat Daftar Produk\n");
    printf("2. Tambah Produk\n");
    printf("3. Ubah Produk\n");
    printf("4. Transaksi Penjualan\n");
    printf("5. Tambah Stok\n");
    printf("6. Cari Produk\n");
    printf("7. Urutkan Produk\n");
    printf("8. Laporan Penjualan\n");
    printf("9. Cek Stok Menipis\n");
    printf("0. Keluar\n");
    printf("--------------------------------------------------\n");
}

// Fitur 1: Melihat daftar produk
void lihatDaftarProduk() {
    printf("\n--- DAFTAR PRODUK KANTIN ---\n");
    if (jumlah_data == 0) {
        printf("Belum ada produk terdaftar.\n");
        return;
    }
    printf("%-4s | %-25s | %-12s | %-6s | %-8s\n", "No", "Nama Produk", "Harga (Rp)", "Stok", "Terjual");
    printf("----------------------------------------------------------\n");
    for (int i = 0; i < jumlah_data; i++) {
        printf("%-4d | %-25s | Rp%-10d | %-6d | %-8d\n",
               i + 1, nama_produk[i], harga_produk[i], stok_produk[i], total_terjual[i]);
    }
}

// Fitur 2: Menambah produk baru
void tambahProduk() {
    if (jumlah_data >= MAX_PRODUK) {
        printf("\n[Kesalahan] Kapasitas penyimpanan penuh (maksimal 50 produk)!\n");
        return;
    }

    printf("\n--- TAMBAH PRODUK BARU ---\n");
    printf("Masukkan nama produk: ");
    fgets(nama_produk[jumlah_data], sizeof(nama_produk[jumlah_data]), stdin);
    nama_produk[jumlah_data][strcspn(nama_produk[jumlah_data], "\n")] = 0; // Menghapus baris baru

    printf("Masukkan harga produk (Rp): ");
    if (scanf("%d", &harga_produk[jumlah_data]) != 1 || harga_produk[jumlah_data] < 0) {
        printf("[Kesalahan] Harga tidak boleh negatif atau bukan angka!\n");
        bersihkanBuffer();
        return;
    }

    printf("Masukkan stok awal: ");
    if (scanf("%d", &stok_produk[jumlah_data]) != 1 || stok_produk[jumlah_data] < 0) {
        printf("[Kesalahan] Stok tidak boleh negatif atau bukan angka!\n");
        bersihkanBuffer();
        return;
    }
    bersihkanBuffer();

    total_terjual[jumlah_data] = 0;
    jumlah_data++;
    printf("\n[Sukses] Produk baru berhasil ditambahkan!\n");
}

// Fitur 3: Mengubah harga dan stok produk
void ubahProduk() {
    lihatDaftarProduk();
    if (jumlah_data == 0) return;

    int nomor;
    printf("\nMasukkan nomor produk yang ingin diubah: ");
    if (scanf("%d", &nomor) != 1 || nomor < 1 || nomor > jumlah_data) {
        printf("[Kesalahan] Nomor produk tidak valid!\n");
        bersihkanBuffer();
        return;
    }
    bersihkanBuffer();

    int idx = nomor - 1;
    printf("Mengubah produk: %s\n", nama_produk[idx]);

    printf("Masukkan harga baru (Rp): ");
    if (scanf("%d", &harga_produk[idx]) != 1 || harga_produk[idx] < 0) {
        printf("[Kesalahan] Harga baru tidak boleh negatif!\n");
        bersihkanBuffer();
        return;
    }

    printf("Masukkan stok baru: ");
    if (scanf("%d", &stok_produk[idx]) != 1 || stok_produk[idx] < 0) {
        printf("[Kesalahan] Stok baru tidak boleh negatif!\n");
        bersihkanBuffer();
        return;
    }
    bersihkanBuffer();

    printf("\n[Sukses] Data produk berhasil diperbarui!\n");
}

// Fitur 4: Transaksi penjualan beberapa produk
void transaksiPenjualan() {
    char lanjut;
    int total_transaksi = 0;
    int keranjang_idx[MAX_PRODUK];
    int keranjang_qty[MAX_PRODUK];
    int item_count = 0;

    printf("\n--- TRANSAKSI PENJUALAN KANTIN ---\n");
    do {
        lihatDaftarProduk();
        int nomor, qty;

        printf("\nMasukkan nomor produk yang dibeli: ");
        if (scanf("%d", &nomor) != 1 || nomor < 1 || nomor > jumlah_data) {
            printf("[Kesalahan] Nomor produk tidak valid!\n");
            bersihkanBuffer();
            goto tanya_lanjut;
        }

        printf("Masukkan jumlah pembelian: ");
        if (scanf("%d", &qty) != 1 || qty <= 0) {
            printf("[Kesalahan] Jumlah pembelian harus bernilai positif (> 0)!\n");
            bersihkanBuffer();
            goto tanya_lanjut;
        }
        bersihkanBuffer();

        int idx = nomor - 1;

        if (qty > stok_produk[idx]) {
            printf("[Kesalahan] Transaksi ditolak! Stok untuk '%s' tidak cukup. (Sisa stok: %d)\n", nama_produk[idx], stok_produk[idx]);
        } else {
            keranjang_idx[item_count] = idx;
            keranjang_qty[item_count] = qty;
            item_count++;
            printf("[Info] %s sebanyak %d dimasukkan ke keranjang.\n", nama_produk[idx], qty);
        }

    tanya_lanjut:
        printf("Ingin tambah produk lain dalam transaksi ini? (y/t): ");
        scanf(" %c", &lanjut);
        bersihkanBuffer();
    } while (lanjut == 'y' || lanjut == 'Y');

    if (item_count > 0) {
        printf("\n==================================================\n");
        printf("                 STRUK PEMBELIAN                  \n");
        printf("==================================================\n");
        printf("%-20s | %-5s | %-10s | %-10s\n", "Nama Produk", "Qty", "Harga", "Subtotal");
        printf("--------------------------------------------------\n");

        for (int i = 0; i < item_count; i++) {
            int idx = keranjang_idx[i];
            int qty = keranjang_qty[i];
            int subtotal = harga_produk[idx] * qty;
            total_transaksi += subtotal;

            stok_produk[idx] -= qty;
            total_terjual[idx] += qty;

            printf("%-20s | %-5d | Rp%-8d | Rp%-8d\n", nama_produk[idx], qty, harga_produk[idx], subtotal);
        }

        printf("--------------------------------------------------\n");
        printf("TOTAL PEMBAYARAN: Rp%d\n", total_transaksi);
        printf("==================================================\n");
        printf("[Sukses] Transaksi berhasil diproses dan stok diperbarui!\n");
    } else {
        printf("\n[Info] Tidak ada produk yang diproses.\n");
    }
}

// Fitur 5: Menambah stok produk
void tambahStok() {
    lihatDaftarProduk();
    if (jumlah_data == 0) return;

    int nomor, tambahan;
    printf("\nMasukkan nomor produk yang ingin ditambah stoknya: ");
    if (scanf("%d", &nomor) != 1 || nomor < 1 || nomor > jumlah_data) {
        printf("[Kesalahan] Nomor produk tidak valid!\n");
        bersihkanBuffer();
        return;
    }

    printf("Masukkan jumlah tambahan stok: ");
    if (scanf("%d", &tambahan) != 1 || tambahan <= 0) {
        printf("[Kesalahan] Jumlah tambahan harus positif (> 0)!\n");
        bersihkanBuffer();
        return;
    }
    bersihkanBuffer();

    int idx = nomor - 1;
    stok_produk[idx] += tambahan;
    printf("\n[Sukses] Stok berhasil ditambah. Stok terbaru '%s' adalah %d.\n", nama_produk[idx], stok_produk[idx]);
}

// Fitur 6: Mencari produk berdasarkan nama
void cariProduk() {
    char keyword[50];
    printf("\n--- PENCARIAN PRODUK ---\n");
    printf("Masukkan nama produk yang dicari: ");
    fgets(keyword, sizeof(keyword), stdin);
    keyword[strcspn(keyword, "\n")] = 0;

    int ditemukan = 0;
    printf("\nHasil Pencarian:\n");
    printf("%-4s | %-25s | %-12s | %-6s\n", "No", "Nama Produk", "Harga (Rp)", "Stok");
    printf("----------------------------------------------------\n");
    for (int i = 0; i < jumlah_data; i++) {
        if (strstr(nama_produk[i], keyword) != NULL) {
            printf("%-4d | %-25s | Rp%-10d | %-6d\n", i + 1, nama_produk[i], harga_produk[i], stok_produk[i]);
            ditemukan++;
        }
    }

    if (ditemukan == 0) {
        printf("Produk dengan kata kunci '%s' tidak ditemukan.\n", keyword);
    }
}

// Fitur 7: Mengurutkan produk
void urutkanProduk() {
    if (jumlah_data <= 1) {
        printf("\n[Info] Data terlalu sedikit untuk diurutkan.\n");
        return;
    }

    int pilihan_urut;
    printf("\n--- PENGURUTAN PRODUK ---\n");
    printf("1. Berdasarkan Harga (Termurah ke Termahal)\n");
    printf("2. Berdasarkan Jumlah Terjual (Terbanyak ke Tersedikit)\n");
    printf("Pilihan (1-2): ");
    if (scanf("%d", &pilihan_urut) != 1) {
        printf("[Kesalahan] Pilihan tidak valid!\n");
        bersihkanBuffer();
        return;
    }
    bersihkanBuffer();

    // Bubble Sort
    for (int i = 0; i < jumlah_data - 1; i++) {
        for (int j = 0; j < jumlah_data - i - 1; j++) {
            int tukar = 0;
            if (pilihan_urut == 1) {
                if (harga_produk[j] > harga_produk[j + 1]) tukar = 1;
            } else if (pilihan_urut == 2) {
                if (total_terjual[j] < total_terjual[j + 1]) tukar = 1;
            }

            if (tukar) {
                char temp_nama[50];
                strcpy(temp_nama, nama_produk[j]);
                strcpy(nama_produk[j], nama_produk[j + 1]);
                strcpy(nama_produk[j + 1], temp_nama);

                int temp_harga = harga_produk[j];
                harga_produk[j] = harga_produk[j + 1];
                harga_produk[j + 1] = temp_harga;

                int temp_stok = stok_produk[j];
                stok_produk[j] = stok_produk[j + 1];
                stok_produk[j + 1] = temp_stok;

                int temp_terjual = total_terjual[j];
                total_terjual[j] = total_terjual[j + 1];
                total_terjual[j + 1] = temp_terjual;
            }
        }
    }

    printf("\n[Sukses] Produk berhasil diurutkan!\n");
    lihatDaftarProduk();
}

// Fitur 8: Laporan penjualan
void laporanPenjualan() {
    printf("\n==================================================\n");
    printf("                LAPORAN PENJUALAN                 \n");
    printf("==================================================\n");
    if (jumlah_data == 0) {
        printf("Belum ada data produk.\n");
        return;
    }

    int total_unit_seluruh = 0;
    int total_pendapatan_seluruh = 0;
    int max_terjual = -1;
    int idx_terlaris = -1;

    printf("%-25s | %-8s | %-12s\n", "Nama Produk", "Terjual", "Pendapatan");
    printf("--------------------------------------------------\n");

    for (int i = 0; i < jumlah_data; i++) {
        int pendapatan_produk = harga_produk[i] * total_terjual[i];
        total_unit_seluruh += total_terjual[i];
        total_pendapatan_seluruh += pendapatan_produk;

        printf("%-25s | %-8d | Rp%-10d\n", nama_produk[i], total_terjual[i], pendapatan_produk);

        if (total_terjual[i] > max_terjual) {
            max_terjual = total_terjual[i];
            idx_terlaris = i;
        }
    }

    printf("--------------------------------------------------\n");
    printf("Total Unit Seluruh Terjual : %d unit\n", total_unit_seluruh);
    printf("Total Pendapatan Kantin    : Rp%d\n", total_pendapatan_seluruh);

    if (max_terjual > 0) {
        printf("Produk Paling Terlaris     : %s (%d unit terjual)\n", nama_produk[idx_terlaris], max_terjual);
    } else {
        printf("Produk Paling Terlaris     : Belum ada yang terjual\n");
    }
    printf("==================================================\n");
}

// Fitur 9: Cek stok menipis (< 5)
void cekStokMenipis() {
    printf("\n--- PERINGATAN STOK MENIPIS (< 5) ---\n");
    int count = 0;
    printf("%-4s | %-25s | %-6s\n", "No", "Nama Produk", "Stok");
    printf("--------------------------------------------\n");

    for (int i = 0; i < jumlah_data; i++) {
        if (stok_produk[i] < 5) {
            printf("%-4d | %-25s | %-6d (PERINGATAN! Stok menipis)\n", i + 1, nama_produk[i], stok_produk[i]);
            count++;
        }
    }

    if (count == 0) {
        printf("Aman! Tidak ada produk dengan stok di bawah 5.\n");
    } else {
        printf("\nTotal produk dengan stok menipis: %d\n", count);
    }
}

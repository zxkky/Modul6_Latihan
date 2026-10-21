# Modul 6: Doubly Linked List (Bagian Pertama) - 6.2 Latihan

Implementasi ADT Doubly Linked List dalam C++ untuk praktikum Struktur Data, **Modul 6 (Doubly Linked List Bagian Pertama) - Subbab 6.2 Latihan**.

---

## Daftar File

| File | Deskripsi |
|---|---|
| `doublylist.h` | Header file yang berisi pendefinisian tipe bentukan (`infotype` kendaraan, `address`, `ElmList`, `List`) dan prototype seluruh fungsi/prosedur. |
| `doublylist.cpp` | Implementasi dari seluruh fungsi dan prosedur ADT Doubly Linked List. |
| `main.cpp` | Program utama (*driver*) untuk menjalankan dan menguji seluruh latihan (Soal No. 1, 2, dan 3). |
| `boolean.h` | Header pendukung tipe `boolean` untuk kompabilitas praktikum Struktur Data. |

---

## Rincian Pengerjaan Soal 6.2 Latihan

### Soal No. 1: Pembentukan ADT Doubly Linked List & Kasus Kendaraan

1. **Definisi Tipe Data**:
   - `infotype` (`kendaraan`): record yang memiliki field `nopol` (`string`), `warna` (`string`), dan `thnBuat` (`int`).
   - `address`: pointer ke elemen list (`ElmList*`).
   - `ElmList`: elemen bertipe struct dengan field `info` (`infotype`), `next` (`address`), dan `prev` (`address`).
   - `List`: pointer ke elemen pertama (`First`) dan terakhir (`Last`).

2. **Primitif yang Dibuat**:
   - `void createList(List &L)`: Menginisialisasi list kosong (`L.First = Nil`, `L.Last = Nil`).
   - `address alokasi(infotype x)`: Mengalokasikan memori node baru dan mengisinya dengan info `x`.
   - `void dealokasi(address &P)`: Membebaskan memori node `P` dan mengeset pointer menjadi `Nil`.
   - `void insertLast(List &L, address P)`: Menyisipkan elemen di akhir list.
   - `void printInfo(List L)`: Menampilkan data kendaraan dari elemen `Last` mundur ke `First` sesuai contoh output Gambar 6-23.

3. **Pencegahan Duplikasi Nomor Polisi**:
   Sebelum melakukan `insertLast`, program memeriksa apakah nomor polisi sudah ada menggunakan fungsi `findElm`. Jika sudah terdaftar, program mencetak `"nomor polisi sudah terdaftar"` dan membatalkan penyisipan.

---

### Soal No. 2: Pencarian Elemen Berdasarkan Nomor Polisi

- **Prototype**: `address findElm(List L, infotype x);`
- **Cara Kerja**: Menelusuri list dari `L.First` ke `L.Last`. Jika `P->info.nopol == x.nopol`, fungsi mengembalikan pointer `P`. Jika tidak ditemukan, mengembalikan `Nil`.
- **Output Gambar 6-24**:
  ```text
  Nomor Polisi : D001
  Warna        : hitam
  Tahun        : 90
  ```

---

### Soal No. 3: Penghapusan Elemen (Delete)

- **Prosedur yang Dibuat**:
  - `void deleteFirst(List &L, address &P)`: Menghapus elemen pertama list.
  - `void deleteLast(List &L, address &P)`: Menghapus elemen terakhir list.
  - `void deleteAfter(address Prec, address &P)`: Menghapus elemen setelah elemen `Prec`.
- **Penerapan**:
  Mencari elemen yang ingin dihapus (misal `D003`). Jika elemen berada di awal, gunakan `deleteFirst`. Jika di akhir, gunakan `deleteLast`. Jika di tengah, gunakan `deleteAfter(found->prev, P)`. Setelah terhapus dari list, panggil `dealokasi(P)` untuk membebaskan memori.
- **Output Gambar 6-25**:
  ```text
  Data dengan nomor polisi D003 berhasil dihapus.

  DATA LIST 1

  no polisi : D004
  warna     : kuning
  tahun     : 90
  no polisi : D001
  warna     : hitam
  tahun     : 90
  ```

---

## Cara Kompilasi dan Menjalankan

### Melalui Terminal / Command Line (g++)

```bash
cd cpp/pertemuan6
g++ main.cpp doublylist.cpp -o main.exe
./main.exe
```

### Melalui Code::Blocks IDE

1. Buka Code::Blocks.
2. Buat project Console Application C++.
3. Tambahkan `doublylist.h`, `doublylist.cpp`, dan `main.cpp`.
4. Tekan **F9** (*Build and Run*).

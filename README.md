# Öğrenci ve Ders Kayıt Otomasyonu

Bu proje, C programlama dili kullanılarak geliştirilmiş, dosya tabanlı bir **Üniversite Kayıt Yönetim Sistemi**dir. Öğrenci bilgilerini, ders içeriklerini ve kayıt eşleşmelerini kalıcı olarak `.txt` dosyalarında saklar.

---

## Özellikler

Sistem üç ana modül üzerine inşa edilmiştir:

### 1. Öğrenci Yönetimi
* **Kayıt Ekleme:** Öğrenci adı, soyadı ve numarasını alır.
* **Arama:** İsim bazlı sorgulama yapar.
* **Listeleme:** Tüm kayıtlı öğrencileri numaralarıyla gösterir.
* **Silme:** Dosya yedekleme yöntemiyle güvenli veri silme işlemi gerçekleştirir.

### 2. Ders Yönetimi
* **Ders Tanımlama:** Ders adı, kodu ve AKTS verilerini saklar.
* **Sorgulama:** Ders kodu üzerinden hızlı erişim sağlar.
* **Ders Silme:** Müfredattan ders çıkarılmasını sağlar.

### 3. Ders Kayıt Sistemi
* Seçilen öğrenci ile mevcut dersleri eşleştirir.
* Kayıt verilerini `KayitDosyasi.txt` içerisinde yapılandırır.

---

## Teknik Mimari

Proje, yapısal programlama prensiplerine uygun olarak `struct` yapıları ve pointer işlemleri içermektedir.



### Kullanılan Yapılar (Structs)
* `struct ogrenciKayit`: Kimlik bilgilerini tutar.
* `struct dersler`: Akademik ders detaylarını tutar.
* `struct dersKayit`: Başarı notu ve kayıt durumunu yönetir.

---

## Kullanım Talimatları

### Gereksinimler
* Standart bir C derleyicisi (GCC, Clang, MSVC).
* Windows İşletim Sistemi (Konsol renklendirme ve ekran temizleme komutları için).

### Derleme ve Çalıştırma
1. Terminali açın.
2. Aşağıdaki komutu çalıştırın:
   ```bash
   gcc projem.c -o otomasyon

# s21_matrix+

s21_matrix_oop.h. kutubxonasini amalga oshirish 

💡 **Ushbu loyiha haqida biz bilan fikr-mulohazalaringizni baham ko’rish uchun [bu yerni bosing](https://new.oprosso.net/p/4cb31ec3f47a4596bc758ea1861fb624).** Bu anonim bo’lib, jamoamizga ta’limni yaxshilashga yordam beradi. Loyihani tugatgandan so'ng darhol so'rovnomani to'ldirishni tavsiya qilamiz.

## Contents

1. [Chapter I](#chapter-i) \
    1.1. [Introduction](#introduction)
2. [Chapter II](#chapter-ii) \
    2.1. [Information](#information)
3. [Chapter III](#chapter-iii) \
    3.1. [Part 1](#part-1-s21_matrix_ooph-kutubxona-funksiyasini-amalga-oshirish)


## Chapter I

![s21_matrix](misc/images/s21_matrix.png)

Yer sayyorasi, 2000-yil 20-sentabr.

*--  Biroq, bizning SEO ajoyib shahar tashqarisidagi uyga ega, g'oyalarni hayotga tatbiq etish uchun hamma narsa bor! Maysazordagi ulkan basseyn va unga qaragan ayvon ishtiyoqli va aqlli inson qiyofasini yanada to'ldiradi.*

*- Ha, fikringga qo’shilaman, bizni bu yerga taklif qilishganidan juda xursandman! To'g'ri, tan olishim kerak, bu menga qandaydir dejavyu hissini beradi, go'yo men bu yerda avval ham bo'lgandekman.*

*-- Ha, bu g'alati. Ishoning, butun mamlakat bo'ylab xuddi shunday ikkinchi uyni topa olmaysiz! Ha, nima haqida gapirayotgan edik? O, ha! Bir necha kundirki, ushbu go'zal joyda, id Software kompaniyasining asosiy texnik jamoasi biz ishlab chiqayotgan Doom 3 o'yinimizda taqdim etmoqchi bo'lgan yangi texnologiyani muhokama qilmoqda. Fotosuratda eng ko'p reallik tuyg'usini nima yaratadi? Tabiiyki, yorug'lik va soyalar o'yini markaziy protsessorni og'ir yuklab, hozir juda uzoq vaqt hisoblanmoqda. Jon o'zining texnologik va algoritmik g'oyalari va tryuklari bilan mashhur bo'lib, ular kodning tez ishlashi va optimallashtirishda juda zo’r yutuqlarga erishishga imkon berdi.*

*- Ha, menimcha, men bu haqda allaqachon eshitganman.*

*-- O, rostdanmi? Menimcha, Katarina mendan biroz oldinga o’tib ketibdi. \
Shunga qaramay, eng qiziqarli qismga o'tamiz. Bizning bosh texnik mutaxassisimiz va kompaniya asoschisi Jon Karmak chuqurlik buferi va trafaret buferi yordamida butun grafik konveyerdan o'tgandan so'ng sahnaga soyalarni qo'llash imkonini beradigan nazariy ishni taqdim etdi.*

*- O, bu haqiqatan ham... qiziq tuyulyapti.*

*-- Sizni ushbu ziyofatga tasodifan taklif qilganimiz yo'q. Butun jamoa sahnada soyalarni yaratishning yangi usuli ustida ishlamoqda va ayniqsa sizning bo'lim Jon tomonidan barcha turdagi matritsalarning eng tez va optimallashtirilgan kutubxonasini joriy qilish uchun tayinlangan. Algoritmning butun matematik mantig'i quriladigan transformatsiyalar: vektorlar va matritsalar, transpozitsiya va SRT transformatsiyasi, shuningdek, kompyuter grafikasida qo'llaniladigan boshqa ko'plab matematik obyektlar va operatsiyalar. Yangi usulga to'g'ri va qasddan o'tish uchun ishlashda sezilarli va ta'sirchan o'zgarishlar talab qilinadi, buning uchun siz shaxsan javobgar bo'lasiz! Shuni ta'kidlash kerakki, barcha ishlar maksimal kod sifatiga erishish uchun zamonaviy OOP uslubida amalga oshiriladi!*

*- Nima ham derdim… mmm… sizga yordam berishdan xursandman.*

*-- Ajoyib! Kim biladi, balki...*

## Introduction

Ushbu loyihada siz yana **s21_matrix** loyihasi bo’yicha o’zingizga tanish bo'lgan matritsalar bilan ishlash kutubxonasini, bu safar obyektga yo'naltirilgan yondashuvdan foydalangan holda (materiallarga qarang) amalga oshirasiz. Obyektga yo'naltirilgan yondashuv matritsalar bilan ishlash uchun kutubxonani alohida sinf sifatida amalga oshirishga imkon beradi, ularning obyektlari ustida ham usul, ham standart operatorlar +, -, * va boshqalar bilan ifodalangan operatsiyalar aniqlangan.

## Chapter II

## Information

### C++ и C

C++ – bu obyektga yo'naltirilgan yondashuvdan foydalangan holda dasturlarni amalga oshirish uchun C tili asosida ishlab chiqilgan dasturlash tili. Bu shuni anglatadiki, C++ tilining umumiy sintaksisi qoidalari bevosita C tilidan meros bo'lib o'tgan va shuning uchun C tilida yozilgan ko'pchilik kodlarni C++ dasturi matniga ko'chirish va muvaffaqiyatli kompilyatsiya qilish mumkin. Ko'pincha, C++ biror narsani olib qo'yishdan ko'ra, dasturchi uchun faqat yangi xususiyatlarni qo'shadi yoki ularni biroz o'zgartiradi, shuning uchun C ++ haqida gapirganda, o'xshashliklar haqida emas, balki farqlar haqida gapirish osonroq (materiallarga qarang).

### C++ da matritsa sinfiga misol

```cpp
class S21Matrix {
    private:
        // Attributes
        int rows_, cols_;         // Rows and columns
        double **matrix_;         // Pointer to the memory where the matrix is allocated

    public:
        S21Matrix();              // Default constructor
        ~S21Matrix();             // Destructor

        void SumMatrix(const S21Matrix& other); 
        // Other methods..
}
```

### Matritsa to’g’risida asosiy qoidalarni eslatish

Matritsa – bu m satr va n t a ustunda joylashtirilgan sonlarning to'rtburchak jadvali:

```
    1 2 3
A = 4 5 6
    7 8 9
```

```
     1  2  3  4
В =  5  6  7  8
     9 10 11 12
```

Kerakli elementni indekslar yordamida olishingiz mumkin, masalan:
A[1,1] = 1, bunda birinchi indeks – satr raqami, ikkinchisi – ustun raqami.

Matritsa tartibi – bu uning satrlari yoki ustunlari soni. \
Kvadrat matritsaning asosiy diagonali yuqori chapdan pastki o'ng burchakka o'tadigan diagonaldir. \
To'rtburchak matritsa (B) – qatorlar soni ustunlar soniga teng bo'lmagan matritsadir. \
Kvadrat matritsa (A) qatorlar soni ustunlar soniga teng bo'lgan matritsadir.

### Matritsalar ustida amallar

uyida ishlab chiqilayotgan kutubxonada amalga oshirilishi kerak bo'lgan matritsalar bo'yicha operatsiyalarning qisqacha tavsifi keltirilgan. Ular avval “Strukturaviy Dasturlash” blokida bajargan operatsiyalaringizga o'xshaydi va ularning har birining batafsil tavsifini u yerda ko’rish mumkin. E'tibor bering, ba'zi operatsiyalarda istisno mexanizmidan foydalangan holda maxsus ishlov berishni talab qiladigan istisnoviy holatlar mavjud.

| Amaliyot    | Tavsif   | stisnoviy holatlar |
| ----------- | ----------- | ----------- |
| `bool EqMatrix (const S21Matrix& other)`	| Matritsalarni o’zaro tengligini tekshiradi. | |
| `void SumMatrix (const S21Matrix& other)` | Joriy matritsaga ikkinchi matritsani qo'shadi | matritsalarning turli o'lchamlari. |
| `void SubMatrix(const  S21Matrix& other)` | Joriy matritsadan boshqa matritsani ayiradi | matritsalarning turli o'lchamlari. |
| `void MulNumber(const  double num)` | Joriy matritsani songa ko'paytiradi. | |
| `void MulMatrix (const S21Matrix& other)` | Joriy matritsani ikkinchisiga ko'paytiradi. | birinchi matritsaning ustunlari soni ikkinchi matritsaning qatorlari soniga teng emas. |
| `S21 Matrix Transpose()`	| Joriydan yangi transpozitsiyalangan matritsa yaratadi va uni qaytaradi. | |
| `S21Matrix CalcComplements()` | Joriy matritsaning algebraik to'ldiruvchi matritsasini hisoblaydi va uni qaytaradi. | Matritsa kvadrat hisoblanmaydi. |
| `double  Determinant()` |Joriy matritsaning aniqlovchisini hisoblaydi va qaytaradi.| Matritsa kvadrat hisoblanmaydi. |
| `S21 Matrix InverseMatrix()` |Teskari matritsani hisoblaydi va qaytaradi.| Matritsaning aniqlovchisi 0 ga teng. |

Ushbu operatsiyalarni amalga oshirishdan tashqari, konstruktorlar va destruktorlarni ham amalga oshirish kerak:

| Usul    | Tavsif   |
| ----------- | ----------- |
| `S21Matrix()` | Oldindan belgilangan o'lchamli matritsani ishga tushiradigan asosiy konstruktor. |  
| `S21Matrix(int rows, int cols)` | Qator va ustunlar soni bilan parametrlangan konstruktor. | 
| `S21Matrix(const S21Matrix& other)` | Nusxalash konstruktori. |
| `S21Matrix(S21Matrix&& other)` | Ko’chirish konstruktori.|
| `~S21Matrix()` | Destruktor. |

Shuningdek, yuqoridagi operatsiyalarga qisman mos keladigan quyidagi operatorlarni qayta yuklashingiz kerak:

| Operator    | Tavsif   | Istisnoviy holatlar |
| ----------- | ----------- | ----------- |
| `+` | Ikki matritsani qo'shish. | Matritsalarning turli o'lchamlari. |
| `-` | Bir matritsani boshqasidan ayirish. | Matritsalarning turli o'lchamlari. |
| `*` | Matritsalarni ko'paytirish va matritsani songa ko'paytirish.| Birinchi matritsaning ustunlari soni ikkinchi matritsaning qatorlari soniga teng emas. |
| `==` | Matritsalar tengligini tekshirish (EqMatrix). | |
| `=` | Matritsaga boshqa matritsaning qiymatlarini o’zlashtirish. | |
| `+=` | Qo'shishni o’zlashtirish (SumMatrix).|Matritsalarning turli o'lchamlari. |
| `-=` | Ayirmani o’zlashtirish (SubMatrix).|Matritsalarning turli o'lchamlari. |
| `*=` | Ko'paytirishni o’zlashtirish (MulMatrix/MulNumber). | Birinchi matritsaning ustunlari soni ikkinchi matritsaning qatorlari soniga teng emas. |
| `(int i, int j)` | Matritsa elementlari bo‘yicha indekslash (satr, ustun). | Matritsa chegarasidan tashqaridagi indeks. |

## Chapter III

## Part 1. s21_matrix_oop.h kutubxona funksiyasini amalga oshirish

- Dastur C++17standartining C++ tilida gcc kompilyatoridan foydalangan holda ishlab chiqilishi kerak.
- Dastur kodi src papkasida joylashgan bo'lishi kerak.
- Kod yozishda Google Style ga amal qilinishi kerak.
- Matritsani `S21Matrix` sinfi sifatida amalga oshiring
- Faqat `matrix_`, `rows_` va `cols_` shaxsiy maydonlarini saqlang.
- accessor va mutator orqali `rows_ `va `cols_` shaxsiy maydonlariga kirishni amalga oshiring. Hajmi kattalashganda, matritsa nol elementlar bilan to'ldiriladi, kichiklashganida esa ortiqchalari shunchaki tashlab yuboriladi.
- Yechimni statik kutubxona sifatida loyihalang (s21\_matrix\_oop.h sarlavhali fayl bilan).
- [Yuqorida](#matritsalar-ustida-amallar) tavsiflangan amallarni bajaring.
- [Yuqoridagi](#matritsalar-ustida-amallar) bo'limdagi jadvalga muvofiq operatorlarni qayta yuklang.
- GTest kutubxonasidan foydalanib, kutubxona funksiyalarining to'liq unit-testlar bilan qoplanishini tayyorlang.
- Kutubxona va testlarni to’plash uchun Makefile faylini nazarda tuting (all, clean, test, s21_matrix_oop.a maqsadlari bilan).
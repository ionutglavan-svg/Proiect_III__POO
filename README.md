# Gestiunea Florăriei – Arhitectură și Implementare POO

## Prezentare Generală
Acest proiect oferă o soluție software complexă pentru gestionarea unei florării, fiind creat pentru a ilustra aplicarea riguroasă a principiilor **Programării Orientate pe Obiecte** într-un sistem de management al inventarului și vânzărilor. Scopul principal a fost crearea unei aplicații robuste care să poată gestiona o varietate de produse florale și accesorii, în timp ce procesează comenzi și livrări. Structura a fost concepută pentru a respecta principiile fundamentale ale POO, asigurând separarea clară a responsabilităților și o extensibilitate crescută, prin utilizarea modelelor de design moderne și a programării generice.

---

## Arhitectura Sistemului

### Ierarhia de Clase și Gestiunea Resurselor
La baza sistemului se află clasa abstractă `Produs`, care funcționează ca un contract esențial pentru orice articol aflat la vânzare. Aceasta include logica de bază pentru stocuri și perisabilitate, folosind metode virtuale pure pentru a crea o structură unitară pentru clasele derivate.

Ierarhia este împărțită în două categorii principale:
* **Produse Simple:** Clasele `Fir` și `Ghiveci`, care se ocupă de atribute de bază (culoare, material).
* **Produse Complexe:** Clasele `Ornament` și `Buchet`, care folosesc compoziția și containere de tip `std::vector` pentru a gestiona structuri florale complexe.

> **Notă tehnică:** Folosim pointeri inteligenți `std::unique_ptr` pentru a asigura un management sigur al memoriei și pentru a evita scurgerile de memorie.

---

## Design Patterns Implementate

### 1. Factory Method (`ProdusFactory`)
Sistemul adoptă modelul de proiectare **Factory**, care centralizează procesul de instanțiere. Clasa `ProdusFactory` elimină nevoie ca logica de business să fie familiarizată cu detalii ale constructorilor specifici. Prin metodele statice `creeazaSimplu` și `creeazaComplex`, Factory-ul determină, în momentul execuției, tipul de obiect ce trebuie generat.

### 2. Strategy Pattern (`StrategiePret`)
Logica de calcul a prețurilor este delegată unei interfețe numită `StrategiePret`. Acest model permitem asocierea dinamică a diferitelor strategii (de exemplu, `StrategiePerisabil`, `StrategieStandard`) în timpul execuției. Astfel, comportamentul financiar al unui produs poate fi ajustat fără a modifica structura clasei de bază, respectând principiul **Open-Closed**.

---

## Programare Generică și Logare
Un aspect avansat al proiectului este template-ul `Gestiune<T>`. Această clasă generică urmărește și loghează evenimentele din sistem. 
* **Funcții Prietene Template:** Am implementat `afiseazaInfoGestiune` și `afiseazaElementeLog` ca funcții `friend` în interiorul template-ului, pentru a permite accesul la datele private, păstrând în același timp o încapsulare strictă.

---

## Tratarea Erorilor și Integritatea Datelor
Sistemul este protejat printr-o ierarhie de excepții definită în modulele `Eroare`, inclusiv:
* `StocInsuficientException` – care apare când se depășește inventarul.
* `InputInvalidException` – pentru a gestiona datele eronate introduse de utilizator.

Pentru a menține integritatea datelor, funcția prietenă `strgLivrareComanda` asigură sincronizarea bazei de date prin eliminarea simultană a înregistrărilor corelate din vectorii de comenzi și livrări.

---

## Bibliografie și Resurse Consultate 
În timp ce am documentat implementarea conceptelor avansate, am utilizat următoarele surse: 
* **Design Patterns in C++ (Factory & Strategy):** Tutorial video despre conceptele de bază ale modelelor de proiectare: (https://youtu.be/usmdZniV_Yw) 
* **C++ Programming Course:** Playlist dedicat conceptelor avansate de POO, Smart Pointers și Programare Generică: (https://youtu.be/blDsmrsyOME?list=PLk6CEY9XxSIDZhQURp6d8Sgp-A0yKKDKV)
* **Materiale de Curs POO:** Note academice despre virtualizarea non-intuitivă, funcțiile prietene și managementul ierarhiilor complexe.

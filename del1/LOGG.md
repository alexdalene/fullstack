# Logg

For å komme meg inn i riktig "mindset", ettersom jeg har vært borte fra utvikler-verden en liten stund, så starter jeg med grunnlaget. Harvard University sitt [CS50x](https://cs50.harvard.edu/x/) kurs, gratis og offentlig, er perfekt for dette. Det er en introduksjon til datavitenskap, som fokuserer på å lære problemløsning, både med og uten kode.

> Kurset går gjennom: computational thinking, abstraction, algorithms, data structures og generell datavitenskap.

## C

Det som er tøft så langt, er at man starter med å lære seg å kode i C, hvilket gir mening om man tenker på det, ettersom det er det underliggende språket i nesten alle språk vi bruker i utvikling (abstraksjon). Allerede så har det hjulpet meg med å forstå konseptet bak TypeScript bedre. La meg gi et eksempel:

```C
void meow(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow\n");
    }
}
```

Se på selve `meow()` funksjonen; ved å si `void` først, så sier vi at denne funksjonen har ingen returverdi. Vi sier derimot innenfor parentesen at denne funksjonen tar et input, som er av type `int`, som nesten er likt TypeScript sin `number`, bortsett fra at `number` er en catch-all for både heltall og desimaltall, mens `int` bare funker for heltall, ellers kuttes desimalene, hvilket kalles **truncation**.

```TS
export default function meow(n: number): void {
    for (let i = 0; i < n; i++) {
        console.log("meow");
    }
}
```

### 16. november 2026

Nå har jeg fullført alle oppgaver fra [Problem Set 1](https://cs50.harvard.edu/x/psets/1/) (_more comfortable_ versjoner). Det er gøy å sette seg inn i slike problemstillinger igjen, og spesielt belønnende å løse de. Den siste oppgaven var definitivt vanskeligst, og tok meg en god stund å løse. Den het [Credit](https://cs50.harvard.edu/x/psets/1/credit/), og gikk ut på skrive kode som finner ut om et kredittkort (eller bankkort) er ekte, og hvem det er fra (leverandør).

Alle kort kan bli identifisert fra de 1-2 første tallene hvem de er fra (4 er VISA f.eks), og samtidig har kortene et **checksum**, som er en matematisk relasjon mellom tallene. Det er sånn at vi kan sjekke om kortene er ekte eller ikke, uten å måtte be om informasjon fra en database (skjer uansett når mer sikkerhet kreves).

Hans Peter Luhn fra IBM lagde en algoritme som finner ut av akkurat dette, og den kalles **Luhn's algorithm**:

1. Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
2. Add the sum to the sum of the digits that weren’t multiplied by 2.
3. If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!

Du kan se min versjon av dette, skrevet i C, uten arrays (ettersom vi "ikke har lært det enda"), og uten hjelp av KI (med et unntak om å bli forklart hvordan modulo (remainder) fungerer), i `del1/cs50/credit/credit.c`.

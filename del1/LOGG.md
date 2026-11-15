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

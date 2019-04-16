# Systemy Operacyjne - Projekt 2
## OCENA 4.0
1. Etap polega na utworzeniu kompletnej aplikacji wielowątkowej ukazującej i rozwiązującej problem ucztujących filozofów.
2. Aplikacja nie musi być rozszerzeniem aplikacji z etapu poprzedniego – można ją napisać od podstaw.
3. Tak jak w etapie poprzednim należy w sposób poprawny tworzyć i zamykać wątki (tym razem zamykanie po wciśnięciu danego klawisza, inaczej aplikacja ma działać bez końca) oraz symulować życie filozofa (tym razem używając wizualizacji bazującej na ncurses).
4. Należy rozwiązać problem synchronizacji (dostępu) do zasobów współdzielonych (sztućców), by nie dochodziło do niespójności (np. dwóch filozofów używających jednocześnie tego samego sztućca).
5. Rozwiązywać problem zagłodzenia.
6. Rozwiązywać problem zakleszczenia (deadlock, być może też livelock).
7. W programie należy wykorzystać mutexy i, w miarę możliwości, zmienne warunkowe.
8. Warunkiem koniecznym otrzymania oceny 5.0 z tego etapu jest poprawne wykorzystanie zmiennych warunkowych i rozwiązanie problemu zakleszczenia.

## Kompilacja
```
make compile
```
## Uruchmienie
``` 
./a.out 5 (5 to liczba watkow/filozofow) 
```

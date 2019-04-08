# Systemy Operacyjne - Projekt 1

## OCENA 4.25

1. Etap polega na utworzeniu pierwszej części aplikacji wielowątkowej ukazującej problem ucztujących filozofów.
2. Aplikacja powinna tworzyć wątki filozofów (co najmniej 5).
3. Aplikacja powinna symulować życie każdego filozofa (co najmniej cykle filofowanie–posiłek) poprzez wypisywanie odpowiednich komunikatów. Czas filozofowania i jedzenia powinien wynosić co najmniej 2–3 sekundy. Dobrze jeśli czas ten będzie lekko losowo (np. od 2.5 do 3.5 sekund, a nie od 1 do 5 sekund).
4. Na tym etapie można założyć, że każdy filozof ma własną parę sztućców. Można też wprowadzić współdzielenie sztućców, ale bez synchronizacji zasobów (efektem jednak będzie chaos/niespójność).
5. Poprawnego zamykania wątków (np. po pewnym czasie lub w reakcji na przycisk).

## Kompilacja
```
g++ -std=c++0x -pthread main.cpp Philosopher.hpp Philosopher.cpp
```

## Uruchmienie

```
./a.out

./a.out 4 (4 to liczba watkow/filozofow)
```

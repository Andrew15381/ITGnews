# Реализация необратимой хэш-функции на основе элементарных клеточных автоматов
Моя небольшая реализация одного из алгоритмов шифрования. В чём он заключается?

## Суть программы

- Алгоритм получает на вход символ для закодирования и правило элементарного клеточного клеточного автомата, реализованное в виде класса Rule (*см. конструкторы класса Field*).

- Внутри код полученного символа переводится в двоичную систему счисления и полученная вереница 1 и 0 передаётся элементарному клеточному автомату, далее просчитываем эволюцию и выводим на экран.

- В итоге алгоритм возвращает закодированный символ в той же кодировке.

Как описанно выше, программа достаточно проста для понимания и использования. Если русский язык вы позабыли со своим программированием, то милости прошу к коду)

**P.S.** *В связи с необратимостью элементарных клеточных автоматов зашифрованный символ обратно не расшифруешь(*

Да и по последним своим проверкам я заметил, что программа работает, но не так, как я этого хочу (не баг, а фича)

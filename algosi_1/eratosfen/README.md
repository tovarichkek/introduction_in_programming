# Запуск
Сначала нужно убедиться в том, что на системе установлены Google Test(https://github.com/google/googletest) и Google Benchmark(https://github.com/google/benchmark)

Далее пользуемся Cmake и, затем make
```bash
cmake -B build/
cd build
make

#запустить только алгоритм
./eratosfen

#прогон тестов
./testing_eratosfen

#бенчмаркинг с выводом в консоль + графиком:
./benchmarking_eratosfen --benchmark_out_format=console --benchmark_out=bench.txt
python3 ../benchmarking/parser_and_graph.py
#Теперь в директории build_folder лежит png файл - Benchmarking_graph.png
#Там же лежит bench.txt, в к-ом содержится информация по бенчмарк-тесту

#бенчмаркинг с выводом в консоль + выходной файл в формате {json|console|csv}:
./benchmarking_eratosfen --benchmark_out_format={json|console|csv} --benchmark_out=$YOURFILENAME$
python3 ../benchmarking/parser_and_graph.py
#Теперь в директории build_folder лежит $YOURFILENAME$ в указанном формате

```

# Сложность
Сложность по памяти - О(N)
Сложность по скорости - O(N * loglogN)

Доказательство того, что сложность по скорости не более O(N * logN):
Пусть мы зачеркиваем также числа и для составных в цикле, т.е. зачеркиваем все кратные 4, 6, 8, 9 и тд
Зачеркивая числа в массиве, мы проводим для чисел 2,3,4... N/2, N/3, N/4... операций + вычеркиваем само простое число(влияние на сложность можно не учитывать).
Итого N/2 + N/3 + N/4 + ... + N/N = N(1/2 + 1/3 + .. + 1/N) = N(logN - 1) = O(N * log N).
Не включая в расчёт кратные 4, 6, 8, 9 и тд числа, можно добиться более точной оценки - O(N * loglogN)


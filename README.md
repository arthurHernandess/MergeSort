# MergeSort
Implementação do algoritmo de ordenação mergesort em C. Este algoritmo é uma forma bem mais eficiente (O(nLogn)) de ordenar listas do que o clássico bubblesort
O mergesort utiliza a estratégia de divisão e conquista e é recursivo
=> 8 5 1 3 7 4 9 0   (inicio) 
=> 8 5 1 3 | 7 4 9 0 
=> 8 5 | 1 3 | 7 4 | 9 0 
=> 8 | 5 | 1 | 3 | 7 | 4 | 9 | 0 
=> 5 8 | 1 3 | 4 7 | 0 9 
=> 1 3 5 8 | 0 4 7 9 
=> 0 1 3 4 5 7 8 9   (fim)

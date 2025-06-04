/*
Применяются библиотеки OpenSSL и OpenCV. Разработать программу, которая загру-
жает пользовательское изображение, вычисляет его хэш-сумму по алгоритму SHA256,
производит изменение значение одного канала одного пикселя изображения, вычисляет
хэш-сумму по алгоритму SHA256, сравнивает две хэш-суммы. Хэш-суммы и результат
сравнения вывести в консоль, сохранить в txt-файл.
*/

#ifndef TASK3
#define TASK3

#include<string>
#include<vector>
std::string hash(const std::vector<unsigned char>& data);
long long load_and_compare(const std::string& path);

#endif
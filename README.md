# file-parser
Парсинг файла по разделителям в первой строке/Parsing the file by separators in the first line

Парсинг файлов в папке и сохранение результата в новый текстовый файл./Parsing the files in a folder and saving the result to a new text file.

Пример файла/ sample file:

example.txt\n

/\,. - разделители/separators

a/b/c\d,e - пример строки/example string 

Запуск программы:  $ FilesParse "Путь к папке" "Имя файла для записи" (Пример: > FilesParse TestDir test.txt)

Running the program: $ FilesParse "The path to the folder" "Filename for the record" (Example: > FilesParse TestDir test.txt)

Вывод программы/output:

example.txt

a

b

c

d

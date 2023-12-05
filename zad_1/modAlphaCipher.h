/**
* @file modAlphaCipher.h
* @author Крестина С.Д.
* @version 1.0
* @brief Заголовочный файл для модуля modAlphaCipher
*/
#pragma once
#include <vector>
#include <string>
#include <map>
#include <codecvt>
#include <locale>

/** @brief Класс для шифрования и расшифрования алгоритмом Гронсфельда
 * @details Ключ(вектор тип данных int)
 * Для шифрования - метод encrypt
 * для расшифровки - метод decrypt
 * @warnings Реализация только для русского языка!
 */
class modAlphaCipher
{
private:
	std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> codec; 
	std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Алфавит по порядку
 	std::map <wchar_t,int> alphaNum; ///< Ассоциативный массив "номер по символу"
	std::vector <int> key; ///< ключ
	/**
 	* @brief Преобразование из строки в вектор.
 	* @param [in] s Строка
 	* Исключения не возбуждаются
 	* @return Вектор, в котором хранятся индексы букв сообщения из алфавита 			"numAlpha"
 	*/
	std::vector<int> convert(const std::wstring& ws);
	/**
 	* @brief Преобразование из вектора в строку.
 	* @param [in] v Вектор данных
 	* Тип данных int
 	* Исключения не возбуждаются
 	* @return Строка текста типа "wstring"
 	*/
	std::wstring convert(const std::vector<int>& v);
public:
	/** @brief Запрет конструктора без параметров
	*/
	modAlphaCipher()=delete;
	/**
 	* @brief Конструктор класса
 	* @param [in] skey Ключ для шифрования
 	* @warning Ключ должен состоять из символов алфавита
 	* @throw std::invalid_argument, при неверном ключе
 	*/
	modAlphaCipher(const std::wstring& wskey); 
	/**
 	* @brief Функция Зашифрования
 	* @param [in] cipher_text Исходный текст
 	* @return Зашифрованная строка
 	*/
	std::wstring encrypt(const std::wstring& open_text);
	/**
	* @brief Функция расшифрования
 	* @param [in] cipher_text Зашифрованная фраза
 	* @return Расшифрованная(исходная) строка
 	*/
	std::wstring decrypt(const std::wstring& cipher_text);
};

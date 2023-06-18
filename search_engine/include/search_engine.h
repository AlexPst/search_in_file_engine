// search_engine.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include "ConverterJson.h"
#include "InvertedIndex.h"
// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.


ConverterJson* cj = new ConverterJson();
InvertedIndex* ii = new InvertedIndex();
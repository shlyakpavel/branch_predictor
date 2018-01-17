<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="ru_RU">
<context>
    <name>MainWindow</name>
    <message>
        <location filename="../mainwindow.ui" line="14"/>
        <source>Branch Predictor</source>
        <translation>Предсказатель переходов</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="21"/>
        <source>CPU instructions:</source>
        <translation>Инструкции CPU:</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="33"/>
        <source>Prediction here</source>
        <translation>Предсказание</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="40"/>
        <source>Current addr:</source>
        <translation>Текущий адрес:</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="57"/>
        <source>Next opr will jump(random): 0</source>
        <translation>Следуюущий условный переход не будет выполнен</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="68"/>
        <source>Mode</source>
        <translation>Режим</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="74"/>
        <source>&amp;Clever: always jump to lower adress</source>
        <translation>На основе &amp;анализа направления перехода</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="84"/>
        <source>&amp;Single-direction: always forward</source>
        <translation>ПВ – Переход &amp;всегда</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="91"/>
        <source>Single-&amp;direction: always jump</source>
        <translation>ПН – Переход &amp;никогда</translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="98"/>
        <source>A target address that is lower than its own address</source>
        <translation></translation>
    </message>
    <message>
        <location filename="../mainwindow.ui" line="108"/>
        <source>&amp;Step</source>
        <translation>&amp;Шаг</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="51"/>
        <source>yes</source>
        <translation>да</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="51"/>
        <source>no</source>
        <translation>нет</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="51"/>
        <source>Next jump operation will actually jump(random): </source>
        <translation>Следуюущий условный переход будет выполнен: </translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="59"/>
        <source>Always predict that a conditional jump will not be taken</source>
        <translation>Предполагается, что для любого исполнения УП перехода не будет и выборка производится следующей по порядку команды</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="67"/>
        <source>Always predict that a conditional jump will be taken</source>
        <translation>Предполагается, что каждая команда передачи управления обязательно завершится переходом и дальнейшая выборка происходит из точки перехода</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="75"/>
        <source>A more advanced form of static prediction presumes that backward branches will be taken and that forward branches will not. A backward branch is one that has a target address that is lower than its own address. This technique can help with prediction accuracy of loops, which are usually backward-pointing branches, and are taken more often than not taken</source>
        <translation>    Если инструкция перехода выполняет переход назад (на младшие адреса), в конвейер загружаются инструкции, расположенные по адресу перехода.
    Если инструкция перехода выполняет переход вперёд (на старшие адреса), в конвейер загружаются инструкции, расположенные после инструкции перехода</translation>
    </message>
    <message>
        <location filename="../mainwindow.cpp" line="80"/>
        <source>Prediction was: %1</source>
        <translation>Предсказание было: %1</translation>
    </message>
</context>
</TS>

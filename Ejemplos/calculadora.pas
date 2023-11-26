(*
Este programa actua como una calculadora sencilla de dos numeros
*)
program Calculadora(input, output);

    var opcion : integer;
    var num1, num2, resultado : real;

    (* Suma numeros *)
    function Suma(a: real; b: real) : real;
    begin
        Suma := a + b
    end;

    (* Resta numeros *)
    function Rest(a: real; b: real) : real;
    begin
        Rest := a - b
    end;

    (* Multiplica numeros *)
    function Mult(a: real; b: real) : real;
    begin
        Mult := a * b
    end;

    (* Divide numeros *)
    function Divi(a: real; b: real) : real;
    begin
        Divi := a / b
    end;

    function Pote(a: real; b: real) : real;
    var acum : real;
    var i: integer;
    begin
        acum := 1;
        for i := 1 to b do
            acum := acum * a;
        Pote := acum
    end;
 
    (* Lee la opcion *)
    procedure leerRespuesta;
    begin
        write("Elija su opcion deseada: ");
        read(opcion)
    end;

    (* Muestra el menu *)
    procedure menu;
    begin
        writeln("\n(1): Sumar");
        writeln("(2): Restar");
        writeln("(3): Multiplicar");
        writeln("(4): Dividir");
        writeln("(5): Potencia");
        writeln("(6): Salir")
    end;
    
    (* Captura los numeros*)
    procedure leerNumeros;
    begin
        write("Escriba el primer numero: ");
        read(num1);
        write("Escriba el segundo numero: ");
        read(num2)
    end;

    procedure realizaOperacion;
    begin
        leerNumeros;
        if opcion = 1 then
            resultado := Suma(num1, num2);
        if opcion = 2 then
            resultado := Rest(num1, num2);
        if opcion = 3 then
            resultado := Mult(num1, num2);
        if opcion = 4 then
            resultado := Divi(num1, num2);
        if opcion = 5 then
            resultado := Pote(num1, num2)
    end;

begin
    opcion := 1; (* Es necesario para que funcione en el while *)
    while opcion < 6 and opcion > 0 do
    begin
        menu;
        leerRespuesta;
        if opcion < 6 and opcion > 0 then
        begin
            realizaOperacion;
            writeln("Resultado: ", resultado)
        end
        else
            writeln("Saliendo del programa")
    end
end.
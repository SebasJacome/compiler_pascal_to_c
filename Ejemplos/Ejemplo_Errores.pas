(*
Este programa genera los 4 tipos de errores que detecta la Hash table:
* Variable redeclarada en el mismo scope
* Variable usada, pero no definida
* Variable declarada en un scope diferente
* Variable definida, pero no usada
*)
program principal(input, output);
    
    var a,b,c,d: INTEGER;
    (* Esta a da error, porque se redeclara *)
    var a: integer;
    var x : array[1..3] of real;
    var y : string;

    (* Suma numeros *)
    function Add(a: integer; b: integer) : integer;
    begin
        Add := a + b
    end;

    (* Resta numeros *)
    function Sus(a: integer; b: integer) : integer;
    var SinUso: integer;
    begin
        Sus := a - b
    end;

    (* Multiplica numeros *)
    function Mult(c: integer; a: integer) : integer;
    begin
        Mult := c * a
    end;

    (* Invoca a Multiplica y Suma numeros *)
    procedure multadd;
    begin
        c := Add(a, b);
        d := Mult(c, a)
    end;

    procedure sub;
    var prueba: real;
    begin
        prueba := 3.1416e9;
        x := Add(a, b);
        x := Sus(a, b)
    end;

begin
    a := 5;
    b := 3;
    (* Esta variable suelta warning, porque nunca se definio *)
    g := 8;
    (* Esta variable tambien, porque se definio en un scope diferente *)
    prueba := 1.9;
    multadd;
    while (a > b) do
      b := b + 1;
    for x := -3 to 5 do
      x := x - 1;
    writeln(c);
    writeln("Resultado final: ", d)
    (* Al final se imprimen warnings de variables sin usarse *)
end.

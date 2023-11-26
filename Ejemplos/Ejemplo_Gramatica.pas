(*
Este programa tiene como funcion demostrar lso diferentes casos que puede generar codigo.
No esta pensado para compilar y correr en C++
*)
program principal(input, output);

    var a,b,c,d: INTEGER;
    var leer, lectura : string;
    var x : array[1..3] of real;

    (*
    const a = -5;
    const b = 3.14e9;
    const c = "hola";
    *)

    (* Suma numeros *)
    function Add(a: integer; b: integer) : integer;
    begin
        Add := a + b
    end;

    (* Resta numeros *)
    function Sus(a: integer; b: integer; c: integer) : real;
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

    procedure useall;
    var prueba: real;
    begin
        prueba := 3.1416e9;
        x := Add(a, b);
        x := Sus(a, b)
    end;

begin
    a := 5;
    b := 3 + 4 - 5 * 6 / 7;
    multadd;
    while a > b do
      b := b + 1;
    for x := -3 to 5 do
      x := x - 1;
    if a <> b then
        begin
            useall;
            a := a+ 1
        end
    else
    begin
        multadd;
        useall
    end;
    if not (a and b) and (a or c or (not b or c)) then
    begin
        a := 1;
        b := 2
    end;
    read(leer);
    readln(lectura);
    writeln(leer);
    writeln(lectura);
    write(b);
    writeln(c);
    writeln("Resultado final: ", d);
    x[2+3] := 3;
    
    writeln("Resultado final: ", d);
    b := Add(2,5,6,5,4,3,3,4,4);
    c := Add(d,c,b,a);
    multadd(a,b,c,d);
    writeln("Resultado final: ", d + a + b * b / b - c * a - c + a);
    b := Add(-2,5,-6,5,-4,3,-3,4,-4);
    prueba := 3.1416;
    prueba := 3.1416e9;
    if not (a and b) and (a or c or (not b or c)) then
    begin
        a := 1;
        b := 2
    end
end.

(*
Este programa calcula c = a+b y entonces d = c * a
Tiene tres funciones
*)
program principal(input, output);
    
    var a,b,c,d: INTEGER;
    var x : array[1..3] of real;
    var y : string;

    (* Suma numeros *)
    function Add(a: integer; b: integer) : integer;
    begin
        Add := a + b
    end;

    (* Resta numeros *)
    function Sus(a: integer; b: integer) : integer;
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
    begin
        x := Add(a, b);
        x := Sus(a, b)
    end;

begin
    a := 5;
    b := 3;
    (* Esta variable suelta warnong, nunca se definio *)
    g := 8;
    multadd;
    while (a > b) do
      b := b + 1;
    for x := -3 to 5 do
      x := x - 1;
    writeln(c);
    writeln("Resultado final: ", d)
end.

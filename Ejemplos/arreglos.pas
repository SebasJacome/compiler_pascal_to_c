(*
Ejemplo de uso de algoritmos
*)
program exArrays(input, output);
    var n: array [1..11] of integer;   (* n es un arreglo de 9 enteros *)
    var i, j: integer;

begin
   (* inicializacion manual *)        
    for i := 1 to 10 do
       n[ i ] := i + 100;   (* da valores distintos a cada elemento *)
    
    (* imprime los valores *)
    for j:= 1 to 10 do
    begin
        write("Element[", j);
        writeln("] = ", n[j] )
        end
end.
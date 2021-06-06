
library IEEE;
use IEEE.STD_LOGIC_1164.all;

package DecimalToBinary is
	procedure dec_to_bin(decimal: in integer; num_of_bits: in integer; binary: out std_logic_vector);
end DecimalToBinary;

package body DecimalToBinary is
	procedure dec_to_bin(decimal: in integer; num_of_bits: in integer; binary: out std_logic_vector) is
		variable dec, bit_pos: integer;
	begin
		dec := decimal;
		bit_pos := 0;
		while(bit_pos < num_of_bits) loop
			if (dec rem 2) = 0 then
				binary(bit_pos) := '0';
			else
				binary(bit_pos) := '1';
			end if;
			dec := dec/2;
			bit_pos := bit_pos + 1;
		end loop;
	end procedure;
end DecimalToBinary;

#1/usr/bin

def generate_ddra_init():

    bit_modes = []
    
    for bit in range(8):

        while True:
            
            mode = input(f"Please enter Bit {bit} Mode (input/output): ").strip().lower()
            
            if mode in ["input", "output"]:
                bit_modes.append(mode)
                break
            
            else:
                print("Usage : Please enter <input> <output>.")

    ddra_value = 0
    for i, mode in enumerate(bit_modes):
        if mode == "output":
            ddra_value |= (1 << i)

    function_code = f"void DDRA_init(void) {{ DDRA = 0x{ddra_value:02X}; }}"
    
    print("\nGenerated DDRA_init function:\n")
    print(function_code)

generate_ddra_init()
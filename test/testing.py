import serial
import keyboard
import time  # Import de la bibliothèque pour gérer les délais

# Configuration du port série
port = "COM6"
baudrate = 115200

try:
    # Connexion au port série
    ser = serial.Serial(port, baudrate, timeout=1)
    print(f"Connecté à {port} avec un baudrate de {baudrate}. Appuyez sur une touche pour envoyer 'a'.")
    
    while True:
        # Attendre une touche
        if keyboard.press_and_release("space"):  # Appuyer sur "espace" pour envoyer 'a'
            ser.write(b'a')  # Envoyer le caractère 'a'
            print("Envoyé : 'a'")
            
            # Lire la réponse du port série
        response = ser.readline().decode('utf-8').strip()
        if response:
            print(f"Reçu : {response}") 
         
            
except serial.SerialException as e:
    print(f"Erreur de connexion au port série : {e}")
except KeyboardInterrupt:
    print("\nProgramme arrêté.")
finally:
    if 'ser' in locals() and ser.is_open:
        ser.close()
        print("Port série fermé.")
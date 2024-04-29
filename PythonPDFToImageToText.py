import os
from pdf2image import convert_from_path
import pytesseract
from PIL import Image

# Function to convert PDF to images
def pdf_to_img(pdf_file):
    return convert_from_path(pdf_file)

# Function to extract text from images
def ocr_core(images):
    text = ""
    for image in images:
        text += pytesseract.image_to_string(image)
    return text

# Specify your PDFs directory
pdfs_dir = 'path_to_your_pdfs'
output_dir = 'path_to_output_text_files'

# Check if output directory exists, if not create one
if not os.path.exists(output_dir):
    os.makedirs(output_dir)

# Loop through all PDFs in the directory
for pdf_file in os.listdir(pdfs_dir):
    if pdf_file.endswith('.pdf'):
        # Full path to your PDF
        pdf_path = os.path.join(pdfs_dir, pdf_file)
        # Convert PDF to images
        images = pdf_to_img(pdf_path)
        # OCR process on the images
        extracted_text = ocr_core(images)
        # Write the text to a file, named after the original PDF
        text_file_path = os.path.join(output_dir, pdf_file.replace('.pdf', '.txt'))
        with open(text_file_path, 'w', encoding='utf-8') as text_file:
            text_file.write(extracted_text)
        print(f"Processed {pdf_file}")

print("All PDFs have been processed.")

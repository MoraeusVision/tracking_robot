FROM dustynv/l4t-pytorch:r36.4.0

WORKDIR /workspace

COPY . .

RUN python3 -m pip install --upgrade pip

RUN pip3 install -v -e ./YOLOX --no-deps

RUN pip3 install loguru tqdm tabulate pycocotools --index-url https://pypi.org/simple

# optional:
# RUN pip3 install -r requirements.txt

CMD ["/bin/bash"]

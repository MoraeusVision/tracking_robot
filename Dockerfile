FROM dustynv/l4t-pytorch:r36.4.0

WORKDIR /workspace

COPY . .
RUN pip3 install -r requirements.txt -i https://pypi.org/simple

CMD ["/bin/bash"]

FROM dustynv/l4t-pytorch:r36.4.0

WORKDIR /workspace

COPY requirements.txt /tmp/requirements.txt
RUN pip3 install -r /tmp/requirements.txt -i https://pypi.org/simple

CMD ["/bin/bash"]

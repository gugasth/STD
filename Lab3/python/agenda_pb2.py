# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: agenda.proto
"""Generated protocol buffer code."""
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
from google.protobuf.internal import builder as _builder
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()


from google.protobuf import timestamp_pb2 as google_dot_protobuf_dot_timestamp__pb2


DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\x0c\x61genda.proto\x12\x06\x61genda\x1a\x1fgoogle/protobuf/timestamp.proto\"\x9e\x02\n\x06Pessoa\x12\n\n\x02id\x18\x01 \x01(\x05\x12\x0c\n\x04nome\x18\x02 \x01(\t\x12\r\n\x05\x65mail\x18\x03 \x01(\t\x12\x30\n\ttelefones\x18\x04 \x03(\x0b\x32\x1d.agenda.Pessoa.NumeroTelefone\x12\x30\n\x0clast_updated\x18\x05 \x01(\x0b\x32\x1a.google.protobuf.Timestamp\x1aK\n\x0eNumeroTelefone\x12\x0e\n\x06numero\x18\x01 \x01(\t\x12)\n\x04tipo\x18\x02 \x01(\x0e\x32\x1b.agenda.Pessoa.TipoTelefone\":\n\x0cTipoTelefone\x12\x0b\n\x07\x43\x45LULAR\x10\x00\x12\x0f\n\x0bRESIDENCIAL\x10\x01\x12\x0c\n\x08TRABALHO\x10\x02\"\x1d\n\x08Resposta\x12\x11\n\tresultado\x18\x01 \x01(\t2e\n\x06\x41genda\x12/\n\tadicionar\x12\x0e.agenda.Pessoa\x1a\x10.agenda.Resposta\"\x00\x12*\n\x06\x62uscar\x12\x0e.agenda.Pessoa\x1a\x0e.agenda.Pessoa\"\x00\x42\'\n\x15\x65ngtelecom.std.agendaB\x0c\x41gendaProtosP\x01\x62\x06proto3')

_globals = globals()
_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, _globals)
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'agenda_pb2', _globals)
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  DESCRIPTOR._serialized_options = b'\n\025engtelecom.std.agendaB\014AgendaProtosP\001'
  _globals['_PESSOA']._serialized_start=58
  _globals['_PESSOA']._serialized_end=344
  _globals['_PESSOA_NUMEROTELEFONE']._serialized_start=209
  _globals['_PESSOA_NUMEROTELEFONE']._serialized_end=284
  _globals['_PESSOA_TIPOTELEFONE']._serialized_start=286
  _globals['_PESSOA_TIPOTELEFONE']._serialized_end=344
  _globals['_RESPOSTA']._serialized_start=346
  _globals['_RESPOSTA']._serialized_end=375
  _globals['_AGENDA']._serialized_start=377
  _globals['_AGENDA']._serialized_end=478
# @@protoc_insertion_point(module_scope)
